#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> generateRandomVector(int size, int min_val, int max_val) {
    // Khởi tạo bộ sinh số ngẫu nhiên
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distrib(min_val, max_val);

    vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = distrib(gen);
    }
    return vec;
}

void display(vector<int> &arr){
    int n = arr.size();
    for (int &x : arr){
        cout << x << ' ';
    }
    cout << '\n';
}

void bubble(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n - 1; i ++){
        bool is_swapped = false;

        for (int j = 0; j < n - i - 1; j ++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped) break;
    }
}

void selection(vector<int> &arr){
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i ++){
        int min = i;
        for (int j = i + 1; j < n; j ++ ){
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void insertion(vector<int> &arr){
    int n = arr.size();

    for (int i = 1; i < n; i ++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
//          MERGE SORT
void merge(vector<int> &arr, int left, int mid, int right){
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    
    //merge
    while (i < L.size() && j < R.size()){
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void merge_sort(vector<int> &arr, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//          QUICK SORT
int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right]; // choose the last
    int i = left - 1;
    
    for (int j = left; j < right; j ++){
        if (arr[j] < pivot){
            i ++;
            swap(arr[i], arr[j]);
        }
        else continue;
    }
    swap(arr[i+1], arr[right]);

    return i + 1; // pivot index
}

void quick_sort(vector<int> &arr, int left, int right){
    if (left < right){
        int pIndex = partition(arr, left, right);

        quick_sort(arr, left, pIndex - 1); // left side
        quick_sort(arr, pIndex + 1, right); // right side
    }
}

int main(){
    vector<int> test1 = generateRandomVector(6, 1, 100);
    vector<int> test2 = generateRandomVector(6, 1, 100);
    vector<int> test3 = generateRandomVector(6, 1, 100);
    vector<int> test4 = generateRandomVector(6, 1, 100);
    vector<int> test5 = generateRandomVector(6, 1, 100);

    bubble(test1);
    selection(test2);
    insertion(test3);
    merge_sort(test4, 0, test4.size() - 1);
    quick_sort(test5, 0, test5.size() - 1);
    
    cout << "This is bubble sort: "; display(test1);
    cout << "This is selection sort: "; display(test2);
    cout << "This is insertion sort: "; display(test3);
    cout << "This is merge sort: "; display(test4);
    cout << "This is quick sort: "; display(test5);

    return 0;
}
