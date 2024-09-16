#include "rfm_weather_api.h"
#include "tomorrow_io_weather_api.hpp"
#include <memory>

int main() {
  std::shared_ptr<CurlApiJsonFetcher> curl = std::make_shared<CurlApiJsonFetcher>(CurlApiJsonFetcher());
  TomorrowIoWeatherApi tom = TomorrowIoWeatherApi("", curl);
}
