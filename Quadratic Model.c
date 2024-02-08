#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"

float data[][2] = {
        {-5.0f, 26.76f},
        {-4.47f, 20.41f},
        {-3.95f, 16.56f},
        {-3.42f, 13.94f},
        {-2.89f, 10.25f},
        {-2.37f, 4.63f},
        {-1.84f, 4.34f},
        {-1.32f, 1.58f},
        {-0.79f, 0.52f},
        {-0.26f, 0.48f},
        {0.26f, 0.21f},
        {0.79f, 2.08f},
        {1.32f, 2.49f},
        {1.84f, 3.52f},
        {2.37f, 6.05f},
        {2.89f, 8.71f},
        {3.42f, 13.2f},
        {3.95f, 15.38f},
        {4.47f, 20.33f},
        {5.0f, 24.15f}
};


int sizeOfData = sizeof(data) / sizeof(data[0]);

float predetermined_Weight();
float costFunction(float w1,float w2,float w3);
void gradient(float w1, float w2, float w3, float *dw1, float *dw2, float *dw3);

int main(){
    srand(69);  // Seed the random number generator
    printf("%d\n", sizeOfData);
    float w1 = predetermined_Weight();
    float w2 = predetermined_Weight();
    float w3 = predetermined_Weight();
    double learning_rate = 1e-3;

    float dw1, dw2, dw3;

    printf("Initial weight: %f , %f, %f\n", w1, w2, w3);
    printf("Initial cost: %f\n", costFunction(w1,w2,w3));

    for (int i = 0; i < 100000; i++) {
        gradient(w1, w2, w3,&dw1, &dw2, &dw3);
        w1 -= learning_rate * dw1;
        w2 -= learning_rate * dw2;
        w3 -= learning_rate * dw3;
        printf("Iteration %d: cost = %f, w1 = %f, w2 = %f, w3 = %f\n , ", i+1, costFunction(w1,w2,w3), w1, w2, w3);
    }

    printf("------------------------------\n");
    printf("Final weight: %f , %f, %f\n", w1, w2, w3);
    printf("------------------------------\n");
    printf("Final cost: %f\n", costFunction(w1,w2,w3));
}

float costFunction(float w1,float w2,float w3){
    float initialValue, actualValue, experimental_value, MSE;
    float result = 0.0f;

    for(int i = 0; i < sizeOfData; i++) {
        initialValue = (float)data[i][0];
        actualValue = (float)data[i][1];
        experimental_value = (float)((w1)*(initialValue*initialValue)+(w2*initialValue)+w3);
        result +=((actualValue-experimental_value)*(actualValue-experimental_value));
    }
    MSE = result / sizeOfData; // Mean Squared Error
    printf("MSE: %f\n", MSE);
    return MSE;
}

void gradient(float w1, float w2, float w3, float *dw1, float *dw2, float *dw3) {
    float gradient_w1 = 0.0f;
    float gradient_w2 = 0.0f;
    float gradient_w3 = 0.0f;

    for (size_t i = 0; i < sizeOfData; ++i) {
        float x = data[i][0];
        float y = data[i][1];
        float y_pred = (w1 * (x * x)) + (w2 * x) + w3; // Predicted value using the current weights

        // Calculate gradients for each weight
        gradient_w1 += ((x*x) * (y- y_pred ));
        gradient_w2 += (x * (y-y_pred));
        gradient_w3 += ((y-y_pred));
    }

    // Average gradients over the dataset and multiply by -2 (according to the partial derivative formulas)
    *dw1 = (gradient_w1 / sizeOfData) * -2;
    *dw2 = (gradient_w2 / sizeOfData) * -2;
    *dw3 = (gradient_w3 / sizeOfData) * -2;
}



float predetermined_Weight() {
    float x = (float)rand() / (float)RAND_MAX;  // Generate a random number
    float weight = x*10.0f;  // Scale the random number by 10,cause why not
    return weight;
}






















