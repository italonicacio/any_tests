#include <chrono>
#include <iostream>

#include <array>
#include <vector>

int64_t MeasureTime(void (*function)(std::size_t), std::size_t iter_max) {

    auto t1 = std::chrono::high_resolution_clock::now();
    function(iter_max);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = t2 - t1;
    
    return duration/std::chrono::nanoseconds(1);
}

void sum_for(std::size_t iter_max) {
    float arr[3] = {1.0f, 2.0f, 3.0f};

    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            float sum = 0;
            for(int j = 0; j < 3; ++j)
            {
                sum += arr[j];
            }
        }
    }

}

void sum(std::size_t iter_max)
{
    float arr[3] = {1.0f, 2.0f, 3.0f};


    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
            float num = arr[0] + arr[1] + arr[2];
    }
}

void sum_for_array(std::size_t iter_max) {
    std::array<float, 3> arr = {1.0f, 2.0f, 3.0f};

    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            float sum = 0;
            for(int j = 0; j < 3; ++j)
            {
                sum += arr[j];
            }
        }
    }

}


void sum_array(std::size_t iter_max)
{
    std::array<float, 3> arr = {1.0f, 2.0f, 3.0f};

    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
            float num = arr[0] + arr[1] + arr[2];
    }
}

void sum_for_vector(std::size_t iter_max) {
    std::vector<float> arr = {1.0f, 2.0f, 3.0f};

    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            float sum = 0;
            for(int j = 0; j < 3; ++j)
            {
                sum += arr[j];
            }
        }
    }

}


void sum_vector(std::size_t iter_max)
{
    std::vector<float> arr = {1.0f, 2.0f, 3.0f};

    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
            float num = arr[0] + arr[1] + arr[2];
    }
}

int32_t main(int argc, char* argv[])
{
    int64_t time;
    std::size_t iterMax = std::stoi(argv[1]);

    time = MeasureTime(&sum, iterMax);
    std::cout << "Tempo do sum: " << time  << "\n";

    time = MeasureTime(&sum_array,iterMax);
    std::cout << "Tempo do sum_array: " << time << "\n";

    time = MeasureTime(&sum_vector, iterMax);
    std::cout << "Tempo do sum_vector: " << time << "\n";

    time = MeasureTime(&sum_for, iterMax);
    std::cout << "Tempo do sum_for: " << time << "\n";

    time = MeasureTime(&sum_for_array, iterMax);
    std::cout << "Tempo do sum_for_array: " << time << "\n";

    time = MeasureTime(&sum_for_vector, iterMax);
    std::cout << "Tempo do sum_for_vector: " << time << "\n";

 
    return 0;
}