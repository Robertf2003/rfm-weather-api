#pragma once

typedef struct {
  double temp_in_c;
  double direction_of_wind;
  double wind_speed;
} WeatherDetails;

class IWeatherApi
{
  public:
    virtual WeatherDetails getWeather(int longitude, int latitude) = 0;
};

