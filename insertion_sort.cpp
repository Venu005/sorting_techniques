#include <functional>
#include <iostream>
#include <string>

void insertion_sort(int int_arr[], size_t length) {
    for (size_t index = 1; index < length; index++) {
        size_t j = index;

        while (j > 0 && int_arr[j - 1] > int_arr[j]) {
            size_t int_current = int_arr[j];

            int_arr[j] = int_arr[j - 1];
            int_arr[j - 1] = int_current;

            j--;
        }
    }
}

template <typename T>
T* get_array(size_t length, std::function<T()> fn) {
    T* arr = new T[length];
    for (size_t index = 0; index < length; index++) {
        arr[index] = fn();
    }
    return arr;
}

template <typename T>
T get_input(std::string prompt) {
    T input;
    std::cout << prompt << ": ";
    std::cin >> input;
    return input;
}

int get_random_in_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

template <typename T>
void print_array(std::string message, T arr[], size_t length) {
    std::cout << message << std::endl;
    std::cout << "[" << arr[0] << ", ";
    for (size_t index = 1; index < length - 1; index++) {
        std::cout << arr[index] << ", ";
    }
    std::cout << arr[length - 1] << "]" << std::endl;
}

void println(std::string message) {
    std::cout << message << std::endl;
}

bool is_arr_equal(int arr_1[], int arr_2[], size_t length) {
    for (size_t index = 0; index < length; index++) {
        if (arr_1[index] != arr_2[index]) {
            return false;
        }
    }
    return true;
}

void test_sort_function(
    std::function<void(int[], size_t)> sort_fn,
    int test_arr[],
    int expected_arr[],
    size_t length
) {
    sort_fn(test_arr, length);

    if (is_arr_equal(test_arr, expected_arr, length)) {
        println("Test Passed");
    } else {
        println("Test Failed");
        print_array<int>("Received", test_arr, length);
        print_array<int>("Expected", expected_arr, length);
    }
}

int main() {
    size_t length = get_input<size_t>("Enter the length of the array");
    int* int_arr = get_array<int>(length, []() { 
        return get_random_in_range(-500, 500); 
    });

    print_array<int>("Original", int_arr, length);
    insertion_sort(int_arr, length);
    print_array<int>("Sorted", int_arr, length);

    delete[] int_arr;

    int test_1_arr[] = { 1, 2, 3, 4, 5 };
    int arr_sorted[] = { 1, 2, 3, 4, 5 };    
    test_sort_function(insertion_sort, test_1_arr, arr_sorted, 5);

    int test_2_arr[] = { 5, 4, 3, 2, 1 };
    test_sort_function(insertion_sort, test_2_arr, arr_sorted, 5);

    int test_3_arr[] = { 1, 3, 2, 5, 4 };
    insertion_sort(test_3_arr, 5);
    test_sort_function(insertion_sort, test_3_arr, arr_sorted, 5);

    int test_4_arr[] = { 5, -1, 3, 2, 4, -3, -5, -6, 10, -20 };
    int test_4_arr_sorted[] = { -20, -6, -5, -3, -1, 2, 3, 4, 5, 10 };
    test_sort_function(insertion_sort, test_4_arr, test_4_arr_sorted, 10);

    return 0;
}