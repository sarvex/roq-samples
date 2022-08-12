/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <span>

#include "roq/service.hpp"

namespace roq {
namespace samples {
namespace metrics {

// Service is a base class used to initialize the environment
// it is not required, only for your convenience

class Application final : public Service {
 public:
  using Service::Service;

 protected:
  int main_helper(std::span<std::string_view> const &args);
  int main(int argc, char **argv) override;
};

}  // namespace metrics
}  // namespace samples
}  // namespace roq
