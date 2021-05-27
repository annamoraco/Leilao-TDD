#include "catch.hpp"
#include "Avaliador.hpp"
#include <iostream>

TEST_CASE("Usuario deve saber informar seu primeiro nome")
{
	// Arrange
	Usuario anna("Anna Moraco");

	std::string primeiroNome = anna.recuperaPrimeiroNome();

	// Assert
	REQUIRE("Anna" == primeiroNome);
}