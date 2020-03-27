#include <test/test.hpp>
#include <secp256k1/libsecp256k1-config.h>
#include <secp256k1/secp256k1.c>

namespace eosio_test {

const secp256k1_context_t* get_context() {
  static secp256k1_context_t* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
  return ctx;
}

void test::bench()
{
	get_context();
}

} /** eosio_test **/