#include <chrono>
#include <iostream>

#include <array>

int64_t MeasureTime(void (*function)(std::size_t), std::size_t iter_max) {

    auto t1 = std::chrono::high_resolution_clock::now();
    function(iter_max);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = t2 - t1;
    
    return duration/std::chrono::nanoseconds(1);
}


void multi_array_f32(std::size_t iter_max)
{
    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            std::array<float, 3> arr = {1.0f, 2.0f, 3.0f};
            std::array<float, 3> arr2 = {2.0f, 2.0f, 2.0f};
            arr[0] *= arr2[0];
            arr[1] *= arr2[1];
            arr[2] *= arr2[2];

        }
    }
}

void multi_array_f64(std::size_t iter_max)
{
    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            std::array<double, 3> arr = {1.0, 2.0, 3.0};
            std::array<double, 3> arr2 = {2.0, 2.0, 2.0};
            arr[0] *= arr2[0];
            arr[1] *= arr2[1];
            arr[2] *= arr2[2];
        }
    }
}

void multi_for_array_f32(std::size_t iter_max) {


    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            std::array<float, 3> arr = {1.0f, 2.0f, 3.0f};
            std::array<float, 3> arr2 = {2.0f, 2.0f, 2.0f};

            for(int k = 0; k < 3; ++k)
            {
                arr[k] *= arr2[k];
            }
        }
    }

}



void multi_for_array_f64(std::size_t iter_max) {

    for(std::size_t i = 0; i < iter_max; ++i )
    {
        
        for(std::size_t j = 0; j < iter_max; j++)
        {
            std::array<double, 3> arr = {1.0, 2.0, 3.0};
            std::array<double, 3> arr2 = {2.0, 2.0, 2.0};

            for(int k = 0; k < 3; ++k)
            {
                arr[k] *= arr2[k];
            }
        }
    }

}

void multi_for_array_f32_without(std::size_t iter_max) {


    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            std::array<float, 3> arr = {1.0f, 2.0f, 3.0f};
            std::array<float, 3> arr2 = {2.0f, 2.0f, 2.0f};
            for(int k = 0; k < 3; ++k)
            {
                arr[k] = arr[k] * arr2[k];
            }
        }
    }
}

void multi_for_array_f64_without(std::size_t iter_max) {

    for(std::size_t i = 0; i < iter_max; ++i )
    {
        
        for(std::size_t j = 0; j < iter_max; j++)
        {
            std::array<double, 3> arr = {1.0, 2.0, 3.0};
            std::array<double, 3> arr2 = {2.0, 2.0, 2.0};
            for(int k = 0; k < 3; ++k)
            {
                arr[k] = arr[k] * arr2[k];
            }
        }
    }

}

void calculus_f32() {
    std::array<float, 3> arr = {1.0f, 2.0f, 3.0f};
    std::array<float, 3> arr2 = {2.0f, 2.0f, 2.0f};
    std::transform(arr.begin(), arr.end(), arr2.begin(), arr.begin(), std::multiplies<float>());
}

void caculus_f64() {
    std::array<double, 3> arr = {1.0, 2.0, 3.0};
    std::array<double, 3> arr2 = {2.0, 2.0, 2.0};
    std::transform(arr.begin(), arr.end(), arr2.begin(), arr.begin(), std::multiplies<double>());
}

void multi_transform_array_f32(std::size_t iter_max) {

    for(int i = 0; i < iter_max; ++i )
    {
        for(int j = 0; j < iter_max; j++)
        {
            calculus_f32();
        }
    }
}

void multi_transform_array_f64(std::size_t iter_max) {

    for(std::size_t i = 0; i < iter_max; ++i )
    {
        for(std::size_t j = 0; j < iter_max; j++)
        {
            caculus_f64();
        }
    }
}


int32_t main(int argc, char* argv[])
{
    int64_t time;
    std::size_t iterMax = std::stoi(argv[1]);

    time = MeasureTime(&multi_array_f32, iterMax);
    std::cout << "Tempo do multi f32: " << time  << "\n";

    time = MeasureTime(&multi_array_f64,iterMax);
    std::cout << "Tempo do multi f64: " << time << "\n";

    time = MeasureTime(&multi_for_array_f32, iterMax);
    std::cout << "Tempo do multi for f32: " << time << "\n";

    time = MeasureTime(&multi_for_array_f64, iterMax);
    std::cout << "Tempo do multi for f64: " << time << "\n";

    time = MeasureTime(&multi_for_array_f32_without, iterMax);
    std::cout << "Tempo do multi for f32 without: " << time << "\n";

    time = MeasureTime(&multi_for_array_f64_without, iterMax);
    std::cout << "Tempo do multi for f64 without: " << time << "\n";

        time = MeasureTime(&multi_transform_array_f32, iterMax);
    std::cout << "Tempo do multi transform f32: " << time << "\n";

    time = MeasureTime(&multi_transform_array_f64, iterMax);
    std::cout << "Tempo do multi transform f64: " << time << "\n";

    return 0;
}