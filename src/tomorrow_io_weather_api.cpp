#include "tomorrow_io_weather_api.hpp"
#include <memory>
#include <string>
#include <vector>
#include "simdjson.h"

TomorrowIoWeatherApi::TomorrowIoWeatherApi(std::string api_key, std::shared_ptr<IApiJsonFetcher> api_json_fetcher) {
  this->api_json_fetcher = api_json_fetcher;
  this->api_key = api_key;
}
WeatherDetails TomorrowIoWeatherApi::parseJson(std::string json_string) {
  // Create and load the parser
  simdjson::ondemand::parser parser;
  json_string = json_string;
  simdjson::padded_string json_str = simdjson::padded_string(json_string);

  simdjson::ondemand::document json_doc = parser.iterate(json_string);
  // Read and extract data
  const double temp_in_c = double(json_doc["data"]["values"]["temperature"]);
  const double direction_of_wind = double(json_doc["data"]["values"]["windDirection"]);
  const double wind_speed = double(json_doc["data"]["values"]["windSpeed"]);
  // Package and return data
  
  return {temp_in_c,direction_of_wind, wind_speed};
}

WeatherDetails TomorrowIoWeatherApi::getWeather(int latitude, int longitude){
  std::string api_url = "https://api.tomorrow.io/v4/weather/realtime?location=" + std::to_string(latitude) + "," + std::to_string(longitude) + "&apikey=" + this->api_key;
  std::cout << api_url << std::endl;
  std::vector<std::string> headers = {};
  ApiResponseAndJson_t api_response_and_json = this->api_json_fetcher->get_data(api_url, "", headers);
  return TomorrowIoWeatherApi::parseJson(api_response_and_json.json_str);
}
