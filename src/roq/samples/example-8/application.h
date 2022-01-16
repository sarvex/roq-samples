/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <span>

#include "roq/service.h"

namespace roq {
namespace samples {
namespace example_8 {

// Service is a base class used to initialize the environment
// it is not required, only for your convenience

class Application final : public Service {
 public:
  using Service::Service;

 protected:
  int main_helper(const std::span<std::string_view> &args);
  int main(int argc, char **argv) override;
};

}  // namespace example_8
}  // namespace samples
}  // namespace roq
