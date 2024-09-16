#pragma once
#include "rfm_weather_api.h"
#include "curl-api-json-fetcher.hpp"
#include <curl/curl.h>
#include <string>
#include <memory>

class TomorrowIoWeatherApi: public IWeatherApi {
  public:
    TomorrowIoWeatherApi(std::string api_key, std::shared_ptr<IApiJsonFetcher> api_json_fetcher);
    WeatherDetails getWeather(int latitude, int longitude);
  private:
    std::shared_ptr<IApiJsonFetcher> api_json_fetcher;
    std::string api_key;
    size_t writeCallback(std::string, size_t size, size_t nmemb, void *userdata);
    WeatherDetails parseJson(std::string json_string);
};
