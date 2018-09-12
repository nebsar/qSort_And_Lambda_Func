/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 11, 2018, 3:22 PM
 */

#include <iostream>
#include <random>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//using namespace std;

int compareFunction(const void* a, const void* b) {
    int A = *(static_cast<const int*> (a));
    int B = *(static_cast<const int*> (b));
    return B - A;
}

struct Compare {
public:

    int operator()(const void* a, const void* b) const {
        int A = *(static_cast<const int*> (a));
        int B = *(static_cast<const int*> (b));
        return B - A;
    }
};

int main(int argc, char** argv) {

    srand(time(0));

    int array[100] = {};

    for (int i = 0; i < 100; i++) {
        array[i] = (rand() % 101);
    }

    auto lambdaFunction = [](const void* a, const void* b)->int {
        return ((*(static_cast<const int*> (a)))-(*(static_cast<const int*> (b))));
    };

    qsort(array, 100, sizeof (int), lambdaFunction);

    for (int i = 0; i < 100; i++) {
        std::cout << array[i] << '\n';
    }

    qsort(array, 100, sizeof (int), compareFunction);

    for (int i = 0; i < 100; i++) {
        std::cout << array[i] << '\n';
    }
    
    //qsort(array, 100, sizeof (int), Compare());

    return 0;
}

