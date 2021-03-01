#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

struct Temperature {
    float value;
};

float convert (float value, char type, char have);

PTemperature Temp_create() {
    return (PTemperature) malloc(sizeof(struct Temperature));
}

PTemperature Temp_createInitC(float value) {
    PTemperature _this = Temp_create();
    _this->value = value;

    return _this;
}

PTemperature Temp_createInitF(float value) {
    PTemperature _this = Temp_create();
    _this->value = convert(value, 'c', 'f');

    return _this;
}

PTemperature Temp_createInitK(float value) {
    PTemperature _this = Temp_create();
    _this->value = convert(value, 'c', 'k');

    return _this;
}

float Temp_getC(PTemperature _this) {
    return _this->value;
}

float Temp_getF(PTemperature _this) {
    return convert(_this->value, 'f', 'c');
}

float Temp_getK(PTemperature _this) {
    return convert(_this->value, 'k', 'c');
}

void Temp_setC(PTemperature _this, float value) {
    _this->value = value;
}

void Temp_setF(PTemperature _this, float value) {
    _this->value = convert(value, 'c', 'f');
}

void Temp_setK(PTemperature _this, float value) {
    _this->value = convert(value, 'c', 'k');
}

void Temp_delete(PTemperature _this) {
    free(_this);
}

float convert (float value, char type, char have) {
    switch (type) {
        case 'c':
            if (have == 'f') return (value - 32) / (float) 1.8;
            if (have == 'k') return value - (float) 273.15;
            break;

        case 'f':
            if (have == 'c') return (value * (float) 1.8) + 32;
            break;

        case 'k':
            if (have == 'c') return value + (float) 273.15;
            break;

        default:
            return value;
    }

    return value;
}

