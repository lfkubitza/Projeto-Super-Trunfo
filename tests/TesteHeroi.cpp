#include "doctest.h"
#include "Heroi.h"
#include "CartasHeroi.h"

TEST_CASE("Teste valida_atributoH") {
	CHECK(valida_atributoH("1") == true);
	CHECK(valida_atributoH("2") == true);
	CHECK(valida_atributoH("3") == true);
	CHECK(valida_atributoH("4") == true);
	CHECK(valida_atributoH("5") == true);
	CHECK(valida_atributoH("6") == false);
}

