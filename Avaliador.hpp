#pragma once
#include "Leilao.hpp"

class Avaliador
{
private:
	float maiorValor;

public:

	void avalia(Leilao);
	float recuperaMaiorValor() const;

};

