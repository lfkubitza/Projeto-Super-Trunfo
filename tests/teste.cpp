#include "doctest.h"
#include "Cartas.h"
#include "Aviao.h"
#include "Heroi.h"
#include "Dinossauro.h"
#include "Carro.h"

bool Cartas::valida_atributo(std::string atributo) {
   if (atributo.compare("1") == 0)
        return true;
    else if (atributo.compare("2") == 0)
        return true;
    else if (atributo.compare("3") == 0)
        return true;
    else if (atributo.compare("4") == 0)
        return true;
    else if (atributo.compare("5") == 0)
        return true;
    else
        return false;
}


TEST_CASE("Teste valida atributo") {
	CHECK(Cartas::valida_atributo("1") == true);
	CHECK(Cartas::valida_atributo("2") == true);
	CHECK(Cartas::valida_atributo("3") == true);
	CHECK(Cartas::valida_atributo("4") == true);
	CHECK(Cartas::valida_atributo("5") == true);
	CHECK(Cartas::valida_atributo("6") == false);
}
