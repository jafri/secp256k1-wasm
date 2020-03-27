#include <test/test.hpp>
//
#define ECMULT_WINDOW_SIZE 15
#include <secp256k1/include/secp256k1.h>

namespace eosio_test {

const secp256k1_context* get_context() {
  static secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
  return ctx;
}

void test::bench()
{
	get_context();
}

} /** eosio_test **/