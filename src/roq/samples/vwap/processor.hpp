/* Copyright (c) 2017-2024, Hans Erik Thrane */

#pragma once

#include <absl/container/node_hash_map.h>

#include <memory>

#include "roq/cache/market_by_price.hpp"

#include "roq/client/event_log_reader.hpp"

#include "roq/samples/vwap/settings.hpp"

namespace roq {
namespace samples {
namespace vwap {

struct Processor final : public client::EventLogReader::Handler {
  static void dispatch(Settings const &, std::string_view const &path);

 protected:
  explicit Processor(Settings const &);

  void operator()(Event<GatewaySettings> const &) override {}
  void operator()(Event<StreamStatus> const &) override {}
  void operator()(Event<ExternalLatency> const &) override {}
  void operator()(Event<RateLimitTrigger> const &) override {}
  void operator()(Event<GatewayStatus> const &) override {}
  void operator()(Event<ReferenceData> const &) override {}
  void operator()(Event<MarketStatus> const &) override {}
  void operator()(Event<TopOfBook> const &) override {}
  void operator()(Event<MarketByPriceUpdate> const &) override;
  void operator()(Event<MarketByOrderUpdate> const &) override {}
  void operator()(Event<TradeSummary> const &) override {}
  void operator()(Event<StatisticsUpdate> const &) override {}
  void operator()(Event<CreateOrder> const &) override {}
  void operator()(Event<ModifyOrder> const &) override {}
  void operator()(Event<CancelOrder> const &) override {}
  void operator()(Event<CancelAllOrders> const &) override {}
  void operator()(Event<CancelAllOrdersAck> const &) override {}
  void operator()(Event<OrderAck> const &) override {}
  void operator()(Event<OrderUpdate> const &) override {}
  void operator()(Event<TradeUpdate> const &) override {}
  void operator()(Event<PositionUpdate> const &) override {}
  void operator()(Event<FundsUpdate> const &) override {}
  void operator()(Event<CustomMetricsUpdate> const &) override {}
  void operator()(Event<CustomMatrixUpdate> const &) override {}
  void operator()(Event<ParametersUpdate> const &) override {}
  void operator()(Event<PortfolioUpdate> const &) override {}
  void operator()(Event<RiskLimits> const &) override {}
  void operator()(Event<RiskLimitsUpdate> const &) override {}

  cache::MarketByPrice &get_market_by_price(auto const &);

 private:
  Settings const &settings_;
  absl::node_hash_map<Symbol, std::unique_ptr<cache::MarketByPrice>> market_by_price_;
};

}  // namespace vwap
}  // namespace samples
}  // namespace roq
