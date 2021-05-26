#include "Avaliador.hpp"
#include <iostream>
#include "Lance.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

int main() {

	// Preparação do ambiente - organiza as condições/cenário para o teste

	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);

	// Execução do código que será testado

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	//  Verificação se o teste teve sucesso ou falha

	float valoresperado = 1500;

	if (valoresperado == leiloeiro.recuperaMaiorValor()) {
		std::cout << "TESTE OK" << std::endl;
	}
	else {
		std::cout << "TESTE FALHOU" << std::endl;
	}
	

	return 0;
}