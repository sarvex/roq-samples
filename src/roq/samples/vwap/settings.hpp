/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include "roq/samples/vwap/flags/flags.hpp"

namespace roq {
namespace samples {
namespace vwap {

struct Settings final : public flags::Flags {
  Settings();
};

}  // namespace vwap
}  // namespace samples
}  // namespace roq