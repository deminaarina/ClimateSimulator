#include <iostream>
#include <cmath>

const double EARTH_RADIUS = 6.371e6; // m
const double DAYS_PER_YEAR = 365.24; // days
const double DAYS_PER_MONTH = DAYS_PER_YEAR/12; // days
const double DAYS_PER_HOUR = 1.0/24; // days
const double STEFAN_BOLTZMANN = 5.67e-8; // W*m^-2*K^-4
const double AIR_MASS = 5.1480e18; // kg
const double AIR_SPECIFIC_HEAT = 1.01; // J*kg^-1*K^-1
const double AIR_DENSITY = 1.2; // kg*m^-3
const double AIR_CONDUCTIVITY = 0.0262; // W*m^-1*K^-1
const double WATER_SPECIFIC_HEAT = 4.18; // J*kg^-1*K^-1
const double WATER_DENSITY = 1000; // kg*m^-3
const double WATER_CONDUCTIVITY = 0.606; // W*m^-1*K^-1
const double WATER_HEAT_CAPACITY = WATER_SPECIFIC_HEAT*WATER_DENSITY; // J*m^-3*K^-1
const double WATER_HEAT_TRANSFER = WATER_CONDUCTIVITY/(WATER_DENSITY*WATER_HEAT_CAPACITY); // m^2*s^-1
const double ATMOSPHERE_HEAT_TRANSFER = AIR_CONDUCTIVITY/(AIR_DENSITY*AIR_SPECIFIC_HEAT); // m^2*s^-1

double solar_constant = 1361; // W/m^2
double solar_elevation = 0.409; // radians
double solar_azimuth = 1.9; // radians
double solar_declination = 0.409; // radians
double solar_transit = 12.0; // hours

double surface_temperature = 288; // K
double ocean_heat_content = 3.337e22; // J
double atmosphere_heat_content = 1.005e17; // J
double surface_albedo = 0.3; // dimensionless

double temperature_atmosphere = 288; // K
double temperature_ocean = 288; // K
double temperature_surface = 288; // K

double solar_insolation() {
    double solar_insolation = solar_constant*(1 + 0.033*cos(2*M_PI*(DAYS_PER_MONTH*12*(1.0/DAYS_PER_Y
