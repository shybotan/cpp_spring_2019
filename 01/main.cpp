#include "numbers.dat"
#include <iostream>
#include <vector>

// Data - массив
// Size - размер массива

void allarrfill(std::vector<bool>& arr)
{ 
    // 1 - simple; 0- not simple;
    arr[0] = arr[1] = false;
    for (int i = 2; i * i < Size; ++i)  
        if (arr[i])
            for (int k = i+i; k <= Size; k += i)
                arr[k] = false;
}

int main(int argc, char* argv[])
{   
    if (argc % 2 == 0 || argc == 1) return -1;      //проверка четности аргументов
    std::vector<bool> simple_digits_arr;
    simple_digits_arr.resize(Size, true);           //создадим массив, где простому индексу соотвествует 1 , иначе 0
    allarrfill(simple_digits_arr);                  //заполняем  

    for (int i = 1; i < argc - 1; i += 2)
    {
        int left = atoi(argv[i]);
        int right = atoi(argv[i + 1]);
        if (left > right) 
        {
            std::cout << 0 << std::endl;
            return 0;
        }
        int flag = 0;
        int count = 0;                              // счетчик простых чисел
        for (int j = 0; j < Size; ++j)
        {
            if (Data[j] == left && flag == 0) flag = 1;
            if (Data[j] == right && flag == 1)
            {
                count += static_cast<int>(simple_digits_arr[Data[j]]);
                ++flag;
                std::cout << count << std::endl;
                break;
            }
            if (flag == 1) count += static_cast<int>(simple_digits_arr[Data[j]]);
        }
        if (flag != 2)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    return 0;
}
