#ifndef MOCK_ALGO_H
#define MOCK_ALGO_H
#include "base_algo_wrapper.h"

class MockAlgo : public BaseAlgoWrapper
{
public:
    MockAlgo() = default;
    ~MockAlgo() override = default;

    int SetAlgoEvalFilePath(const std::string& old_file_path, const std::string& new_file_path) override;
    int GetAlgoEvalFilePath(std::string& old_file_path, std::string& new_file_path) override;
    int StartEval() override;
    int GetEvalResult(AlgoEvalResult &result) override;
};

#endif // MOCK_ALGO_H