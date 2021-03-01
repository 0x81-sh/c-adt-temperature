#include <stdio.h>
#include "temperature.h"

int hasFailed = 0;
void testFunction(PTemperature (*createFn)(float), float expected, float (*getFn)(PTemperature), float using, char * name);

int main() {
    //Sanity test
    testFunction(Temp_createInitC, 10.5, Temp_getC, 10.5, "Celsius to Celsius");

    //Celsius to ...
    testFunction(Temp_createInitC, 50.899998, Temp_getF, 10.5, "Celsius to Fahrenheit");
    testFunction(Temp_createInitC, 283.65, Temp_getK, 10.5, "Celsius to Kelvin");

    //Fahrenheit to ...
    testFunction(Temp_createInitF, -11.944445, Temp_getC, 10.5, "Fahrenheit to Celsius");
    testFunction(Temp_createInitF, 261.205536, Temp_getK, 10.5, "Fahrenheit to Kelvin");

    //Kelvin to ...
    testFunction(Temp_createInitK, -262.65, Temp_getC, 10.5, "Kelvin to Celsius");
    testFunction(Temp_createInitK, -440.77, Temp_getF, 10.5, "Kelvin to Fahrenheit");

    //Check if any tests failed
    if (hasFailed == 0) {
        printf("All tests passed.\n");
    } else {
        printf("!! %d TEST FAILED. !!\n", hasFailed);
    }

    return 0;
}

void testFunction(PTemperature (*createFn)(float), float expected, float (*getFn)(PTemperature), float using, char * name) {
    printf("Test: %s\n", name);
    printf("\tInput value: %f\n", using);
    printf("\tExpected output: %f\n", expected);

    PTemperature thisTemp = createFn(using);
    float returnedValue = getFn(thisTemp);

    printf("\tGot value: %f\n", returnedValue);
    printf("\tTest %s\n\n", expected == returnedValue ? "PASSED" : "FAILED");

    hasFailed += expected != returnedValue;
    Temp_delete(thisTemp);
}