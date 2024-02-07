#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"

int data[][2]={
        {1,10},
        {2,20},
        {3,30},
        {4,40},
        {5,50},
        {6,60},
        {7,70},
        {8,80},
        {9,90},
        {10,100},
};

int sizeOfData = sizeof(data) / sizeof(data[0]);

float predetermined_Weight();
float costFunction(float weight);
float gradient(float weight);

int main(){
    srand(69);  // Seed the random number generator
    printf("%d\n", sizeOfData);
    float w = predetermined_Weight();
    double learning_rate = 1e-3;

    printf("Initial weight: %f\n", w);
    printf("Initial cost: %f\n", costFunction(w));

    for (int i = 0; i < 1000; i++) {
        float differential = gradient(w);
        w -= learning_rate * differential;
        printf("Iteration %d: cost = %f, w = %f\n", i+1, costFunction(w), w);
    }

    printf("------------------------------\n");
    printf("Final weight: %f\n", w);
}

float costFunction(float weight){
    float initialValue, actualValue, experimental_value, MSE;
    float result = 0.0f;

    for(int i = 0; i < sizeOfData; i++) {
        initialValue = (float)data[i][0];
        actualValue = (float)data[i][1];
        experimental_value = initialValue * weight;
        result += pow((actualValue - experimental_value), 2);
    }
    MSE = result / sizeOfData; // Mean Squared Error
    return MSE;
}

float gradient(float weight) {
    float result = 0.0f;

    for (size_t i = 0; i < sizeOfData; ++i) {
        float x = data[i][0];
        float y = data[i][1];
        result += 2 * (x * weight - y) * x;
    }
    result /= sizeOfData;
    return result;
}

float predetermined_Weight() {
    float x = (float)rand() / (float)RAND_MAX;  // Generate a random number
    float weight = x*10.0f;  // Scale the random number by 10,cause why not
    return weight;
}
