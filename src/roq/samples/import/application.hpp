/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include <span>

#include "roq/tool.hpp"

namespace roq {
namespace samples {
namespace import {

// Service is a base class used to initialize the environment
// it is not required, only for your convenience

struct Application final : public Tool {
  using Tool::Tool;

 protected:
  int main_helper(std::span<std::string_view> const &args);
  int main(int argc, char **argv) override;
};

}  // namespace import
}  // namespace samples
}  // namespace roq
