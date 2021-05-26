#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"
#include <iostream>

/*
#include "Lance.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"
*/

TEST_CASE("Deve recuperar maior lance de leil�o em ordem decrescente") {

	// Prepara��o do ambiente - organiza as condi��es/cen�rio para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);

	// Execu��o do c�digo que ser� testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verifica��o se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1500 == leiloeiro.recuperaMaiorValor());	
}

TEST_CASE("Deve recuperar maior lance de leil�o em ordem crescente") {

	// Prepara��o do ambiente - organiza as condi��es/cen�rio para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);


	// Execu��o do c�digo que ser� testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verifica��o se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1500 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leil�o em ordem crescente") {

	// Prepara��o do ambiente - organiza as condi��es/cen�rio para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);


	// Execu��o do c�digo que ser� testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verifica��o se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar menor lance de leil�o em ordem decrescente") {

	// Prepara��o do ambiente - organiza as condi��es/cen�rio para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);


	// Execu��o do c�digo que ser� testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verifica��o se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar os tr�s maiores lance de leil�o") {

	// Prepara��o do ambiente - organiza as condi��es/cen�rio para o teste
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


	// Execu��o do c�digo que ser� testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verifica��o se o teste teve sucesso ou falha
	// Assert - Then

	std::vector<Lance> maiores3Lances = leiloeiro.recupera3maioresLances();

	REQUIRE(3 == maiores3Lances.size());
}