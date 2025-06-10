#include "doctest.h"
#include "Dinossauro.h"
#include "CartasDinossauro.h"

TEST_CASE("Teste valida_atributoD") {
	CHECK(valida_atributoD("1") == true);
	CHECK(valida_atributoD("2") == true);
	CHECK(valida_atributoD("3") == true);
	CHECK(valida_atributoD("4") == true);
	CHECK(valida_atributoD("5") == false);
}

