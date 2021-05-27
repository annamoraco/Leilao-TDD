#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"
#include <iostream>

/*
#include "Lance.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"
*/

Leilao emOrdemCrescente()
{
	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);
	return leilao;
}

Leilao emOrdemDecrescente() 
{
	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);
	return leilao;
}

TEST_CASE("Avaliador") {
	// Preparação do ambiente - organiza as condições/cenário para o teste
	// Arrange - Given

	SECTION("Maior e menor lance") {

		Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());
		Avaliador leiloeiro;

		SECTION("Deve recuperar maior lance de leilão ") {

			// Execução do código que será testado
			// Act - When

			leiloeiro.avalia(leilao);

			//  Verificação se o teste teve sucesso ou falha
			// Assert - Then

			REQUIRE(1500 == leiloeiro.recuperaMaiorValor());
		}

		SECTION("Deve recuperar menor lance de leilão ") {

			// Execução do código que será testado
			// Act - When

			leiloeiro.avalia(leilao);

			//  Verificação se o teste teve sucesso ou falha
			// Assert - Then

			REQUIRE(1000 == leiloeiro.recuperaMenorValor());
		}
	}

	SECTION("Deve recuperar os três maiores lance de leilão") {

		// Preparação do ambiente - organiza as condições/cenário para o teste
		// Arrange - Given

		Lance primeiroLance(Usuario("Anna Moraco"), 1000);
		Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
		Lance terceiroLance(Usuario("Ana Maria"), 3000);
		Lance quartoLance(Usuario("Rogerio"), 1250);
		Leilao leilao("Fiat 147 0km");
		leilao.recebeLance(segundoLance);
		leilao.recebeLance(primeiroLance);
		leilao.recebeLance(terceiroLance);
		leilao.recebeLance(quartoLance);
		Avaliador leiloeiro;

		// Execução do código que será testado
		// Act - When

		leiloeiro.avalia(leilao);

		//  Verificação se o teste teve sucesso ou falha
		// Assert - Then

		std::vector<Lance> maiores3Lances = leiloeiro.recupera3maioresLances();

		REQUIRE(3 == maiores3Lances.size());
		REQUIRE(3000 == maiores3Lances[0].recuperaValor());
		REQUIRE(1500 == maiores3Lances[1].recuperaValor());
		REQUIRE(1250 == maiores3Lances[2].recuperaValor());
	}
}

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

TEST_CASE("Usuario deve saber informar seu primeiro nome")
{
	// Arrange
	Usuario anna("Anna");

	std::string primeiroNome = anna.recuperaPrimeiroNome();

	// Assert
	REQUIRE("Anna" == primeiroNome);
}