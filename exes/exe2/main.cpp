#include <iostream>
/*
#include <stdlib>

void swap(int arr[], int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

// bubble sort : O(n2)
// n = arr.length
void bubbleSort(int arr[], int n)
{
    bool swapped = true;
    int j = 0;
    
    while(swapped)
    {
        swapped = false;
        j++;
        for(int i = 0; i<n-j; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr, i, i+1);
                swapped = true;
            }
        }
    }
}

// selection sort : O(n2)
// MAX = arr.length
void selectionSort(int arr[], int MAX)
{
    int i, j, min;
    
    for(i = 0; i < MAX-1; i++)
    {
        min = i;
        for(j = i+1; j < MAX; j++)
        {
            if(arr[j] < arr[min]) min = j;
        }
        
        swap(arr, i, min);
    }
}

// merge sort : O(n log n)
void merge(int array[], int low, int middle, int high)
{
    int helper[] = new int[array.length];
    
    for(int i=low; i<=high; i++)
    {
        helper[i] = array[i];
    }
    
    int helperLeft = low;
    int helperRight = middle + 1;
    int current = low;
    
    while(helperLeft<=middle && helperRight<=high)
    {
        if(helper[helperLeft]<=helper[helperRight])
        {
            array[current] = helper[helperLeft];
            helperLeft++;
        }
        else
        {
            array[current] = helper[helperRight];
            helperRight++;
        }
        current++;
        
    }
    
    int remaining = middle - helperLeft;
    for(int i=0; i<=remaining; i++)
    {
        array[current+ i] = helper[helperLeft+i];
    }
}

void mergesort(int array[], int low, int high)
{
    if(low < high)
    {
        int middle = (low+high)/2;
        mergesort(array, low, middle);
        mergesort(array, middle+1, high);
        merge(array, low, middle, high);
    }
}

// quick sort : O(n log n), O(n2), O(log n)
int partition(int arr[], int left, int right)
{
    int pivot = arr[(left+right)/2];
    
    while(left<=right)
    {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        
        if(left<=right)
        {
            swap(arr, left, right);
            left++;
            right--;
        }
    }
    
    return left;
}

void quickSort(int arr[], int left, int right)
{
    int index = partition(arr, left, right);
    if(left < index -1)
    {
        quickSort(arr, left, index - 1);
    }
    
    if(index < right)
    {
        quickSort(arr, index, right);
    }
}

// radix sort : O(kn)
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for(int i = 1; i <n; i++)
        if(arr[i] > mx)
            mx = arr[i];
    
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    
    for(i = 0; i < n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    
    for(i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    
    for(i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    
    for(int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

// binarySearch
int binarySearch(int a[], int x)
{
    int low = 0;
    int high = a.length - 1;
    int mid;
    
    while(low <= high)
    {
        mid = (low+high)/2;
        if(a[mid] < x)
        {
            low = mid + 1;
        }
        else if(a[mid] > x){
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    
    return -1; // error
}

int binarySearchRecursive(int a[], int x, int low, int high)
{
    if(low>high) return -1; // error
    
    int mid = (low+high)/2;
    if(a[mid] < x)
    {
        return binarySearchRecursive(a, x, mid+1, high);
    }
    else if (a[mid] > x)
    {
        return binarySearchRecursive(a, x, low, mid - 1);
    }
    else
    {
        return mid;
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    
}
*/

int main(int argc, char *argv[])
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //print(arr, n);
    //adixSort(arr, n);
    //print(arr, n);
   
    return 0;
}
