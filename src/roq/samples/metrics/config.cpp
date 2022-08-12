/* Copyright (c) 2017-2022, Hans Erik Thrane */

#include "roq/samples/metrics/config.hpp"

#include "roq/samples/metrics/flags.hpp"

namespace roq {
namespace samples {
namespace metrics {

void Config::dispatch(Handler &handler) const {
  // callback for each subscription pattern
  handler(client::Symbol{
      .regex = Flags::symbols(),
      .exchange = {},
  });
}

}  // namespace metrics
}  // namespace samples
}  // namespace roq
