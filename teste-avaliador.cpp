#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"
#include <iostream>

/*
#include "Lance.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"
*/

TEST_CASE("Deve recuperar maior lance de leilão em ordem decrescente") {

	// Preparação do ambiente - organiza as condições/cenário para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);

	// Execução do código que será testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verificação se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1500 == leiloeiro.recuperaMaiorValor());	
}

TEST_CASE("Deve recuperar maior lance de leilão em ordem crescente") {

	// Preparação do ambiente - organiza as condições/cenário para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);


	// Execução do código que será testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verificação se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1500 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão em ordem crescente") {

	// Preparação do ambiente - organiza as condições/cenário para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);


	// Execução do código que será testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verificação se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão em ordem decrescente") {

	// Preparação do ambiente - organiza as condições/cenário para o teste
	// Arrange - Given

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);


	// Execução do código que será testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verificação se o teste teve sucesso ou falha
	// Assert - Then

	REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar os três maiores lance de leilão") {

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


	// Execução do código que será testado
	// Act - When

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verificação se o teste teve sucesso ou falha
	// Assert - Then

	std::vector<Lance> maiores3Lances = leiloeiro.recupera3maioresLances();

	REQUIRE(3 == maiores3Lances.size());
}