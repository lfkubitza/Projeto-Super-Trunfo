#ifndef Heroi_H
#define Heroi_H

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Cartas.h"

class Heroi: public Cartas {
private:
	int velocidade;
	int inteligencia;
	int agilidade;
	int forca;
	int habilidade;
	bool super_trunfo;

public:
	std::stack<Heroi> stack_1h;
	std::stack<Heroi> stack_2h;

	//GETS
	int get_velocidade();
	int get_inteligencia();
	int get_agilidade();
	int get_forca();
	int get_habilidade();
	bool get_super_trunfo();

	void imprime_carta() override;

	void inverte_pilhaH(std::stack<Heroi> *pilha);
	int compara_cartasH(Heroi carta1, Heroi carta2, std::string atributo);
	void jogada_playerH(std::stack<Heroi> *pilha_jogador, std::stack<Heroi> *pilha_adversario);
	bool valida_atributoH(std::string atributo);

	void cartas_heroi();
	void embaralhar_cartasH();
	void inicializar_pilhas_h();
	void jogarh();

	//SETS
	void set_velocidade(int velocidade);
	void set_inteligencia(int inteligencia);
	void set_agilidade(int agilidade);
	void set_forca(int forca);
	void set_habilidade(int habilidade);
	void set_super_trunfo(bool super_trunfo);
	
};

#endif
