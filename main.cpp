#include <QApplication>
#include <QIcon>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>

#include <map>
#include <vector>
#include <array>
#include <string>
#include <mutex>
#include <filesystem>
#include <stdexcept>
#include <cstdint>
#include "DiffAlgoEval.h"
#include "mock_algo.h"
class AlgoSelect 
{
public:
    AlgoSelect()
    {
        algo_select[0]["bsdiff"] = false;
        algo_select[1]["courgette"] = false;
        algo_select[2]["hdiffpatch"] = false;
        algo_select[3]["vcdiff"] = false;
        algo_select[4]["xdelta3"] = false;
        algo_select_fin = false;
    }
    ~AlgoSelect() = default;

    void Reset()
    {
        std::lock_guard<std::mutex> lock(algo_select_mutex); // Lock the mutex for thread safety
        // Reset the selection state of all algorithms to false
        for (auto& algo : algo_select) {
            for (auto& pair : algo) {
                pair.second = false;
            }
        }
        algo_select_fin = false; // Reset the finalized state
    }

    int SetAlgoSelect(const std::string& algo_name, bool algo_select_state)
    {
        std::lock_guard<std::mutex> lock(algo_select_mutex); // Lock the mutex for thread safety
        bool found = false;

        if (algo_select_fin) {
            return -1; // Cannot set selection after finalization
        }
        if (algo_name.empty()) {
            return -1; // Invalid algorithm name
        }
        // Set the selection state of the specified algorithm
        for (auto& algo : algo_select) {
            if (algo.find(algo_name) != algo.end()) {
                algo[algo_name] = algo_select_state; // Set the algorithm as selected or deselected
                found = true;
                break;
            }
        }
        
        if (!found) {
            return -1; // Algorithm not found
        }else {
            return 0; // Success
        }
    }
    
    int GetAlgoSelect(const std::string& algo_name, bool& algo_select_state)
    {
        std::lock_guard<std::mutex> lock(algo_select_mutex); // Lock the mutex for thread safety

        if (algo_name.empty()) {
            return -1; // Invalid algorithm name
        }
        // Get the selection state of the specified algorithm
        for (const auto& algo : algo_select) {
            if (algo.find(algo_name) != algo.end()) {
                algo_select_state = algo.at(algo_name);
                return 0; // Success
            }
        }
        return -1; // Algorithm not found
    }

    bool IsAlgoSelectFin() const
    {
        return algo_select_fin;
    }

    int SetAlgoSelectFin(void)
    {
        std::lock_guard<std::mutex> lock(algo_select_mutex); // Lock the mutex for thread safety
        if (algo_select_fin) {
            return 0; // Already finalized
        }
        bool allFalse = true;
        for (const auto& algo : algo_select) {
            for (const auto& pair : algo) {
                if (pair.second) {
                    allFalse = false;
                    break;
                }
            }
            if (!allFalse) {
                break;
            }
        }

        if (allFalse) {
            return -1;
        }else {
            algo_select_fin = true;
            return 0; // Finalization successful
        } 
    }

private:
    static constexpr uint32_t algo_nums = 5; // Number of algorithms
    std::array<std::map<std::string, bool>, algo_nums> algo_select; // Array to store the selection state of each algorithm
    bool algo_select_fin = false; // Flag to indicate if the selection is finalized
    std::mutex algo_select_mutex; // Mutex for thread safety
};

class FileSelect 
{
public:
    FileSelect()
    {
        old_file_path = "";
        new_file_path = "";
        file_select_fin = false;
    }
    ~FileSelect() = default;

    void Reset()
    {
        std::lock_guard<std::mutex> lock(file_select_mutex); // Lock the mutex for thread safety
        old_file_path = "";
        new_file_path = "";
        file_select_fin = false; // Reset the finalized state
    }

    int SetOldFileSelect(std::string& file_path)
    {
        std::lock_guard<std::mutex> lock(file_select_mutex); // Lock the mutex for thread safety

        if (file_path.empty()) {
            return -1; // Invalid file paths
        }

        if (!isReadableFile(file_path)) {
            return -1; // File is not readable
        }

        // Set the file paths
        old_file_path = file_path;
        return 0; // Success
    }
    
    int SetNewFileSelect(std::string& file_path)
    {
        std::lock_guard<std::mutex> lock(file_select_mutex); // Lock the mutex for thread safety

        if (file_path.empty()) {
            return -1; // Invalid file paths
        }

        if (!isReadableFile(file_path)) {
            return -1; // File is not readable
        }

        // Set the file paths
        new_file_path = file_path;
        return 0; // Success
    }

    int GetFileSelect(std::string &old_path, std::string &new_path)
    {
        std::lock_guard<std::mutex> lock(file_select_mutex); // Lock the mutex for thread safety
        if(!file_select_fin) {
            return -1; // Cannot get selection after finalization
        }
        old_path = old_file_path; 
        new_path = new_file_path;
        return 0;
    }

    bool IsFileSelectFin() const
    {
        return file_select_fin;
    }

    int SetFileSelectFin(void)
    {
        std::lock_guard<std::mutex> lock(file_select_mutex); // Lock the mutex for thread safety
        if (file_select_fin) {
            return 0; // Already finalized
        }

        if (old_file_path.empty() || new_file_path.empty()) {
            return -1;
        }else {
            file_select_fin = true;
            return 0; // Finalization successful
        } 
    }
private:
    bool isReadableFile(const std::string& filePath) {
        std::filesystem::path path(filePath);
        if(!std::filesystem::is_regular_file(path)){
            return false; // File does not exist or is not a regular file
        }

        if((std::filesystem::status(path).permissions() & std::filesystem::perms::owner_read) == std::filesystem::perms::none){
            return false; // File is not readable
        }

        return true; // File is readable
    }
private:
    std::string old_file_path;
    std::string new_file_path;
    bool file_select_fin = false; // Flag to indicate if the selection is finalized
    std::mutex file_select_mutex; // Mutex for thread safety
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        ui.setupUi(this);

        ui.lineEdit_oldfile->setReadOnly(true);
        ui.lineEdit_newfile->setReadOnly(true);
        // Connect the pushButton click signal to the slot function
        connect(ui.pushButton_algocfm, &QPushButton::clicked, this, &MainWindow::onPushButtonAlgoConfirmClicked);
        connect(ui.pushButton_algoresel, &QPushButton::clicked, this, &MainWindow::onPushButtonAlgoReselectClicked);
        connect(ui.pushButton_oldfile, &QPushButton::clicked, this, &MainWindow::onPushButtonOldFileSelectClicked);
        connect(ui.pushButton_newfile, &QPushButton::clicked, this, &MainWindow::onPushButtonNewFileSelectClicked);
        connect(ui.pushButton_filecfm, &QPushButton::clicked, this, &MainWindow::onPushButtonFileConfirmClicked);
        connect(ui.pushButton_fileresel, &QPushButton::clicked, this, &MainWindow::onPushButtonFileReselectClicked);
        connect(ui.pushButton_starteval, &QPushButton::clicked, this, &MainWindow::onPushButtonStartEvalClicked);
    }

private slots:
    void onPushButtonAlgoConfirmClicked()
    {
        // Get the state of the checkboxes
        bool isChecked_bsdiff = ui.checkBox_bsdiff->isChecked();
        bool isChecked_courgette = ui.checkBox_courgette->isChecked();
        bool isChecked_hdiffpatch = ui.checkBox_hdiffpatch->isChecked();
        bool isChecked_vcdiff = ui.checkBox_vcdiff->isChecked();
        bool isChecked_xdelta3 = ui.checkBox_xdelta3->isChecked();

        if(isChecked_bsdiff == false 
            && isChecked_courgette == false 
            && isChecked_hdiffpatch == false 
            && isChecked_vcdiff == false 
            && isChecked_xdelta3 == false)
        {
            algo_sel.Reset(); // Reset the algorithm selection
            QMessageBox::warning(this, "Warning", "Please select at least one checkbox.");
            return;
        }

        if(algo_sel.SetAlgoSelect("bsdiff", isChecked_bsdiff) != 0
            || algo_sel.SetAlgoSelect("courgette", isChecked_courgette) != 0
            || algo_sel.SetAlgoSelect("hdiffpatch", isChecked_hdiffpatch) != 0
            || algo_sel.SetAlgoSelect("vcdiff", isChecked_vcdiff) != 0
            || algo_sel.SetAlgoSelect("xdelta3", isChecked_xdelta3) != 0
            || algo_sel.SetAlgoSelectFin() != 0)
        {
            QMessageBox::warning(this, "Warning", "Failed to set algorithm selection.");
            return;
        }

        // Disable the pushButton and checkboxes
        ui.pushButton_algocfm->setEnabled(false);
        ui.checkBox_bsdiff->setEnabled(false);
        ui.checkBox_courgette->setEnabled(false);
        ui.checkBox_hdiffpatch->setEnabled(false);
        ui.checkBox_vcdiff->setEnabled(false);
        ui.checkBox_xdelta3->setEnabled(false);
    }

    void onPushButtonAlgoReselectClicked()
    {
        ui.checkBox_bsdiff->setChecked(false);
        ui.checkBox_courgette->setChecked(false);
        ui.checkBox_hdiffpatch->setChecked(false);
        ui.checkBox_vcdiff->setChecked(false);
        ui.checkBox_xdelta3->setChecked(false);
        // Enable the pushButton and checkboxes
        ui.pushButton_algocfm->setEnabled(true);
        ui.checkBox_bsdiff->setEnabled(true);
        ui.checkBox_courgette->setEnabled(true);
        ui.checkBox_hdiffpatch->setEnabled(true);
        ui.checkBox_vcdiff->setEnabled(true);
        ui.checkBox_xdelta3->setEnabled(true);

        ui.lineEdit_oldfile->setText("");
        ui.lineEdit_newfile->setText("");
        ui.pushButton_filecfm->setEnabled(true);
        algo_sel.Reset(); // Reset the algorithm selection
        file_sel.Reset(); // Reset the file selection
    }

    void onPushButtonOldFileSelectClicked()
    {
        if(algo_sel.IsAlgoSelectFin() == false)
        {
            QMessageBox::warning(this, "Warning", "Please confirm the algorithm selection first.");
            return;
        }
        QString filePath = QFileDialog::getOpenFileName(this, "Select File", "", "All files (*.*)");
        if (!filePath.isEmpty()) 
        {
            ui.lineEdit_oldfile->setText(filePath);
        }
    }

    void onPushButtonNewFileSelectClicked()
    {
        if(algo_sel.IsAlgoSelectFin() == false)
        {
            QMessageBox::warning(this, "Warning", "Please confirm the algorithm selection first.");
            return;
        }
        QString filePath = QFileDialog::getOpenFileName(this, "Select File", "", "All files (*.*)");
        if (!filePath.isEmpty()) 
        {
            ui.lineEdit_newfile->setText(filePath);
        }
    }

    void onPushButtonFileConfirmClicked()
    {
        auto oldfile = ui.lineEdit_oldfile->text().toStdString();
        auto newfile = ui.lineEdit_newfile->text().toStdString();
        if(oldfile.empty() || newfile.empty())
        {
            file_sel.Reset(); // Reset the file selection
            QMessageBox::warning(this, "Warning", "Please select old and new files.");
            return;
        }
        file_sel.SetOldFileSelect(oldfile);
        file_sel.SetNewFileSelect(newfile);
        if(file_sel.SetFileSelectFin() != 0)
        {
            QMessageBox::warning(this, "Warning", "Failed to set file selection.");
            return;
        }
        ui.pushButton_filecfm->setEnabled(false);
    }

    void onPushButtonFileReselectClicked()
    {
        ui.lineEdit_oldfile->setText("");
        ui.lineEdit_newfile->setText("");
        ui.pushButton_filecfm->setEnabled(true);
        file_sel.Reset(); // Reset the file selection
    }

    void onPushButtonStartEvalClicked()
    {
        if(algo_sel.IsAlgoSelectFin() == false)
        {
            QMessageBox::warning(this, "Warning", "Please confirm the algorithm selection first.");
            return;
        }
        if(file_sel.IsFileSelectFin() == false)
        {
            QMessageBox::warning(this, "Warning", "Please confirm the file selection first.");
            return;
        }
        
        // Start the evaluation process here
        std::string old_file_path, new_file_path;
        std::string old_file_md5;
        std::string new_file_md5;
        std::chrono::duration<double> duration;
        uint64_t memory;
        uint64_t cpu;
        MockAlgo mockAlgo;
        AlgoEvalResult result;

        if(file_sel.GetFileSelect(old_file_path, new_file_path) != 0)
        {
            QMessageBox::warning(this, "Warning", "Failed to get file selection.");
            return;
        }
        mockAlgo.SetAlgoEvalFilePath(old_file_path, new_file_path);
        mockAlgo.StartEval();
        if(mockAlgo.GetEvalResult(result) != 0)
        {
            QMessageBox::warning(this, "Warning", "Failed to get evaluation result.");
            return;
        }
        
        result.GetEvalResult(old_file_path, new_file_path, old_file_md5, new_file_md5, duration, memory, cpu);
        // Display the evaluation result in a message box or any other UI element
        QString resultMessage = QString("Algorithm: %1\nOld File: %2\nNew File: %3\nMD5: %4\nMD5: %5\nDuration: %6 seconds\nMemory: %7 bytes\nCPU: %8%")
            .arg("MockAlgo") // Replace with the actual algorithm name
            .arg(QString::fromStdString(old_file_path))
            .arg(QString::fromStdString(new_file_path))
            .arg(QString::fromStdString(old_file_md5))
            .arg(QString::fromStdString(new_file_md5))
            .arg(duration.count())
            .arg(memory)
            .arg(cpu);
        // Show the result message in a message box
        QMessageBox::information(this, "Evaluation Result", resultMessage);
    }
private:
    Ui::MainWindow ui;
    AlgoSelect algo_sel;
    FileSelect file_sel;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("DiffAlgoEval");
    mainWindow.setStyleSheet("background-color: #f0f0f0;"); // Set a light background color
    mainWindow.setAttribute(Qt::WA_DeleteOnClose); // Ensure the window is deleted when closed
    mainWindow.show();

    return app.exec();
}

// Include the moc file generated by the Qt Meta-Object Compiler
#include "main.moc"