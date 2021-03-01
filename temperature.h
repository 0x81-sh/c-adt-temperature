#pragma once
typedef struct Temperature *PTemperature;

PTemperature Temp_create();
PTemperature Temp_createInitC(float value);
PTemperature Temp_createInitF(float value);
PTemperature Temp_createInitK(float value);
float Temp_getC(PTemperature _this);
float Temp_getF(PTemperature _this);
float Temp_getK(PTemperature _this);
void Temp_setC(PTemperature _this, float value);
void Temp_setF(PTemperature _this, float value);
void Temp_setK(PTemperature _this, float value);
void Temp_delete(PTemperature _this);