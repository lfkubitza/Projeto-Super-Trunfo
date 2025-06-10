#include "Dinossauro.h"
#include <iostream>
#include <string>

Dinossauro carta_d[32];

float Dinossauro::get_altura(){
	return altura;
}

float Dinossauro::get_peso(){
	return peso;
}

float Dinossauro::get_comprimento(){
	return comprimento;
}

int Dinossauro::get_viveu_ha(){
	return viveu_ha;
}

bool Dinossauro::get_super_trunfo(){
	return super_trunfo;
}

void Dinossauro::imprime_carta(){
	std::cout << "##########CARTA##########" << std::endl;
	std::cout << "# Nome: " << get_nome() << std::endl;
	std::cout << "# Tipo: " << get_tipo() << std::endl << std::endl;
	std::cout << "# 1 Altura: " << get_altura() << std::endl;
	std::cout << "# 2 Peso: " << get_peso() << std::endl;
	std::cout << "# 3 Comprimento: " << get_comprimento() << std::endl;
	std::cout << "# 4 Viveu ha: " << get_viveu_ha() << std::endl;
	std::cout << "#########################" << std::endl << std::endl;
}

void Dinossauro::set_altura(float altura){
	this-> altura = altura;
}

void Dinossauro::set_peso(float peso){
	this-> peso = peso;
}

void Dinossauro::set_comprimento(float comprimento){
	this-> comprimento = comprimento;
}

void Dinossauro::set_viveu_ha(int viveu_ha){
	this-> viveu_ha = viveu_ha;
}

void Dinossauro::set_super_trunfo(bool super_trunfo){
	this-> super_trunfo = super_trunfo;
}

void Dinossauro::inverte_pilhaD(std::stack<Dinossauro> *pilha) {
    std::stack<Dinossauro> stack_temp_1;
    std::stack<Dinossauro> stack_temp_2;

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

int Dinossauro::compara_cartasD(Dinossauro carta1, Dinossauro carta2, std::string atributo) {
    if (atributo.compare("1") == 0) {
        if ((carta1.get_altura() - carta2.get_altura()) != 0)
            return carta1.get_altura() - carta2.get_altura();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("2") == 0) {
        if ((carta1.get_peso() - carta2.get_peso()) != 0)
            return carta1.get_peso() - carta2.get_peso();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("3") == 0) {
        if ((carta1.get_comprimento() - carta2.get_comprimento()) != 0)
            return carta1.get_comprimento() - carta2.get_comprimento();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());

    }
    else if (atributo.compare("4") == 0) {
        if ((carta1.get_viveu_ha() - carta2.get_viveu_ha()) != 0)
            return carta1.get_viveu_ha() - carta2.get_viveu_ha();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }

    return 0;
}

void Dinossauro::jogada_playerD(std::stack<Dinossauro> *pilha_jogador, std::stack<Dinossauro> *pilha_adversario) {
    Dinossauro carta_jogador = pilha_jogador->top();
    Dinossauro carta_adversario = pilha_adversario->top();

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

            Dinossauro temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaD(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            pilha_jogador->pop();
            inverte_pilhaD(pilha_adversario);
            player_atual = player_adversario;
        }else {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;
            
            Dinossauro temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaD(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaD(pilha_jogador);
            pilha_adversario->pop();
        }
    }else {

        std::string atributo;

        std::cout << "Selecione um Atributo [1 | 2 | 3 | 4 ]: ";
        std::cin >> atributo;

        while(!Cartas::valida_atributo(atributo)) {
            std::cin.clear();
            std::cin.ignore();

            std::cout << "ATRIBUTO INVALIDO!" << std::endl;
            std::cout << "Selecione um Atributo [1 | 2 | 3 | 4 ]: ";
            std::cin >> atributo;
        }

        std::cout << "ATRIBUTO ESCOLHIDO: " << atributo << std::endl;
        std::cout << std::endl << "CARTA PLAYER " << player_adversario << std::endl;
        carta_adversario.imprime_carta();

        if(compara_cartasD(carta_jogador, carta_adversario, atributo) > 0) {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;
                
            Dinossauro temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaD(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaD(pilha_jogador);
            pilha_adversario->pop();
        }else {
            std::cout << std::endl << "[PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;
                
            Dinossauro temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaD(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            inverte_pilhaD(pilha_adversario);
            pilha_jogador->pop();
            player_atual = player_adversario;
        }
    }
}

void Dinossauro::cartas_dinossauro() {
    carta_d[0].set_nome("Herrerassauro");
    carta_d[0].set_tipo("A1");
    carta_d[0].set_altura(1.50);
    carta_d[0].set_peso(4.50);
    carta_d[0].set_comprimento(300);
    carta_d[0].set_viveu_ha(231);
    carta_d[0].set_super_trunfo(false);

    carta_d[1].set_nome("Pterodactilo");
    carta_d[1].set_tipo("A2");
    carta_d[1].set_altura(0.50);
    carta_d[1].set_peso(1.00);
    carta_d[1].set_comprimento(1);
    carta_d[1].set_viveu_ha(150);
    carta_d[1].set_super_trunfo(false);

    carta_d[2].set_nome("Plateossauro");
    carta_d[2].set_tipo("A3");
    carta_d[2].set_altura(2.00);
    carta_d[2].set_peso(9.00);
    carta_d[2].set_comprimento(4000);
    carta_d[2].set_viveu_ha(221);
    carta_d[2].set_super_trunfo(false);

    carta_d[3].set_nome("Ultrassauro");
    carta_d[3].set_tipo("A4");
    carta_d[3].set_altura(22.00);
    carta_d[3].set_peso(38.00);
    carta_d[3].set_comprimento(90000);
    carta_d[3].set_viveu_ha(154);
    carta_d[3].set_super_trunfo(false);

    carta_d[4].set_nome("Coelophisis");
    carta_d[4].set_tipo("A5");
    carta_d[4].set_altura(1.80);
    carta_d[4].set_peso(3.00);
    carta_d[4].set_comprimento(30);
    carta_d[4].set_viveu_ha(227);
    carta_d[4].set_super_trunfo(false);

    carta_d[5].set_nome("Othnielia");
    carta_d[5].set_tipo("A6");
    carta_d[5].set_altura(1.10);
    carta_d[5].set_peso(1.50);
    carta_d[5].set_comprimento(40);
    carta_d[5].set_viveu_ha(146);
    carta_d[5].set_super_trunfo(false);

    carta_d[6].set_nome("Eoraptor");
    carta_d[6].set_tipo("A7");
    carta_d[6].set_altura(0.80);
    carta_d[6].set_peso(1.00);
    carta_d[6].set_comprimento(10);
    carta_d[6].set_viveu_ha(231);
    carta_d[6].set_super_trunfo(false);

    carta_d[7].set_nome("Oftalmossauro");
    carta_d[7].set_tipo("A8");
    carta_d[7].set_altura(1.30);
    carta_d[7].set_peso(5.00);
    carta_d[7].set_comprimento(3000);
    carta_d[7].set_viveu_ha(165);
    carta_d[7].set_super_trunfo(false);

    carta_d[8].set_nome("Procompsognato");
    carta_d[8].set_tipo("B1");
    carta_d[8].set_altura(0.30);
    carta_d[8].set_peso(1.20);
    carta_d[8].set_comprimento(1);
    carta_d[8].set_viveu_ha(222);
    carta_d[8].set_super_trunfo(false);

    carta_d[9].set_nome("Velociraptor");
    carta_d[9].set_tipo("B2");
    carta_d[9].set_altura(1.00);
    carta_d[9].set_peso(1.80);
    carta_d[9].set_comprimento(15);
    carta_d[9].set_viveu_ha(80);
    carta_d[9].set_super_trunfo(false);

    carta_d[10].set_nome("Peteinossauro");
    carta_d[10].set_tipo("B3");
    carta_d[10].set_altura(0.30);
    carta_d[10].set_peso(0.60);
    carta_d[10].set_comprimento(0.20);
    carta_d[10].set_viveu_ha(210);
    carta_d[10].set_super_trunfo(false);

    carta_d[11].set_nome("Tiranossauro Rex");
    carta_d[11].set_tipo("B4");
    carta_d[11].set_altura(5.60);
    carta_d[11].set_peso(14.0);
    carta_d[11].set_comprimento(7000);
    carta_d[11].set_viveu_ha(68);
    carta_d[11].set_super_trunfo(true);

    carta_d[12].set_nome("Melanorossauro");
    carta_d[12].set_tipo("B5");
    carta_d[12].set_altura(12.00);
    carta_d[12].set_peso(15.00);
    carta_d[12].set_comprimento(8000);
    carta_d[12].set_viveu_ha(228);
    carta_d[12].set_super_trunfo(false);

    carta_d[13].set_nome("Carcharodontossauro");
    carta_d[13].set_tipo("B6");
    carta_d[13].set_altura(5.80);
    carta_d[13].set_peso(14.00);
    carta_d[13].set_comprimento(8000);
    carta_d[13].set_viveu_ha(113);
    carta_d[13].set_super_trunfo(false);

    carta_d[14].set_nome("Nothossauro");
    carta_d[14].set_tipo("B7");
    carta_d[14].set_altura(8.00);
    carta_d[14].set_peso(9.00);
    carta_d[14].set_comprimento(400);
    carta_d[14].set_viveu_ha(220);
    carta_d[14].set_super_trunfo(false);

    carta_d[15].set_nome("Psitacossauro");
    carta_d[15].set_tipo("B8");
    carta_d[15].set_altura(0.70);
    carta_d[15].set_peso(2.00);
    carta_d[15].set_comprimento(25);
    carta_d[15].set_viveu_ha(125);
    carta_d[15].set_super_trunfo(false);

    carta_d[16].set_nome("Patagossauro");
    carta_d[16].set_tipo("C1");
    carta_d[16].set_altura(8.00);
    carta_d[16].set_peso(18.00);
    carta_d[16].set_comprimento(16000);
    carta_d[16].set_viveu_ha(169);
    carta_d[16].set_super_trunfo(false);

    carta_d[17].set_nome("Triceratops");
    carta_d[17].set_tipo("C2");
    carta_d[17].set_altura(6.00);
    carta_d[17].set_peso(9.00);
    carta_d[17].set_comprimento(6000);
    carta_d[17].set_viveu_ha(68);
    carta_d[17].set_super_trunfo(false);

    carta_d[18].set_nome("Estegossauro");
    carta_d[18].set_tipo("C3");
    carta_d[18].set_altura(4.00);
    carta_d[18].set_peso(9.00);
    carta_d[18].set_comprimento(2000);
    carta_d[18].set_viveu_ha(156);
    carta_d[18].set_super_trunfo(false);

    carta_d[19].set_nome("Carnotauro");
    carta_d[19].set_tipo("C4");
    carta_d[19].set_altura(3.00);
    carta_d[19].set_peso(7.50);
    carta_d[19].set_comprimento(1000);
    carta_d[19].set_viveu_ha(113);
    carta_d[19].set_super_trunfo(false);

    carta_d[20].set_nome("Brachiossauro");
    carta_d[20].set_tipo("C5");
    carta_d[20].set_altura(15.00);
    carta_d[20].set_peso(28.00);
    carta_d[20].set_comprimento(50000);
    carta_d[20].set_viveu_ha(156);
    carta_d[20].set_super_trunfo(false);

    carta_d[21].set_nome("Barionix");
    carta_d[21].set_tipo("C6");
    carta_d[21].set_altura(8.00);
    carta_d[21].set_peso(12.00);
    carta_d[21].set_comprimento(2000);
    carta_d[21].set_viveu_ha(125);
    carta_d[21].set_super_trunfo(false);

    carta_d[22].set_nome("Diplodoco");
    carta_d[22].set_tipo("C7");
    carta_d[22].set_altura(5.0);
    carta_d[22].set_peso(27.0);
    carta_d[22].set_comprimento(20000);
    carta_d[22].set_viveu_ha(156);
    carta_d[22].set_super_trunfo(false);

    carta_d[23].set_nome("Oviraptor");
    carta_d[23].set_tipo("C8");
    carta_d[23].set_altura(1.30);
    carta_d[23].set_peso(2.50);
    carta_d[23].set_comprimento(35);
    carta_d[23].set_viveu_ha(80);
    carta_d[23].set_super_trunfo(false);

    carta_d[24].set_nome("Ceratossauro");
    carta_d[24].set_tipo("D1");
    carta_d[24].set_altura(2.00);
    carta_d[24].set_peso(6.00);
    carta_d[24].set_comprimento(1000);
    carta_d[24].set_viveu_ha(156);
    carta_d[24].set_super_trunfo(false);

    carta_d[25].set_nome("Baptornis");
    carta_d[25].set_tipo("D2");
    carta_d[25].set_altura(0.80);
    carta_d[25].set_peso(1.00);
    carta_d[25].set_comprimento(7);
    carta_d[25].set_viveu_ha(83);
    carta_d[25].set_super_trunfo(false);

    carta_d[26].set_nome("Alosauro");
    carta_d[26].set_tipo("D3");
    carta_d[26].set_altura(5.20);
    carta_d[26].set_peso(14.00);
    carta_d[26].set_comprimento(3600);
    carta_d[26].set_viveu_ha(156);
    carta_d[26].set_super_trunfo(false);

    carta_d[27].set_nome("Iberomesornis");
    carta_d[27].set_tipo("D4");
    carta_d[27].set_altura(0.20);
    carta_d[27].set_peso(0.10);
    carta_d[27].set_comprimento(0.03);
    carta_d[27].set_viveu_ha(125);
    carta_d[27].set_super_trunfo(false);

    carta_d[28].set_nome("Dilofossauro");
    carta_d[28].set_tipo("D5");
    carta_d[28].set_altura(2.50);
    carta_d[28].set_peso(7.00);
    carta_d[28].set_comprimento(450);
    carta_d[28].set_viveu_ha(206);
    carta_d[28].set_super_trunfo(false);

    carta_d[29].set_nome("Hylaeossauro");
    carta_d[29].set_tipo("D6");
    carta_d[29].set_altura(1.80);
    carta_d[29].set_peso(5.00);
    carta_d[29].set_comprimento(1500);
    carta_d[29].set_viveu_ha(130);
    carta_d[29].set_super_trunfo(false);

    carta_d[30].set_nome("Compsognato");
    carta_d[30].set_tipo("D7");
    carta_d[30].set_altura(0.70);
    carta_d[30].set_peso(1.00);
    carta_d[30].set_comprimento(2);
    carta_d[30].set_viveu_ha(156);
    carta_d[30].set_super_trunfo(false);

    carta_d[31].set_nome("Globidens");
    carta_d[31].set_tipo("D8");
    carta_d[31].set_altura(1.10);
    carta_d[31].set_peso(6.00);
    carta_d[31].set_comprimento(400);
    carta_d[31].set_viveu_ha(150);
    carta_d[31].set_super_trunfo(false);
}

void Dinossauro::embaralhar_cartasD() {
    srand(time(0));
    std::random_shuffle(&carta_d[0], &carta_d[31]);
    std::cout << ">>> Cartas Embaralhadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Dinossauro::inicializar_pilhas_d() {
    for (int i = 0; i < 32 / 2; i++){
        stack_1d.push(carta_d[i]);
    }
    for (int i = 32 / 2; i < 32; i++){
        stack_2d.push(carta_d[i]);
    }

    std::cout << ">>> Pilhas de Cartas Montadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Dinossauro::jogard() {
    int rodada = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    while(!stack_1d.empty() && !stack_2d.empty()) {

        system("clear");
        std::cout << std::endl << ">>> Placar <<<" << std::endl;
        std::cout << "P1 - " << stack_1d.size() << " Cartas" << " x " << stack_2d.size() << " Cartas - " << "P2"<< std::endl;
        std::cout << "Rodada: " << rodada++ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        if (player_atual == 1)
            jogada_playerD(&stack_1d, &stack_2d);
        else
            jogada_playerD(&stack_2d, &stack_1d);

        std::this_thread::sleep_for(std::chrono::milliseconds(5500));
    }

    if (stack_1d.empty())
        std::cout << std::endl << "FIM DE JOGO - PLAYER 2 VENCEU!!!" << std::endl << std::endl;
    else
        std::cout << std::endl << "FIM DE JOGO - PLAYER 1 VENCEU!!!" << std::endl << std::endl;

    std::cout << "Total de Rodadas: " << rodada;
}