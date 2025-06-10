#include "doctest.h"
#include "Aviao.h"
#include "CartasAviao.h"

TEST_CASE("Teste valida_atributo") {
	CHECK(valida_atributo("1") == true);
	CHECK(valida_atributo("2") == true);
	CHECK(valida_atributo("3") == true);
	CHECK(valida_atributo("4") == true);
	CHECK(valida_atributo("5") == true);
	CHECK(valida_atributo("6") == false);
}

