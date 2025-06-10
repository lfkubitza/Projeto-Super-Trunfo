#include "doctest.h"
#include "Carro.h"
#include "CartasCarro.h"

TEST_CASE("Teste valida_atributo") {
	CHECK(valida_atributoC("1") == true);
	CHECK(valida_atributoC("2") == true);
	CHECK(valida_atributoC("3") == true);
	CHECK(valida_atributoC("4") == true);
	CHECK(valida_atributoC("5") == true);
	CHECK(valida_atributoC("6") == false);
}


