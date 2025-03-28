#include "mock_algo.h"
#include <QThread>

int MockAlgo::SetAlgoEvalFilePath(const std::string& old_file_path, const std::string& new_file_path)
{
    this->old_file_path = old_file_path;
    this->new_file_path = new_file_path;
    return 0; // Success
}

int MockAlgo::GetAlgoEvalFilePath(std::string& old_file_path, std::string& new_file_path)
{
    old_file_path = this->old_file_path;
    new_file_path = this->new_file_path;
    return 0; // Success
}

int MockAlgo::StartEval()
{
    this->algo_eval_result.SetEvalFiles(this->old_file_path, this->new_file_path); // Set the evaluation files
    this->algo_eval_result.SetEvalStartTime(); // Set the evaluation start time

#if 1
    QThread::sleep(3); // Simulate the evaluation process with a sleep
    this->algo_eval_result.SetEvalOccupyMemory(1024); // Set the memory usage (example value)
    this->algo_eval_result.SetEvalOccupyCPU(50); // Set the CPU usage (example value)
    this->algo_eval_result.SetEvalFinished(); // Set the evaluation finished flag
#endif

    return 0; // Success
}

int MockAlgo::GetEvalResult(AlgoEvalResult &result)
{

    result = this->algo_eval_result; // Copy the result
    return 0; // Success
}