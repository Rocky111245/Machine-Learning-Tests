#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"


//AND-GATE
int data[][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1}
};

int sizeOfData=sizeof(data)/sizeof(data[0]);

float predetermined_Weight(float scale) {
    float x = (float)rand() / (float)RAND_MAX;  // Generate a random number
    float weight = x*scale;  // Scale the random number by 10,cause why not
    return weight;
}

float sigmoidFunction(float x){
    float y;
    y = 1 / (1 + exp(-x));
    return y;
}


float costFunction(float w1,float w2,float bias){
    float x1,x2, actualValue, experimental_value, MSE;
    float result = 0.0f;

    for(int i = 0; i < sizeOfData; i++) {
        x1 = data[i][0];
        x2 = data[i][1];
        actualValue = data[i][2];
        experimental_value = (float)(w1*x1+w2*x2+bias);
        result +=((actualValue-experimental_value)*(actualValue-experimental_value));
    }
    MSE = result / sizeOfData; // Mean Squared Error
    printf("MSE: %f\n", MSE);
    return MSE;
}

void gradient(float w1, float w2, float bias, float *dw1, float *dw2, float *dw3) {
    // Partial derivative with respect to w1
    float partialDerivativeW1 = 0.0f;
    for(int i = 0; i < sizeOfData; i++) {
        float x1 = data[i][0];
        float actualValue = data[i][2];
        float experimental_value = (w1 * x1 + w2 * data[i][1] + bias);
        partialDerivativeW1 += 2 * x1 * (actualValue-experimental_value);
    }
    partialDerivativeW1 /= -sizeOfData;

// Partial derivative with respect to w2
    float partialDerivativeW2 = 0.0f;
    for(int i = 0; i < sizeOfData; i++) {
        float x2 = data[i][1];
        float actualValue = data[i][2];
        float experimental_value = (w1 * data[i][0] + w2 * x2 + bias);
        partialDerivativeW2 += 2 * x2 * (actualValue-experimental_value);
    }
    partialDerivativeW2 /= -sizeOfData;

// Partial derivative with respect to bias
    float partialDerivativeBias = 0.0f;
    for(int i = 0; i < sizeOfData; i++) {
        float actualValue = data[i][2];
        float experimental_value = (w1 * data[i][0] + w2 * data[i][1] + bias);
        partialDerivativeBias += 2 * ((actualValue-experimental_value));
    }
    partialDerivativeBias /= -sizeOfData;

    // Average gradients over the dataset and multiply by -2 (according to the partial derivative formulas)
    *dw1 = partialDerivativeW1;
    *dw2 = partialDerivativeW2;
    *dw3 = partialDerivativeBias;

}
//--------------------------------------------------------------------------------------------------------------------------------//
// Example function for OR gate model
float OR(float x1, float x2) {
    // Assuming weights: w1, w2 and bias: b for OR gate
    float output = (0.500067) * x1 + (0.500067)* x2 +(0.249929);

    return output > 0.5 ? 1 : 0; // Applying threshold for binary output
}

// Example function for NAND gate model
float NAND(float x1, float x2) {
    // Assuming weights: w1, w2 and bias: b for NAND gate
    float output = (-0.499911) * x1 + (-0.499911)* x2 +(1.249881);
    return output > 0.5 ? 1 : 0; // Applying threshold for binary output
}

// Example function for AND gate model
float AND(float x1, float x2) {
    // Assuming weights: w1, w2 and bias: b for AND gate
    float output = (0.500075)* x1 + (0.500075)* x2 -(0.250082);
    return output > 0.5 ? 1 : 0; // Applying threshold for binary output
}

float XOR(float x1, float x2) {
    // Compute the intermediate outputs using OR and NAND
    float or_output = OR(x1, x2);
    float nand_output = NAND(x1, x2);

    // Use the intermediate outputs as inputs to the AND function
    float xor_output = AND(or_output, nand_output);
    return xor_output;
}









int main(){
    srand(69);
    float gradient_w1 = 0.0f;
    float gradient_w2 = 0.0f;
    float gradient_bias = 0.0f;
    int x1,x2,y;
    float w1= predetermined_Weight(10.0f);
    float w2= predetermined_Weight(10.0f);
    float bias= predetermined_Weight(5.0f);
    float learningRate = 1e-3;
    float dw1, dw2,dw3;

    printf("%d\n", sizeOfData);
    printf("Initial weight: %f , %f, %f\n", w1, w2, bias);
    printf("Initial cost: %f\n", costFunction(w1,w2,bias));

        for (int i = 0; i < 4; i++) {
            float x=XOR(1,1);
            float y=XOR(1,0);
            float z=XOR(0,1);
            float a=XOR(0,0);
            printf("%d\n");
            printf("XOR VALUE IS %f",x);
            printf("%d\n");
            printf("XOR VALUE IS %f",y);
            printf("%d\n");
            printf("XOR VALUE IS %f",z);
            printf("%d\n");
            printf("XOR VALUE IS %f",a);
            printf("%d\n");
//        gradient(w1, w2, bias,&dw1, &dw2,&dw3);
//        w1 -= learningRate * dw1;
//        w2 -= learningRate * dw2;
//        bias -= learningRate * dw3;
//        printf("Iteration %d: cost = %f, w1 = %f, w2 = %f, w3 = %f\n , ", i+1, costFunction(w1,w2,bias), w1, w2, bias);
    }

    printf("------------------------------\n");
    printf("Final weight: %f , %f, %f\n", w1, w2, bias);
    printf("------------------------------\n");
    printf("Final cost: %f\n", costFunction(w1,w2,bias));

}





