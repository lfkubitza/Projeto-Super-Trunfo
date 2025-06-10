#ifndef Aviao_H
#define Aviao_H

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Cartas.h"

class Aviao : public Cartas {
private:
	int peso;
	int velocidade;
	int altitude_voo;
	float comprimento;
	float altura;
	bool super_trunfo;
public:
	std::stack<Aviao> stack_1;
	std::stack<Aviao> stack_2;

	//GETS
	int get_peso();
	int get_velocidade();
	int get_altitude_voo();
	float get_comprimento();
	float get_altura();
	bool get_super_trunfo();

	void imprime_carta ();
	
	void inverte_pilha(std::stack<Aviao> *pilha);
	int compara_cartas(Aviao carta1, Aviao carta2, std::string atributo);
	void jogada_player(std::stack<Aviao> *pilha_jogador, std::stack<Aviao> *pilha_adversario);
	bool valida_atributo(std::string atributo);

	void cartas_aviao();
	void embaralhar_cartas();
	void inicializar_pilhas();
	void jogar();

	//SETS
	void set_peso(int peso);
	void set_velocidade(int velocidade);
	void set_altitude_voo(int altitude_voo);
	void set_comprimento(float comprimento);
	void set_altura(float altura);
	void set_super_trunfo(bool super_trunfo);

};

#endif