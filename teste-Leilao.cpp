#include "catch.hpp"
#include "Avaliador.hpp"
#include <iostream>

TEST_CASE("Leilao não pode receber lance consecutivo do mesmo usuário")
{
	// Arrange
	Leilao leilao("Fiat 147 0km");
	Usuario anna("Anna Moraco");

	Lance primeiroLance(anna, 1000);
	Lance segundoLance(anna, 1500);

	// Act
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	// Assert
	REQUIRE(1 == leilao.recuperaLances().size());
}