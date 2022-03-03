/* Week1.cpp 
@brief :Iterative Algorithms , Linear Search, Binary Search ,Matrix Multiplication
*/ 

#include <iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int Sum(vector<int>& A);
int Power1(int a, int n);
int Power2(int a, int n);
bool isPrime1(int n);
bool isPrime2(int n);
void MatrixMultiply(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C);
int LinearSearch(vector<int>& A, int key);
int BinarySearch(vector<int>& A, int key);

int main()
{
    
#if 0
    vector<int>A = { 3,9,6,5,2 };
    int result = Sum(A);
    printf("Sum of the numbers in A: %d\n", result);
#endif

#if 1
    printf("3^10: %d, 3^10: %d\n", Power1(3, 10), Power2(3, 10));
    printf("5^18: %d, 5^18: %d\n", Power1(5, 18), Power2(5, 18));
#endif

#if 0
    cout << "isPrime1(5)? " << isPrime1(5) << ", " << "isPrime2(5)? " << isPrime2(5) << endl;
    cout << "isPrime1(10002035)? " << isPrime1(10002035) << ", " << "isPrime2(10002035)? " << isPrime2(10002035) << endl;
    cout << "isPrime1(1299709)? " << isPrime1(1299709) << ", " << "isPrime2(1299709)? " << isPrime2(1299709) << endl;
#endif

#if 0
    vector<vector<int>> A = { {5, 1, 2}, {1, 2, 4}, {6, 2, 7} };
    vector<vector<int>> B = { {1, 2, 2}, {3, 1, 3}, {2, 1, 4} };
    vector<vector<int>> C(3, vector<int>(3));
    MatrixMultiply(A, B, C);
    for (uint32_t i = 0; i < C.size(); i++) {
        for (uint32_t j = 0; j < C[i].size(); j++) {
            printf("%2d, ", C[i][j]);
        } //end-for
        printf("\b\b \n");
    } //end-for
#endif

#if 0
    vector<int> A = { 9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 24, 20 };
    printf("Index of 20: %d\n", LinearSearch(A, 20));
    printf("Index of 57: %d\n", LinearSearch(A, 57));
#endif

#if 0
    vector<int> A = { 3, 8, 10, 11, 20, 50, 55, 60, 65, 70, 72, 90, 91, 94, 96, 99 };
    printf("Index of 55: %d\n", BinarySearch(A, 55));
    printf("Index of 57: %d\n", BinarySearch(A, 57));
#endif

    return 0;
}

//O(N) algorithm to compute the summation of N numbers
//Space Complexity ---> S(N)=N+2
int Sum(vector<int>& A) {
    int sum = 0; //local variable 1
    unsigned int i = 0; // locale variable 2
    while (i < A.size()) {//Vector size is N.(input size)
        sum += A[i];
        i++;
    }
    return sum;
}

//Compute a^n in O(N) time
// S(N) = 3 (variables --> pow, a and n)
int Power1(int a, int n) {
    int pow = 1; // 1 time executed
    while (n > 0) //Comparison --> n times executed
    {
        pow *= a; //math operation1 --> n times executed
        n--;     //math operation2 --> n times executed
    }
    return pow; // 1 time executed
} 

//Compute a^n in O(logN) time
int Power2(int a, int n) {
    int pow = 1; //3 4
    int currentPow = a;
    while (n > 0) {
        //The bitwize and operator is 
       //represented by a single &.
      //If you don't understand again 
     //after time has passed, go to this page -->//https://codeforwin.org/2016/01/c-program-to-check-lsb-of-number.html
        if (n & 0x1) // n%2 --> odd-->true || even-->false
            pow *= currentPow;
        currentPow *= currentPow;
        //x >>= 1 expression means 1) shift the value of x 
        // 1 bit right, 2) assign the new value to x and 3) 
        //return the new value of x as the value of the expression
        n >>= 1; //right shift || n=n/2^m m=1 in this code
             
    }
    return pow;
}

// O(n) Algorithm for primality check

bool isPrime1(int n) {

    if (n == 1) return false;
    if (n == 2) return true;

    int x = 2;
    while (x < n) {
        if (n % x == 0) return false;
        x++;
    }
    return true;
}

// O(√n) algorithm for primality check
bool isPrime2(int n) {
    if (n == 1) return false;
    if (n == 2) return true;

    int x = 2;
    while (x * x <= n) {
        if (n % x == 0) return false;
        x++;
    }
    return true;
}

// O(n^3) algorithm for matrix multiplication
void MatrixMultiply(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C)
{
    //32-bit unsigned integers
    for (uint32_t i = 0;i < C.size();i++) {
        for (uint32_t j = 0;j < C[i].size();j++) {
            C[i][j] = 0;
            for (uint32_t k = 0; k < A[i].size();k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
       
    }
}

//O(n) algorithm for forward linear search in an unsorted array
int LinearSearch(vector<int>& A, int key) {
    for (uint32_t i = 0;i < A.size();i++) {
        if (A[i] == key)
            return i;
    }
    return -1; //not found
}

// Olog(N) algorithm for binary search in a sorted array
/*
You shouldn't forget two things about binary search implementation: 
1) Data's must be in order.
2) Input must have random access in O(1) time.(we can access any element in our data structure in O(1) time)
*/
int BinarySearch(vector<int>& A, int key) {
    int left = 0;
    int right = (int)A.size()-1;
    int middle;

    while (left<=right)
    {
        middle = left + (right - left) / 2; /* 
         left + (right - left) / 2 = (left + right) / 2                             
         if we use "(left + right) / 2 " this happens then the value of left+right can go out of the 
         range of integer and that will result in an overflow.So we should choose other expression.*/
        if (A[middle] == key) return middle;
        else if (key < A[middle] == key) right = middle - 1;// Eliminate the right side
        else left = middle + 1;// Eliminate the left side
    }
    return -1;
}