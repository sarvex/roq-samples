/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include "roq/samples/example-1/flags/flags.hpp"

namespace roq {
namespace samples {
namespace example_1 {

struct Settings final : public flags::Flags {
  Settings();
};

}  // namespace example_1
}  // namespace samples
}  // namespace roq