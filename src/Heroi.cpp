#include "Heroi.h"
#include <iostream>
#include <string>

Heroi carta_h[32];

int Heroi::get_velocidade(){
	return velocidade;
}

int Heroi::get_inteligencia(){
	return inteligencia;
}

int Heroi::get_agilidade(){
	return agilidade;
}

int Heroi::get_forca(){
	return forca;
}

int Heroi::get_habilidade(){
	return habilidade;
}

bool Heroi::get_super_trunfo(){
	return super_trunfo;
}

void Heroi::imprime_carta(){
	std::cout << "##########CARTA##########" << std::endl;
	std::cout << "Nome: " << get_nome() << std::endl;
	std::cout << "Tipo: " << get_tipo() << std::endl << std::endl;
	std::cout << "1 Velocidade: " << get_velocidade() << std::endl;
	std::cout << "2 Inteligencia: " << get_inteligencia() << std::endl;
	std::cout << "3 Agilidade: " << get_agilidade() << std::endl;
	std::cout << "4 Força: " << get_forca() << std::endl;
	std::cout << "5 Habilidade: " << get_habilidade() << std::endl;
	std::cout << "#########################" << std::endl << std::endl;
}

void Heroi::set_velocidade(int velocidade){
	this-> velocidade = velocidade;
}

void Heroi::set_inteligencia(int inteligencia){
	this-> inteligencia = inteligencia;
}

void Heroi::set_agilidade(int agilidade){
	this-> agilidade = agilidade;
}

void Heroi::set_forca(int forca){
	this-> forca = forca;
}

void Heroi::set_habilidade(int habilidade){
	this-> habilidade = habilidade;
}

void Heroi::set_super_trunfo(bool super_trunfo){
	this-> super_trunfo = super_trunfo;
}

void Heroi::inverte_pilhaH(std::stack<Heroi> *pilha) {
    std::stack<Heroi> stack_temp_1;
    std::stack<Heroi> stack_temp_2;

    while (!pilha->empty()){
        stack_temp_1.push(pilha->top());
        pilha->pop();
    }
    while (!stack_temp_1.empty()){
        stack_temp_2.push(stack_temp_1.top());
        stack_temp_1.pop();
    }
    while (!stack_temp_2.empty()){
        pilha->push(stack_temp_2.top());
        stack_temp_2.pop();
    }
}

int Heroi::compara_cartasH(Heroi carta1, Heroi carta2, std::string atributo) {
    if (atributo.compare("1") == 0) {
        if ((carta1.get_velocidade() - carta2.get_velocidade()) != 0)
            return carta1.get_velocidade() - carta2.get_velocidade();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("2") == 0) {
        if ((carta1.get_inteligencia() - carta2.get_inteligencia()) != 0)
            return carta1.get_inteligencia() - carta2.get_inteligencia();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("3") == 0) {
        if ((carta1.get_agilidade() - carta2.get_agilidade()) != 0)
            return carta1.get_agilidade() - carta2.get_agilidade();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());

    }
    else if (atributo.compare("4") == 0) {
        if ((carta1.get_forca() - carta2.get_forca()) != 0)
            return carta1.get_forca() - carta2.get_forca();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("5") == 0) {
    	if ((carta1.get_habilidade() - carta2.get_habilidade()) != 0)
    		return carta1.get_habilidade() - carta2.get_habilidade();
        else
        	return carta2.get_tipo().compare(carta1.get_tipo());
    }

    return 0;
}

void Heroi::jogada_playerH(std::stack<Heroi> *pilha_jogador, std::stack<Heroi> *pilha_adversario) {
    Heroi carta_jogador = pilha_jogador->top();
    Heroi carta_adversario = pilha_adversario->top();

    //int player_atual1 = 1;
    int player_adversario;

    if (player_atual == 2)
        player_adversario = 1;
    else
        player_adversario = 2;

    std::cout << std::endl << "[NOVA JOGADA]" << std::endl;
    std::cout << "PLAYER " << player_atual << std::endl;
    std::cout << std::endl << "CARTA PLAYER " << player_atual << std::endl;
    carta_jogador.imprime_carta();

    if (carta_jogador.get_super_trunfo() == true) {
        std::cout << "[EH TRUNFO]" << std::endl;
        std::cout << std::endl << "CARTA PLAYER " << player_adversario << std::endl;
        carta_adversario.imprime_carta();

        if(carta_adversario.get_tipo().substr(0,1).compare("A") == 0) {
            std::cout << std::endl << "PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaH(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            pilha_jogador->pop();
            inverte_pilhaH(pilha_adversario);
            player_atual = player_adversario;
        }else {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaH(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaH(pilha_jogador);
            pilha_adversario->pop();
        }
    }else {

        std::string atributo;

        std::cout << "Selecione um Atributo [1 | 2 | 3 | 4 | 5 ]: ";
        std::cin >> atributo;

        while(!Cartas::valida_atributo(atributo)) {
            std::cin.clear();
            std::cin.ignore();

            std::cout << "ATRIBUTO INVALIDO!" << std::endl;
            std::cout << "Selecione um Atributo [1 | 2 | 3 | 4 | 5 ]: ";
            std::cin >> atributo;
        }

        std::cout << "ATRIBUTO ESCOLHIDO: " << atributo << std::endl;
        std::cout << std::endl << "CARTA PLAYER " << player_adversario << std::endl;
        carta_adversario.imprime_carta();

        if(compara_cartasH(carta_jogador, carta_adversario, atributo) > 0) {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaH(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaH(pilha_jogador);
            pilha_adversario->pop();
        }else {
            std::cout << std::endl << "[PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;

            Heroi temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaH(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            inverte_pilhaH(pilha_adversario);
            pilha_jogador->pop();
            player_atual = player_adversario;
        }
    }
}

void Heroi::cartas_heroi(){
    carta_h[0].set_nome("Abominavel");
    carta_h[0].set_tipo("A1");
    carta_h[0].set_velocidade(3);
    carta_h[0].set_inteligencia(3);
    carta_h[0].set_agilidade(1);
    carta_h[0].set_forca(6);
    carta_h[0].set_habilidade(3);
    carta_h[0].set_super_trunfo(false);

    carta_h[1].set_nome("Capitao America");
    carta_h[1].set_tipo("A2");
    carta_h[1].set_velocidade(2);
    carta_h[1].set_inteligencia(3);
    carta_h[1].set_agilidade(2);
    carta_h[1].set_forca(3);
    carta_h[1].set_habilidade(6);
    carta_h[1].set_super_trunfo(false);

    carta_h[2].set_nome("Thor");
    carta_h[2].set_tipo("A3");
    carta_h[2].set_velocidade(5);
    carta_h[2].set_inteligencia(2);
    carta_h[2].set_agilidade(3);
    carta_h[2].set_forca(6);
    carta_h[2].set_habilidade(3);
    carta_h[2].set_super_trunfo(false);

    carta_h[3].set_nome("Hulk");
    carta_h[3].set_tipo("A4");
    carta_h[3].set_velocidade(5);
    carta_h[3].set_inteligencia(2);
    carta_h[3].set_agilidade(3);
    carta_h[3].set_forca(6);
    carta_h[3].set_habilidade(3);
    carta_h[3].set_super_trunfo(false);

    carta_h[4].set_nome("Nick Fury");
    carta_h[4].set_tipo("A5");
    carta_h[4].set_velocidade(2);
    carta_h[4].set_inteligencia(3);
    carta_h[4].set_agilidade(6);
    carta_h[4].set_forca(1);
    carta_h[4].set_habilidade(4);
    carta_h[4].set_super_trunfo(false);

    carta_h[5].set_nome("Viuva Negra");
    carta_h[5].set_tipo("A6");
    carta_h[5].set_velocidade(2);
    carta_h[5].set_inteligencia(3);
    carta_h[5].set_agilidade(4);
    carta_h[5].set_forca(1);
    carta_h[5].set_habilidade(6);
    carta_h[5].set_super_trunfo(false);

    carta_h[6].set_nome("Odin");
    carta_h[6].set_tipo("A7");
    carta_h[6].set_velocidade(2);
    carta_h[6].set_inteligencia(6);
    carta_h[6].set_agilidade(6);
    carta_h[6].set_forca(5);
    carta_h[6].set_habilidade(1);
    carta_h[6].set_super_trunfo(false);

    carta_h[7].set_nome("Sif");
    carta_h[7].set_tipo("A8");
    carta_h[7].set_velocidade(2);
    carta_h[7].set_inteligencia(3);
    carta_h[7].set_agilidade(3);
    carta_h[7].set_forca(4);
    carta_h[7].set_habilidade(4);
    carta_h[7].set_super_trunfo(false);

    carta_h[8].set_nome("Gaviao Arqueiro");
    carta_h[8].set_tipo("B1");
    carta_h[8].set_velocidade(1);
    carta_h[8].set_inteligencia(2);
    carta_h[8].set_agilidade(5);
    carta_h[8].set_forca(1);
    carta_h[8].set_habilidade(6);
    carta_h[8].set_super_trunfo(false);

    carta_h[9].set_nome("Agente Hill");
    carta_h[9].set_tipo("B2");
    carta_h[9].set_velocidade(1);
    carta_h[9].set_inteligencia(3);
    carta_h[9].set_agilidade(5);
    carta_h[9].set_forca(1);
    carta_h[9].set_habilidade(4);
    carta_h[9].set_super_trunfo(false);

    carta_h[10].set_nome("Agente Coulson");
    carta_h[10].set_tipo("B3");
    carta_h[10].set_velocidade(1);
    carta_h[10].set_inteligencia(2);
    carta_h[10].set_agilidade(5);
    carta_h[10].set_forca(1);
    carta_h[10].set_habilidade(3);
    carta_h[10].set_super_trunfo(false);

    carta_h[11].set_nome("Tony Stark");
    carta_h[11].set_tipo("B4");
    carta_h[11].set_velocidade(1);
    carta_h[11].set_inteligencia(6);
    carta_h[11].set_agilidade(5);
    carta_h[11].set_forca(1);
    carta_h[11].set_habilidade(1);
    carta_h[11].set_super_trunfo(false);

    carta_h[12].set_nome("Bruce Banner");
    carta_h[12].set_tipo("B5");
    carta_h[12].set_velocidade(1);
    carta_h[12].set_inteligencia(6);
    carta_h[12].set_agilidade(3);
    carta_h[12].set_forca(1);
    carta_h[12].set_habilidade(1);
    carta_h[12].set_super_trunfo(false);

    carta_h[13].set_nome("Loki");
    carta_h[13].set_tipo("B6");
    carta_h[13].set_velocidade(4);
    carta_h[13].set_inteligencia(5);
    carta_h[13].set_agilidade(5);
    carta_h[13].set_forca(5);
    carta_h[13].set_habilidade(4);
    carta_h[13].set_super_trunfo(false);

    carta_h[14].set_nome("Bucky Barnes");
    carta_h[14].set_tipo("B7");
    carta_h[14].set_velocidade(2);
    carta_h[14].set_inteligencia(3);
    carta_h[14].set_agilidade(3);
    carta_h[14].set_forca(1);
    carta_h[14].set_habilidade(3);
    carta_h[14].set_super_trunfo(false);

    carta_h[15].set_nome("Destruidor");
    carta_h[15].set_tipo("B8");
    carta_h[15].set_velocidade(4);
    carta_h[15].set_inteligencia(1);
    carta_h[15].set_agilidade(3);
    carta_h[15].set_forca(6);
    carta_h[15].set_habilidade(3);
    carta_h[15].set_super_trunfo(false);

    carta_h[16].set_nome("Chitauri");
    carta_h[16].set_tipo("C1");
    carta_h[16].set_velocidade(1);
    carta_h[16].set_inteligencia(1);
    carta_h[16].set_agilidade(3);
    carta_h[16].set_forca(2);
    carta_h[16].set_habilidade(2);
    carta_h[16].set_super_trunfo(false);

    carta_h[17].set_nome("Leviathan");
    carta_h[17].set_tipo("C2");
    carta_h[17].set_velocidade(5);
    carta_h[17].set_inteligencia(1);
    carta_h[17].set_agilidade(5);
    carta_h[17].set_forca(5);
    carta_h[17].set_habilidade(1);
    carta_h[17].set_super_trunfo(false);

    carta_h[18].set_nome("Caveira Vermelha");
    carta_h[18].set_tipo("C3");
    carta_h[18].set_velocidade(2);
    carta_h[18].set_inteligencia(3);
    carta_h[18].set_agilidade(4);
    carta_h[18].set_forca(3);
    carta_h[18].set_habilidade(4);
    carta_h[18].set_super_trunfo(false);

    carta_h[19].set_nome("Soldados Hidra");
    carta_h[19].set_tipo("C4");
    carta_h[19].set_velocidade(1);
    carta_h[19].set_inteligencia(2);
    carta_h[19].set_agilidade(4);
    carta_h[19].set_forca(2);
    carta_h[19].set_habilidade(2);
    carta_h[19].set_super_trunfo(false);

    carta_h[20].set_nome("Chicote Negro");
    carta_h[20].set_tipo("C5");
    carta_h[20].set_velocidade(2);
    carta_h[20].set_inteligencia(6);
    carta_h[20].set_agilidade(4);
    carta_h[20].set_forca(2);
    carta_h[20].set_habilidade(3);
    carta_h[20].set_super_trunfo(false);

    carta_h[21].set_nome("Homem de Ferro");
    carta_h[21].set_tipo("C6");
    carta_h[21].set_velocidade(6);
    carta_h[21].set_inteligencia(6);
    carta_h[21].set_agilidade(5);
    carta_h[21].set_forca(5);
    carta_h[21].set_habilidade(2);
    carta_h[21].set_super_trunfo(true);

    carta_h[22].set_nome("Dum Dum Dugan");
    carta_h[22].set_tipo("C7");
    carta_h[22].set_velocidade(2);
    carta_h[22].set_inteligencia(2);
    carta_h[22].set_agilidade(2);
    carta_h[22].set_forca(1);
    carta_h[22].set_habilidade(3);
    carta_h[22].set_super_trunfo(false);

    carta_h[23].set_nome("Homem de Ferro (Mark V)");
    carta_h[23].set_tipo("C8");
    carta_h[23].set_velocidade(4);
    carta_h[23].set_inteligencia(6);
    carta_h[23].set_agilidade(4);
    carta_h[23].set_forca(5);
    carta_h[23].set_habilidade(2);
    carta_h[23].set_super_trunfo(false);

    carta_h[24].set_nome("Gigante de Gelo");
    carta_h[24].set_tipo("D1");
    carta_h[24].set_velocidade(3);
    carta_h[24].set_inteligencia(2);
    carta_h[24].set_agilidade(2);
    carta_h[24].set_forca(4);
    carta_h[24].set_habilidade(3);
    carta_h[24].set_super_trunfo(false);

    carta_h[25].set_nome("Monge de Ferro");
    carta_h[25].set_tipo("D2");
    carta_h[25].set_velocidade(4);
    carta_h[25].set_inteligencia(4);
    carta_h[25].set_agilidade(5);
    carta_h[25].set_forca(5);
    carta_h[25].set_habilidade(2);
    carta_h[25].set_super_trunfo(false);

    carta_h[26].set_nome("Heimdall");
    carta_h[26].set_tipo("D3");
    carta_h[26].set_velocidade(3);
    carta_h[26].set_inteligencia(2);
    carta_h[26].set_agilidade(3);
    carta_h[26].set_forca(4);
    carta_h[26].set_habilidade(3);
    carta_h[26].set_super_trunfo(false);

    carta_h[27].set_nome("Emil Blonsk");
    carta_h[27].set_tipo("D4");
    carta_h[27].set_velocidade(3);
    carta_h[27].set_inteligencia(3);
    carta_h[27].set_agilidade(2);
    carta_h[27].set_forca(2);
    carta_h[27].set_habilidade(5);
    carta_h[27].set_super_trunfo(false);

    carta_h[28].set_nome("Howard Stark");
    carta_h[28].set_tipo("D5");
    carta_h[28].set_velocidade(1);
    carta_h[28].set_inteligencia(6);
    carta_h[28].set_agilidade(4);
    carta_h[28].set_forca(1);
    carta_h[28].set_habilidade(2);
    carta_h[28].set_super_trunfo(false);

    carta_h[29].set_nome("Maquina de Combate");
    carta_h[29].set_tipo("D6");
    carta_h[29].set_velocidade(5);
    carta_h[29].set_inteligencia(3);
    carta_h[29].set_agilidade(5);
    carta_h[29].set_forca(5);
    carta_h[29].set_habilidade(2);
    carta_h[29].set_super_trunfo(false);

    carta_h[30].set_nome("Feiticeira Escarlate");
    carta_h[30].set_tipo("D7");
    carta_h[30].set_velocidade(2);
    carta_h[30].set_inteligencia(5);
    carta_h[30].set_agilidade(1);
    carta_h[30].set_forca(2);
    carta_h[30].set_habilidade(6);
    carta_h[30].set_super_trunfo(false);

    carta_h[31].set_nome("Homem Formiga");
    carta_h[31].set_tipo("D8");
    carta_h[31].set_velocidade(4);
    carta_h[31].set_inteligencia(5);
    carta_h[31].set_agilidade(5);
    carta_h[31].set_forca(2);
    carta_h[31].set_habilidade(3);
    carta_h[31].set_super_trunfo(false);
}

void Heroi::embaralhar_cartasH() {
    srand(time(0));
    std::random_shuffle(&carta_h[0], &carta_h[31]);
    std::cout << ">>> Cartas Embaralhadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Heroi::inicializar_pilhas_h() {
    for (int i = 0; i < 32 / 2; i++){
        stack_1h.push(carta_h[i]);
    }
    for (int i = 32 / 2; i < 32; i++){
        stack_2h.push(carta_h[i]);
    }

    std::cout << ">>> Pilhas de Cartas Montadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Heroi::jogarh() {
    int rodada = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    while(!stack_1h.empty() && !stack_2h.empty()) {

        system("clear");
        std::cout << std::endl << ">>> Placar <<<" << std::endl;
        std::cout << "P1 - " << stack_1h.size() << " Cartas" << " x " << stack_2h.size() << " Cartas - " << "P2"<< std::endl;
        std::cout << "Rodada: " << rodada++ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        if (player_atual == 1)
            jogada_playerH(&stack_1h, &stack_2h);
        else
            jogada_playerH(&stack_2h, &stack_1h);

        std::this_thread::sleep_for(std::chrono::milliseconds(5500));
    }

    if (stack_1h.empty())
        std::cout << std::endl << "FIM DE JOGO - PLAYER 2 VENCEU!!!" << std::endl << std::endl;
    else
        std::cout << std::endl << "FIM DE JOGO - PLAYER 1 VENCEU!!!" << std::endl << std::endl;

    std::cout << "Total de Rodadas: " << rodada;
}