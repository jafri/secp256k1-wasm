#pragma once

#include <eosio/eosio.hpp>

namespace eosio_test {
  class [[eosio::contract("test")]] test : public eosio::contract {
  public:
    using contract::contract;

    test( eosio::name receiver, eosio::name code, eosio::datastream<const char*> ds )
      : contract(receiver, code, ds) {}

    ACTION bench();
  };
}