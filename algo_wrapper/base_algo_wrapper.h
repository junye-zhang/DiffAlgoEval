/*
    Generalized Algorithm Wrapper for C++
*/
#ifndef BASE_ALGO_WRAPPER_H
#define BASE_ALGO_WRAPPER_H

#include <string>
#include <chrono>
#include <ctime>
#include <mutex>
#include <filesystem>
#include <cstdint>

#include <QCryptographicHash>
#include <QFile>
#include <QIODevice>
#include <QByteArrayView>
class AlgoEvalResult
{
public:
    AlgoEvalResult() = default;
    ~AlgoEvalResult() = default;

    AlgoEvalResult(const AlgoEvalResult& other)
        : eval_old_file_path(other.eval_old_file_path),
          eval_new_file_path(other.eval_new_file_path),
          eval_old_file_md5(other.eval_old_file_md5),
          eval_new_file_md5(other.eval_new_file_md5),
          eval_finshed(other.eval_finshed),
          eval_start_time(other.eval_start_time),
          eval_finish_time(other.eval_finish_time),
          eval_duration(other.eval_duration),
          eval_occupy_memory(other.eval_occupy_memory),
          eval_occupy_cpu(other.eval_occupy_cpu)
    {
    }
    AlgoEvalResult& operator=(const AlgoEvalResult& other)
    {
        if (this != &other) // Check for self-assignment
        {
            std::lock_guard<std::mutex> lock(eval_mutex);

            eval_old_file_path = other.eval_old_file_path;
            eval_new_file_path = other.eval_new_file_path;
            eval_old_file_md5 = other.eval_old_file_md5;
            eval_new_file_md5 = other.eval_new_file_md5;
            eval_finshed = other.eval_finshed;
            eval_start_time = other.eval_start_time;
            eval_finish_time = other.eval_finish_time;
            eval_duration = other.eval_duration;
            eval_occupy_memory = other.eval_occupy_memory;
            eval_occupy_cpu = other.eval_occupy_cpu;
        }
        return *this;
    }
    
    void Clear()
    {
        eval_old_file_path = "";
        eval_new_file_path = "";
        eval_old_file_md5 = "";
        eval_new_file_md5 = "";
        eval_duration = std::chrono::duration<double>(0);
        eval_start_time = std::chrono::system_clock::time_point();
        eval_finish_time = std::chrono::system_clock::time_point();
        eval_occupy_memory = 0;
        eval_occupy_cpu = 0;
    }

    int IsEvalFinished(bool& isFinished)
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        if(eval_old_file_path.empty() || eval_new_file_path.empty())
        {
            return -1; // File paths are not set
        }
        if(eval_start_time == std::chrono::system_clock::time_point() 
            || eval_finish_time == std::chrono::system_clock::time_point())
        {
            return -1; // Evaluation start or finish time is not set
        }
        if(eval_duration.count() <= 0)
        {
            return -1; // Evaluation duration is not valid
        }
        if(eval_occupy_memory == 0 || eval_occupy_cpu == 0)
        {
            return -1; // Memory or CPU usage is not set
        }
        isFinished = eval_finshed; // Set the evaluation finished flag
        return 0; // Success
    }

    int SetEvalFiles(const std::string& old_file_path, const std::string& new_file_path)
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        std::string old_file_md5, new_file_md5;

        if (isReadableFile(old_file_path) == false || isReadableFile(new_file_path) == false)
        {
            return -1; // File paths are not readable
        }
        
        if(calculateFileMD5(old_file_path, old_file_md5) != 0)
        {
            return -1; // Failed to calculate MD5 for old file
        }
        if(calculateFileMD5(new_file_path, new_file_md5) != 0)
        {
            return -1; // Failed to calculate MD5 for new file
        }
        eval_old_file_md5 = old_file_md5;
        eval_new_file_md5 = new_file_md5;
        eval_old_file_path = old_file_path;
        eval_new_file_path = new_file_path;
        return 0; // Success
    }
    int SetEvalFinished()
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        bool need_clear = false;
        if(eval_finshed)
        {
            return -1; // Evaluation already finished or not finished
        }
        do{
            if(eval_old_file_path.empty() || eval_new_file_path.empty())
            {
                need_clear = true;
                break;
            }
            if (eval_old_file_md5.empty() || eval_new_file_md5.empty())
            {
                need_clear = true;
                break;
            }
            if (eval_start_time == std::chrono::system_clock::time_point())
            {
                need_clear = true;
                break;
            }
            if (eval_finish_time != std::chrono::system_clock::time_point())
            {
                need_clear = true;
                break;
            }
            if (eval_duration.count() != 0)
            {
                need_clear = true;
                break;
            }
            if(eval_occupy_memory == 0 || eval_occupy_cpu == 0)
            {
                need_clear = true;
                break;
            }
        }while(0);
            
        if(need_clear)
        {
            Clear(); // Clear the evaluation result
            return -1; // Evaluation not finished
        }

        eval_finish_time = std::chrono::system_clock::now();; // Get the current time
        eval_duration = timeDifferenceMilliseconds(eval_start_time, eval_finish_time); // Calculate the duration
        eval_finshed = true; // Set the evaluation finished flag
        return 0; // Success
    }
    int SetEvalStartTime()
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        if(eval_start_time != std::chrono::system_clock::time_point())
        {
            return -1; // Evaluation already started
        }
        eval_duration = std::chrono::duration<double>(0);
        eval_finish_time = std::chrono::system_clock::time_point();
        eval_occupy_memory = 0;
        eval_occupy_cpu = 0;
        eval_start_time = std::chrono::system_clock::now(); // Get the current time

        return 0; // Success
    }
    int SetEvalOccupyMemory(uint64_t memory)
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        eval_occupy_memory = memory; // Set the memory usage
        return 0; // Success
    }
    int SetEvalOccupyCPU(uint64_t cpu)
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        eval_occupy_cpu = cpu; // Set the CPU usage
        return 0; // Success
    }
    
    int GetEvalResult(std::string& old_file_path, 
                        std::string& new_file_path, 
                        std::string& old_file_md5, 
                        std::string& new_file_md5, 
                        std::chrono::duration<double>& duration, 
                        uint64_t& memory, 
                        uint64_t& cpu)
    {
        std::lock_guard<std::mutex> lock(eval_mutex); // Lock the mutex for thread safety
        if(eval_finshed == false)
        {
            return -1; // Evaluation not finished
        }
        old_file_path = eval_old_file_path;
        new_file_path = eval_new_file_path;
        old_file_md5 = eval_old_file_md5;
        new_file_md5 = eval_new_file_md5;
        duration = eval_duration;
        memory = eval_occupy_memory;
        cpu = eval_occupy_cpu;
        return 0; // Success
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
    int calculateFileMD5(const std::string &filePath, std::string &md5Hash)
    {
        if (filePath.empty())
        {
            return -1; // Invalid file path
        }

        if (!isReadableFile(filePath))
        {
            return -1; // File is not readable
        }

        QFile file(QString::fromStdString(filePath));
        if (!file.open(QIODevice::ReadOnly))
        {
            return -1; // Failed to open the file
        }

        QCryptographicHash md5(QCryptographicHash::Md5);
        char buffer[1024]; // read 1KB at a time
        int bytesRead;

        while ((bytesRead = file.read(buffer, sizeof(buffer))) > 0)
        {
            md5.addData(QByteArrayView(buffer, bytesRead));
        }

        file.close();
        md5Hash = md5.result().toHex().toStdString(); // Convert to string
        return 0;
    }
    std::chrono::duration<double> timeDifferenceMilliseconds(std::chrono::system_clock::time_point &pre_time, 
                                        std::chrono::system_clock::time_point &post_time) {
        auto diff = post_time - pre_time;
        return std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    }
public:
    std::string eval_old_file_path;
    std::string eval_new_file_path;
    std::string eval_old_file_md5;
    std::string eval_new_file_md5;
    bool eval_finshed; // Evaluation finished flag

    std::chrono::system_clock::time_point eval_start_time;
    std::chrono::system_clock::time_point eval_finish_time;
    std::chrono::duration<double> eval_duration;

    uint64_t eval_occupy_memory; // Memory usage in bytes
    uint64_t eval_occupy_cpu; // CPU usage in percentage

private:
    std::mutex eval_mutex; // Mutex for thread safety
};

class BaseAlgoWrapper
{
protected:
    std::string old_file_path;
    std::string new_file_path;
    AlgoEvalResult algo_eval_result;
public:
    BaseAlgoWrapper(/* args */) = default;
    virtual ~BaseAlgoWrapper() = default;

    virtual int SetAlgoEvalFilePath(const std::string& old_file_path, const std::string& new_file_path) = 0;
    virtual int GetAlgoEvalFilePath(std::string& old_file_path, std::string& new_file_path) = 0; // Get the evaluation file path
    virtual int StartEval() = 0; // Start the evaluation process
    virtual int GetEvalResult(AlgoEvalResult &result) = 0; // Get the evaluation result

};
#endif // BASE_ALGO_WRAPPER_H
