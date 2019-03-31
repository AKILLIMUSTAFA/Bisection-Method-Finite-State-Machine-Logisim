/**
 * Created by m_akilli on 29.03.2019.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calculateFunctionValue(double value, double x5, double x4, double x3, double x2, double x1, double constant);
double calculatePower(double base, int exponent, double coefficient);
double negativeToPositive(double number);

/**
 * Implementing Bisection Method
 */
int main() {
    /*
     * İnputs
     */
    double equationX5 = 0;
    double equationX4 = 0;
    double equationX3 = 1;
    double equationX2 = 0;
    double equationX1 = 3;
    double equationConstant = -5;

    double firstValue = 1;
    double secondValue = 2;

    double limitValue = 0.00001;

    double firstValueFunctionValue = calculateFunctionValue(firstValue,equationX5,equationX4,equationX3,equationX2,equationX1,equationConstant);
    
    double currentValueFunctionValue = firstValueFunctionValue;
    while( negativeToPositive(currentValueFunctionValue) > limitValue ){
        double currentValue = (firstValue + secondValue) / 2;
        currentValueFunctionValue = calculateFunctionValue(currentValue,equationX5,equationX4,equationX3,equationX2,equationX1,equationConstant);
        firstValueFunctionValue = calculateFunctionValue(firstValue,equationX5,equationX4,equationX3,equationX2,equationX1,equationConstant);
        if(firstValueFunctionValue * currentValueFunctionValue < 0){
            secondValue = currentValue;
        } else {
            firstValue = currentValue;
        }
        printf("%lf : ", currentValue);
        printf("%lf\n", currentValueFunctionValue);
    }

    return 0;
}

/**
 * Calculate Function Value
 *
 * @param value
 * @param x5
 * @param x4
 * @param x3
 * @param x2
 * @param x1
 * @param constant
 * @return
 */
double calculateFunctionValue(double value, double x5, double x4, double x3, double x2, double x1, double constant) {
    double result = 0;
    result += calculatePower(value, 5, x5);
    result += calculatePower(value, 4, x4);
    result += calculatePower(value, 3, x3);
    result += calculatePower(value, 2, x2);
    result += calculatePower(value, 1, x1);
    result += constant;
    return result;
}

/**
 * Calculate Power
 *
 * @param base
 * @param exponent
 * @param coefficient
 * @return
 */
double calculatePower(double base, int exponent, double coefficient){
    return coefficient * pow(base,exponent);
}

/**
 * İf given number negative then return positive, Otherwise return given number.
 *
 * @param number
 * @return
 */
double negativeToPositive(double number){
    if(number < 0)
        return -1 * number;
    return number;
}






