/*
    Generalized Algorithm Wrapper for C++
*/
#ifndef BASE_ALGO_WRAPPER_H
#define BASE_ALGO_WRAPPER_H

#include <string>
#include <chrono>
#include <mutex>
#include <cstdint>

class AlgoEvalResult
{
public:
    AlgoEvalResult() = default;
    ~AlgoEvalResult() = default;

    void Clear()
    {
        eval_old_file_path = "";
        eval_new_file_path = "";
        eval_old_file_md5 = "";
        eval_new_file_md5 = "";
        eval_duration = std::chrono::duration<double>(0);
        eval_start_time = 0;
        eval_finish_time = 0;
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
        if(eval_start_time == 0 || eval_finish_time == 0)
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

    
public:
    std::string eval_old_file_path;
    std::string eval_new_file_path;
    std::string eval_old_file_md5;
    std::string eval_new_file_md5;
    bool eval_finshed; // Evaluation finished flag

    std::time_t eval_start_time;
    std::time_t eval_finish_time;
    std::chrono::duration<double> eval_duration;

    uint64_t eval_occupy_memory; // Memory usage in bytes
    uint64_t eval_occupy_cpu; // CPU usage in percentage

private:
    std::mutex eval_mutex; // Mutex for thread safety
};

class BaseAlgoWrapper
{
private:
    std::string old_file_path;
    std::string new_file_path;
    AlgoEvalResult algo_eval_result;
public:
    BaseAlgoWrapper(/* args */) = default;
    virtual ~BaseAlgoWrapper() = default;

    virtual int SetAlgoEvalFilePath(const std::string& old_file_path, const std::string& new_file_path) = 0;
    virtual int GetAlgoEvalFilePath(std::string& old_file_path, std::string& new_file_path) = 0; // Get the evaluation file path
    virtual int StartEval() = 0; // Start the evaluation process
    virtual int GetEvalResult() = 0; // Get the evaluation result

}
#endif // BASE_ALGO_WRAPPER_H