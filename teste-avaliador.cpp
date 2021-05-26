#include "Avaliador.hpp"
#include <iostream>
#include "Lance.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

int main() {
	Lance primeiroLance(Usuario("Anna Moraco"), 1000);
	Lance segundoLance(Usuario("Rodrigo Mendes"), 1500);
	Leilao leilao("Fiat 147 0km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);


	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	std::cout << leiloeiro.recuperaMaiorValor() << std::endl;

	return 0;
}