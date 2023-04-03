/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include <cstdint>

#include "roq/numbers.hpp"

namespace roq {
namespace samples {
namespace example_3 {

struct EMA final {
  explicit EMA(double alpha);

  EMA(EMA &&) = default;
  EMA(const EMA &) = delete;

  operator double() const { return value_; }

  void reset();

  bool is_ready() const { return countdown_ == 0; }

  double update(double value);

 private:
  double const alpha_;
  double value_ = NaN;
  uint32_t countdown_;
};

}  // namespace example_3
}  // namespace samples
}  // namespace roq
