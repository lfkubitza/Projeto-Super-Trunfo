#include "Carro.h"
#include <iostream>
#include <string>

Carro carta_c[32];

int Carro::get_cilindradas(){
	return cilindradas;
}

int Carro::get_potencia(){
	return potencia;
}

int Carro::get_velocidade(){
	return velocidade;
}

int Carro::get_peso(){
	return peso;
}

float Carro::get_comprimento(){
	return comprimento;
}

bool Carro::get_super_trunfo(){
	return super_trunfo;
}

void Carro::imprime_carta(){
	std::cout << "##########CARTA##########" << std::endl;
	std::cout << "Nome: " << get_nome() << std::endl;
	std::cout << "Tipo: " << get_tipo() << std::endl << std::endl;
	std::cout << "1 Cilindradas: " << get_cilindradas() << " ccm" << std::endl;
	std::cout << "2 Potência: " << get_potencia() << " cv" << std::endl;
	std::cout << "3 Velocidade: " << get_velocidade() << " km/h" << std::endl;
	std::cout << "4 Peso: " << get_peso() << " kg" << std::endl;
	std::cout << "5 Comprimento: " << get_comprimento() << " m" << std::endl;
	std::cout << "#########################" << std::endl << std::endl;
}

void Carro::set_cilindradas(int cilindradas){
	this-> cilindradas = cilindradas;
}

void Carro::set_potencia(int potencia){
	this-> potencia = potencia;
}

void Carro::set_velocidade(int velocidade){
	this-> velocidade = velocidade;
}

void Carro::set_peso(int peso){
	this-> peso = peso;
}

void Carro::set_comprimento(float comprimento){
	this-> comprimento = comprimento;
}

void Carro::set_super_trunfo(bool super_trunfo){
	this-> super_trunfo = super_trunfo;
}

void Carro::inverte_pilhaC(std::stack<Carro> *pilha) {
    std::stack<Carro> stack_temp_1;
    std::stack<Carro> stack_temp_2;

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

int Carro::compara_cartasC(Carro carta1, Carro carta2, std::string atributo) {
    if (atributo.compare("1") == 0) {
        if ((carta1.get_cilindradas() - carta2.get_cilindradas()) != 0)
            return carta1.get_cilindradas() - carta2.get_cilindradas();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("2") == 0) {
        if ((carta1.get_potencia() - carta2.get_potencia()) != 0)
            return carta1.get_potencia() - carta2.get_potencia();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("3") == 0) {
        if ((carta1.get_velocidade() - carta2.get_velocidade()) != 0)
            return carta1.get_velocidade() - carta2.get_velocidade();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());

    }
    else if (atributo.compare("4") == 0) {
        if ((carta1.get_peso() - carta2.get_peso()) != 0)
            return carta1.get_peso() - carta2.get_peso();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("5") == 0) {
        if ((carta1.get_comprimento() - carta2.get_comprimento()) != 0)
            return carta1.get_comprimento() - carta2.get_comprimento();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }

    return 0;
}

void Carro::jogada_playerC(std::stack<Carro> *pilha_jogador, std::stack<Carro> *pilha_adversario) {
    Carro carta_jogador = pilha_jogador->top();
    Carro carta_adversario = pilha_adversario->top();

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

            Carro temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaC(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            pilha_jogador->pop();
            inverte_pilhaC(pilha_adversario);
            player_atual = player_adversario;
        }else {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;
            
            Carro temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaC(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaC(pilha_jogador);
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

        if(compara_cartasC(carta_jogador, carta_adversario, atributo) > 0) {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;
                
            Carro temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilhaC(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilhaC(pilha_jogador);
            pilha_adversario->pop();
        }else {
            std::cout << std::endl << "[PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;
                
            Carro temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilhaC(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            inverte_pilhaC(pilha_adversario);
            pilha_jogador->pop();
            player_atual = player_adversario;
        }
    }
}

void Carro::cartas_carro(){
    carta_c[0].set_nome("Maserati 'Assetto Corsa'");
    carta_c[0].set_tipo("A1");
    carta_c[0].set_cilindradas(3217);
    carta_c[0].set_potencia(369);
    carta_c[0].set_velocidade(280);
    carta_c[0].set_peso(1590);
    carta_c[0].set_comprimento(4.51);
    carta_c[0].set_super_trunfo(false);

    carta_c[1].set_nome("Rolls-Royce Park Ward");
    carta_c[1].set_tipo("A2");
    carta_c[1].set_cilindradas(5379);
    carta_c[1].set_potencia(326);
    carta_c[1].set_velocidade(225);
    carta_c[1].set_peso(2480);
    carta_c[1].set_comprimento(5.65);
    carta_c[1].set_super_trunfo(false);

    carta_c[2].set_nome("Lexus RX 300");
    carta_c[2].set_tipo("A3");
    carta_c[2].set_cilindradas(2995);
    carta_c[2].set_potencia(201);
    carta_c[2].set_velocidade(180);
    carta_c[2].set_peso(1865);
    carta_c[2].set_comprimento(4.58);
    carta_c[2].set_super_trunfo(false);

    carta_c[3].set_nome("Bugatti EB 16.4 Veyron");
    carta_c[3].set_tipo("A4");
    carta_c[3].set_cilindradas(7993);
    carta_c[3].set_potencia(1001);
    carta_c[3].set_velocidade(404);
    carta_c[3].set_peso(1380);
    carta_c[3].set_comprimento(4.38);
    carta_c[3].set_super_trunfo(false);

    carta_c[4].set_nome("VW D1");
    carta_c[4].set_tipo("A5");
    carta_c[4].set_cilindradas(6000);
    carta_c[4].set_potencia(450);
    carta_c[4].set_velocidade(250);
    carta_c[4].set_peso(1750);
    carta_c[4].set_comprimento(4.95);
    carta_c[4].set_super_trunfo(false);

    carta_c[5].set_nome("Binz XL");
    carta_c[5].set_tipo("A6");
    carta_c[5].set_cilindradas(4266);
    carta_c[5].set_potencia(279);
    carta_c[5].set_velocidade(230);
    carta_c[5].set_peso(2180);
    carta_c[5].set_comprimento(5.79);
    carta_c[5].set_super_trunfo(false);

    carta_c[6].set_nome("Pagani Zonda C12 S");
    carta_c[6].set_tipo("A7");
    carta_c[6].set_cilindradas(7010);
    carta_c[6].set_potencia(550);
    carta_c[6].set_velocidade(350);
    carta_c[6].set_peso(1250);
    carta_c[6].set_comprimento(4.40);
    carta_c[6].set_super_trunfo(false);

    carta_c[7].set_nome("Lexus LS 430");
    carta_c[7].set_tipo("A8");
    carta_c[7].set_cilindradas(4293);
    carta_c[7].set_potencia(282);
    carta_c[7].set_velocidade(250);
    carta_c[7].set_peso(1995);
    carta_c[7].set_comprimento(5.00);
    carta_c[7].set_super_trunfo(false);

    carta_c[8].set_nome("Jaguar XKR");
    carta_c[8].set_tipo("B1");
    carta_c[8].set_cilindradas(3996);
    carta_c[8].set_potencia(363);
    carta_c[8].set_velocidade(250);
    carta_c[8].set_peso(1715);
    carta_c[8].set_comprimento(4.76);
    carta_c[8].set_super_trunfo(false);

    carta_c[9].set_nome("Mercedes S 63 AMG");
    carta_c[9].set_tipo("B2");
    carta_c[9].set_cilindradas(6258);
    carta_c[9].set_potencia(444);
    carta_c[9].set_velocidade(250);
    carta_c[9].set_peso(2035);
    carta_c[9].set_comprimento(5.16);
    carta_c[9].set_super_trunfo(false);

    carta_c[10].set_nome("Mercedes ML 55 AMG");
    carta_c[10].set_tipo("B3");
    carta_c[10].set_cilindradas(5439);
    carta_c[10].set_potencia(347);
    carta_c[10].set_velocidade(235);
    carta_c[10].set_peso(2300);
    carta_c[10].set_comprimento(4.64);
    carta_c[10].set_super_trunfo(false);

    carta_c[11].set_nome("Ferrari 500 Maranello");
    carta_c[11].set_tipo("B4");
    carta_c[11].set_cilindradas(5474);
    carta_c[11].set_potencia(485);
    carta_c[11].set_velocidade(320);
    carta_c[11].set_peso(1690);
    carta_c[11].set_comprimento(4.55);
    carta_c[11].set_super_trunfo(false);

    carta_c[12].set_nome("ItalDesing Scighera");
    carta_c[12].set_tipo("B5");
    carta_c[12].set_cilindradas(3000);
    carta_c[12].set_potencia(400);
    carta_c[12].set_velocidade(310);
    carta_c[12].set_peso(1450);
    carta_c[12].set_comprimento(4.32);
    carta_c[12].set_super_trunfo(false);

    carta_c[13].set_nome("Hooper Rolls-Royce Emperor");
    carta_c[13].set_tipo("B6");
    carta_c[13].set_cilindradas(6748);
    carta_c[13].set_potencia(325);
    carta_c[13].set_velocidade(215);
    carta_c[13].set_peso(2440);
    carta_c[13].set_comprimento(5.82);
    carta_c[13].set_super_trunfo(false);

    carta_c[14].set_nome("Morgan Aero 8");
    carta_c[14].set_tipo("B7");
    carta_c[14].set_cilindradas(4398);
    carta_c[14].set_potencia(286);
    carta_c[14].set_velocidade(258);
    carta_c[14].set_peso(1000);
    carta_c[14].set_comprimento(4.09);
    carta_c[14].set_super_trunfo(false);

    carta_c[15].set_nome("BMW 745i");
    carta_c[15].set_tipo("B8");
    carta_c[15].set_cilindradas(4398);
    carta_c[15].set_potencia(333);
    carta_c[15].set_velocidade(250);
    carta_c[15].set_peso(1945);
    carta_c[15].set_comprimento(5.00);
    carta_c[15].set_super_trunfo(false);

    carta_c[16].set_nome("Porsche 911 GT2");
    carta_c[16].set_tipo("C1");
    carta_c[16].set_cilindradas(3600);
    carta_c[16].set_potencia(462);
    carta_c[16].set_velocidade(315);
    carta_c[16].set_peso(1451);
    carta_c[16].set_comprimento(4.45);
    carta_c[16].set_super_trunfo(false);

    carta_c[17].set_nome("Daimler Super V8");
    carta_c[17].set_tipo("C2");
    carta_c[17].set_cilindradas(3996);
    carta_c[17].set_potencia(363);
    carta_c[17].set_velocidade(250);
    carta_c[17].set_peso(1820);
    carta_c[17].set_comprimento(5.15);
    carta_c[17].set_super_trunfo(false);

    carta_c[18].set_nome("Range Rover");
    carta_c[18].set_tipo("C3");
    carta_c[18].set_cilindradas(4553);
    carta_c[18].set_potencia(218);
    carta_c[18].set_velocidade(196);
    carta_c[18].set_peso(2120);
    carta_c[18].set_comprimento(4.71);
    carta_c[18].set_super_trunfo(false);

    carta_c[19].set_nome("B. Engineering Edonis");
    carta_c[19].set_tipo("C4");
    carta_c[19].set_cilindradas(3760);
    carta_c[19].set_potencia(680);
    carta_c[19].set_velocidade(365);
    carta_c[19].set_peso(1300);
    carta_c[19].set_comprimento(4.35);
    carta_c[19].set_super_trunfo(false);

    carta_c[20].set_nome("Cadillac Imaj");
    carta_c[20].set_tipo("C5");
    carta_c[20].set_cilindradas(4200);
    carta_c[20].set_potencia(431);
    carta_c[20].set_velocidade(300);
    carta_c[20].set_peso(1850);
    carta_c[20].set_comprimento(5.10);
    carta_c[20].set_super_trunfo(false);

    carta_c[21].set_nome("American Custom Lincoln");
    carta_c[21].set_tipo("C6");
    carta_c[21].set_cilindradas(5409);
    carta_c[21].set_potencia(380);
    carta_c[21].set_velocidade(200);
    carta_c[21].set_peso(2870);
    carta_c[21].set_comprimento(6.40);
    carta_c[21].set_super_trunfo(false);

    carta_c[22].set_nome("Mega Monte Carlo");
    carta_c[22].set_tipo("C7");
    carta_c[22].set_cilindradas(5991);
    carta_c[22].set_potencia(395);
    carta_c[22].set_velocidade(500);
    carta_c[22].set_peso(1500);
    carta_c[22].set_comprimento(4.45);
    carta_c[22].set_super_trunfo(false);

    carta_c[23].set_nome("Cadillac Deville DTS");
    carta_c[23].set_tipo("C8");
    carta_c[23].set_cilindradas(4565);
    carta_c[23].set_potencia(305);
    carta_c[23].set_velocidade(240);
    carta_c[23].set_peso(1843);
    carta_c[23].set_comprimento(5.26);
    carta_c[23].set_super_trunfo(false);

    carta_c[24].set_nome("Aston Martin Vanquish");
    carta_c[24].set_tipo("D1");
    carta_c[24].set_cilindradas(5935);
    carta_c[24].set_potencia(460);
    carta_c[24].set_velocidade(306);
    carta_c[24].set_peso(1863);
    carta_c[24].set_comprimento(4.67);
    carta_c[24].set_super_trunfo(true);

    carta_c[25].set_nome("Bentley Continental T");
    carta_c[25].set_tipo("D2");
    carta_c[25].set_cilindradas(6750);
    carta_c[25].set_potencia(426);
    carta_c[25].set_velocidade(270);
    carta_c[25].set_peso(2450);
    carta_c[25].set_comprimento(5.22);
    carta_c[25].set_super_trunfo(false);

    carta_c[26].set_nome("BMW X5");
    carta_c[26].set_tipo("D3");
    carta_c[26].set_cilindradas(4398);
    carta_c[26].set_potencia(286);
    carta_c[26].set_velocidade(207);
    carta_c[26].set_peso(2170);
    carta_c[26].set_comprimento(4.67);
    carta_c[26].set_super_trunfo(false);

    carta_c[27].set_nome("Lamborghini Diablo");
    carta_c[27].set_tipo("D4");
    carta_c[27].set_cilindradas(5992);
    carta_c[27].set_potencia(550);
    carta_c[27].set_velocidade(330);
    carta_c[27].set_peso(1625);
    carta_c[27].set_comprimento(4.47);
    carta_c[27].set_super_trunfo(false);

    carta_c[28].set_nome("Chrysler Chronos");
    carta_c[28].set_tipo("D5");
    carta_c[28].set_cilindradas(5980);
    carta_c[28].set_potencia(350);
    carta_c[28].set_velocidade(280);
    carta_c[28].set_peso(1950);
    carta_c[28].set_comprimento(5.22);
    carta_c[28].set_super_trunfo(false);

    carta_c[29].set_nome("Maybach Langversion");
    carta_c[29].set_tipo("D6");
    carta_c[29].set_cilindradas(5600);
    carta_c[29].set_potencia(470);
    carta_c[29].set_velocidade(250);
    carta_c[29].set_peso(2450);
    carta_c[29].set_comprimento(6.10);
    carta_c[29].set_super_trunfo(false);

    carta_c[30].set_nome("Lotec Sirius");
    carta_c[30].set_tipo("D7");
    carta_c[30].set_cilindradas(5987);
    carta_c[30].set_potencia(1200);
    carta_c[30].set_velocidade(400);
    carta_c[30].set_peso(1380);
    carta_c[30].set_comprimento(4.12);
    carta_c[30].set_super_trunfo(false);

    carta_c[31].set_nome("Audi S8");
    carta_c[31].set_tipo("D8");
    carta_c[31].set_cilindradas(4172);
    carta_c[31].set_potencia(360);
    carta_c[31].set_velocidade(250);
    carta_c[31].set_peso(1730);
    carta_c[31].set_comprimento(5.03);
    carta_c[31].set_super_trunfo(false);
}

void Carro::embaralhar_cartasC() {
    srand(time(0));
    std::random_shuffle(&carta_c[0], &carta_c[31]);
    std::cout << ">>> Cartas Embaralhadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Carro::inicializar_pilhas_c() {
    for (int i = 0; i < 32 / 2; i++){
        stack_1c.push(carta_c[i]);
    }
    for (int i = 32 / 2; i < 32; i++){
        stack_2c.push(carta_c[i]);
    }

    std::cout << ">>> Pilhas de Cartas Montadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Carro::jogarc() {
    int rodada = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    while(!stack_1c.empty() && !stack_2c.empty()) {

        system("clear");
        std::cout << std::endl << ">>> Placar <<<" << std::endl;
        std::cout << "P1 - " << stack_1c.size() << " Cartas" << " x " << stack_2c.size() << " Cartas - " << "P2"<< std::endl;
        std::cout << "Rodada: " << rodada++ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        if (player_atual == 1)
            jogada_playerC(&stack_1c, &stack_2c);
        else
            jogada_playerC(&stack_2c, &stack_1c);

        std::this_thread::sleep_for(std::chrono::milliseconds(5500));
    }

    if (stack_1c.empty())
        std::cout << std::endl << "FIM DE JOGO - PLAYER 2 VENCEU!!!" << std::endl << std::endl;
    else
        std::cout << std::endl << "FIM DE JOGO - PLAYER 1 VENCEU!!!" << std::endl << std::endl;

    std::cout << "Total de Rodadas: " << rodada;
}