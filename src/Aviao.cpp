#include "Aviao.h"
#include <iostream>
#include <string>

Aviao carta[32];

int Aviao::get_peso(){
	return peso;
}

int Aviao::get_velocidade(){
	return velocidade;
}

int Aviao::get_altitude_voo(){
	return altitude_voo;
}

float Aviao::get_comprimento(){
	return comprimento;
}

float Aviao::get_altura(){
	return altura;
}
bool Aviao::get_super_trunfo(){
	return super_trunfo;
}

void Aviao::imprime_carta (){
	std::cout << "##########CARTA##########" << std::endl;
	std::cout << "Nome: " << get_nome() << std::endl;
	std::cout << "Tipo: " << get_tipo() << std::endl << std::endl;
	std::cout << "1 Peso: " << get_peso() << " kg" << std::endl;
	std::cout << "2 Velocidade: " << get_velocidade() << " km/h" << std::endl;
	std::cout << "3 Altitude Voo: " << get_altitude_voo() << " pes" << std::endl;
	std::cout << "4 Comprimento: " << get_comprimento() << " m" << std::endl;
	std::cout << "5 Altura: " << get_altura() << " m" << std::endl;
	std::cout << "#########################" << std::endl << std::endl;
}

void Aviao::set_peso(int peso){
	this-> peso = peso;
}
void Aviao::set_velocidade(int velocidade){
	this-> velocidade = velocidade;
}
void Aviao::set_altitude_voo(int altitude_voo){
	this-> altitude_voo = altitude_voo;
}
void Aviao::set_comprimento(float comprimento){
	this-> comprimento = comprimento;
}
void Aviao::set_altura(float altura){
	this-> altura = altura;
}
void Aviao::set_super_trunfo(bool super_trunfo){
	this-> super_trunfo = super_trunfo;
}

void Aviao::inverte_pilha(std::stack<Aviao> *pilha) {
    std::stack<Aviao> stack_temp_1;
    std::stack<Aviao> stack_temp_2;

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

int Aviao::compara_cartas(Aviao carta1, Aviao carta2, std::string atributo) {
    if (atributo.compare("1") == 0) {
        if ((carta1.get_peso() - carta2.get_peso()) != 0)
            return carta1.get_peso() - carta2.get_peso();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("2") == 0) {
        if ((carta1.get_velocidade() - carta2.get_velocidade()) != 0)
            return carta1.get_velocidade() - carta2.get_velocidade();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("3") == 0) {
        if ((carta1.get_altitude_voo() - carta2.get_altitude_voo()) != 0)
            return carta1.get_altitude_voo() - carta2.get_altitude_voo();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());

    }
    else if (atributo.compare("4") == 0) {
        if ((carta1.get_comprimento() - carta2.get_comprimento()) != 0)
            return carta1.get_comprimento() - carta2.get_comprimento();
        else
            return carta2.get_tipo().compare(carta1.get_tipo());
    }
    else if (atributo.compare("5") == 0) {
    	if ((carta1.get_altura() - carta2.get_altura()) != 0)
      		return carta1.get_altura() - carta2.get_altura();
        else
          	return carta2.get_tipo().compare(carta1.get_tipo());
    }

    return 0;
}

void Aviao::jogada_player(std::stack<Aviao> *pilha_jogador, std::stack<Aviao> *pilha_adversario) {
    Aviao carta_jogador = pilha_jogador->top();
    Aviao carta_adversario = pilha_adversario->top();

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

            Aviao temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilha(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            pilha_jogador->pop();
            inverte_pilha(pilha_adversario);
            player_atual = player_adversario;
        }else {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;
            
            Aviao temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilha(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilha(pilha_jogador);
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

        if(compara_cartas(carta_jogador, carta_adversario, atributo) > 0) {
            std::cout << std::endl << "[PLAYER " << player_atual << " Vencedor da Rodada]" << std::endl;
                
            Aviao temp = pilha_jogador->top();
            pilha_jogador->pop();
            inverte_pilha(pilha_jogador);
            pilha_jogador->push(pilha_adversario->top());
            pilha_jogador->push(temp);
            inverte_pilha(pilha_jogador);
            pilha_adversario->pop();
        }else {
            std::cout << std::endl << "[PLAYER " << player_adversario << " Vencedor da Rodada]" << std::endl;
                
            Aviao temp = pilha_adversario->top();
            pilha_adversario->pop();
            inverte_pilha(pilha_adversario);
            pilha_adversario->push(pilha_jogador->top());
            pilha_adversario->push(temp);
            inverte_pilha(pilha_adversario);
            pilha_jogador->pop();
            player_atual = player_adversario;
        }
    }
}

void Aviao::cartas_aviao() {
    carta[0].set_nome("Cessna Citation X");
    carta[0].set_tipo("A1");
    carta[0].set_peso(16193);
    carta[0].set_velocidade(945);
    carta[0].set_altitude_voo(13636);
    carta[0].set_comprimento(22.01);
    carta[0].set_altura(5.76);
    carta[0].set_super_trunfo(false);

    carta[1].set_nome("Canadair Global Express");
    carta[1].set_tipo("A2");
    carta[1].set_peso(41275);
    carta[1].set_velocidade(880);
    carta[1].set_altitude_voo(15500);
    carta[1].set_comprimento(30.20);
    carta[1].set_altura(7.50);
    carta[1].set_super_trunfo(false);

    carta[2].set_nome("Bombardier CRJ 700");
    carta[2].set_tipo("A3");
    carta[2].set_peso(32885);
    carta[2].set_velocidade(785);
    carta[2].set_altitude_voo(10600);
    carta[2].set_comprimento(32.41);
    carta[2].set_altura(7.32);
    carta[2].set_super_trunfo(false);

    carta[3].set_nome("Boeing 757-300");
    carta[3].set_tipo("A4");
    carta[3].set_peso(122472);
    carta[3].set_velocidade(800);
    carta[3].set_altitude_voo(11200);
    carta[3].set_comprimento(54.50);
    carta[3].set_altura(13.60);
    carta[3].set_super_trunfo(false);

    carta[4].set_nome("Airbus A340-600");
    carta[4].set_tipo("A5");
    carta[4].set_peso(365000);
    carta[4].set_velocidade(857);
    carta[4].set_altitude_voo(11820);
    carta[4].set_comprimento(63.45);
    carta[4].set_altura(17.80);
    carta[4].set_super_trunfo(false);

    carta[5].set_nome("DC-8_73F");
    carta[5].set_tipo("A6");
    carta[5].set_peso(161000);
    carta[5].set_velocidade(880);
    carta[5].set_altitude_voo(11600);
    carta[5].set_comprimento(57.10);
    carta[5].set_altura(13.10);
    carta[5].set_super_trunfo(false);

    carta[6].set_nome("Airbus A300-600AT");
    carta[6].set_tipo("A7");
    carta[6].set_peso(150000);
    carta[6].set_velocidade(780);
    carta[6].set_altitude_voo(10000);
    carta[6].set_comprimento(56.16);
    carta[6].set_altura(17.25);
    carta[6].set_super_trunfo(false);

    carta[7].set_nome("Dassault 'Rafale'");
    carta[7].set_tipo("A8");
    carta[7].set_peso(22500);
    carta[7].set_velocidade(2350);
    carta[7].set_altitude_voo(16775);
    carta[7].set_comprimento(15.27);
    carta[7].set_altura(5.34);
    carta[7].set_super_trunfo(false);

    carta[8].set_nome("Swearingen SJ 30");
    carta[8].set_tipo("B1");
    carta[8].set_peso(5580);
    carta[8].set_velocidade(825);
    carta[8].set_altitude_voo(13100);
    carta[8].set_comprimento(12.09);
    carta[8].set_altura(3.94);
    carta[8].set_super_trunfo(false);

    carta[9].set_nome("Gulfstream G 1159-V");
    carta[9].set_tipo("B2");
    carta[9].set_peso(40370);
    carta[9].set_velocidade(830);
    carta[9].set_altitude_voo(15500);
    carta[9].set_comprimento(29.40);
    carta[9].set_altura(7.70);
    carta[9].set_super_trunfo(false);

    carta[10].set_nome("British Aerospace 146-200");
    carta[10].set_tipo("B3");
    carta[10].set_peso(42185);
    carta[10].set_velocidade(730);
    carta[10].set_altitude_voo(9600);
    carta[10].set_comprimento(28.55);
    carta[10].set_altura(8.61);
    carta[10].set_super_trunfo(false);

    carta[11].set_nome("Airbus A319-100");
    carta[11].set_tipo("B4");
    carta[11].set_peso(64000);
    carta[11].set_velocidade(803);
    carta[11].set_altitude_voo(11820);
    carta[11].set_comprimento(33.84);
    carta[11].set_altura(11.76);
    carta[11].set_super_trunfo(false);

    carta[12].set_nome("Boeing 747-400");
    carta[12].set_tipo("B5");
    carta[12].set_peso(396900);
    carta[12].set_velocidade(920);
    carta[12].set_altitude_voo(10600);
    carta[12].set_comprimento(70.70);
    carta[12].set_altura(19.30);
    carta[12].set_super_trunfo(false);

    carta[13].set_nome("Airbus A310 200F");
    carta[13].set_tipo("B6");
    carta[13].set_peso(142000);
    carta[13].set_velocidade(840);
    carta[13].set_altitude_voo(11200);
    carta[13].set_comprimento(46.66);
    carta[13].set_altura(15.81);
    carta[13].set_super_trunfo(false);
    
    carta[14].set_nome("Ilyushin IL-76MF");
    carta[14].set_tipo("B7");
    carta[14].set_peso(210000);
    carta[14].set_velocidade(780);
    carta[14].set_altitude_voo(13100);
    carta[14].set_comprimento(53.19);
    carta[14].set_altura(14.45);
    carta[14].set_super_trunfo(false);

    carta[15].set_nome("Sukhoi S-37");
    carta[15].set_tipo("B8");
    carta[15].set_peso(17700);
    carta[15].set_velocidade(2350);
    carta[15].set_altitude_voo(17900);
    carta[15].set_comprimento(21.90);
    carta[15].set_altura(6.40);
    carta[15].set_super_trunfo(false);

    carta[16].set_nome("IAI 1124 'Westwind'");
    carta[16].set_tipo("C1");
    carta[16].set_peso(10375);
    carta[16].set_velocidade(858);
    carta[16].set_altitude_voo(12500);
    carta[16].set_comprimento(15.93);
    carta[16].set_altura(4.81);
    carta[16].set_super_trunfo(false);

    carta[17].set_nome("Dassault Falcon 2000");
    carta[17].set_tipo("C2");
    carta[17].set_peso(16250);
    carta[17].set_velocidade(878);
    carta[17].set_altitude_voo(15500);
    carta[17].set_comprimento(20.23);
    carta[17].set_altura(6.98);
    carta[17].set_super_trunfo(false);

    carta[18].set_nome("Bombardier CRJ 900");
    carta[18].set_tipo("C3");
    carta[18].set_peso(360000);
    carta[18].set_velocidade(790);
    carta[18].set_altitude_voo(10600);
    carta[18].set_comprimento(36.27);
    carta[18].set_altura(7.29);
    carta[18].set_super_trunfo(false);

    carta[19].set_nome("Yakoklev YAK-42");
    carta[19].set_tipo("C4");
    carta[19].set_peso(56500);
    carta[19].set_velocidade(750);
    carta[19].set_altitude_voo(9050);
    carta[19].set_comprimento(36.38);
    carta[19].set_altura(9.83);
    carta[19].set_super_trunfo(false);

    carta[20].set_nome("Concorde");
    carta[20].set_tipo("C5");
    carta[20].set_peso(185065);
    carta[20].set_velocidade(2170);
    carta[20].set_altitude_voo(15550);
    carta[20].set_comprimento(62.17);
    carta[20].set_altura(12.19);
    carta[20].set_super_trunfo(true);

    carta[21].set_nome("Boeing 757-200PF");
    carta[21].set_tipo("C6");
    carta[21].set_peso(115650);
    carta[21].set_velocidade(860);
    carta[21].set_altitude_voo(11600);
    carta[21].set_comprimento(47.30);
    carta[21].set_altura(13.60);
    carta[21].set_super_trunfo(false);

    carta[22].set_nome("Boeing 747-100");
    carta[22].set_tipo("C7");
    carta[22].set_peso(340200);
    carta[22].set_velocidade(920);
    carta[22].set_altitude_voo(10600);
    carta[22].set_comprimento(70.70);
    carta[22].set_altura(19.30);
    carta[22].set_super_trunfo(false);

    carta[23].set_nome("AMX International");
    carta[23].set_tipo("C8");
    carta[23].set_peso(13000);
    carta[23].set_velocidade(849);
    carta[23].set_altitude_voo(12900);
    carta[23].set_comprimento(13.23);
    carta[23].set_altura(3.75);
    carta[23].set_super_trunfo(false);

    carta[24].set_nome("Beech Beechjet 400");
    carta[24].set_tipo("D1");
    carta[24].set_peso(7309);
    carta[24].set_velocidade(850);
    carta[24].set_altitude_voo(11800);
    carta[24].set_comprimento(14.80);
    carta[24].set_altura(4.50);
    carta[24].set_super_trunfo(false);

    carta[25].set_nome("Yakoklev YAK-40");
    carta[25].set_tipo("D2");
    carta[25].set_peso(16000);
    carta[25].set_velocidade(550);
    carta[25].set_altitude_voo(10000);
    carta[25].set_comprimento(20.36);
    carta[25].set_altura(6.50);
    carta[25].set_super_trunfo(false);

    carta[26].set_nome("Fairchild 329 Jet");
    carta[26].set_tipo("D3");
    carta[26].set_peso(15200);
    carta[26].set_velocidade(720);
    carta[26].set_altitude_voo(7000);
    carta[26].set_comprimento(21.28);
    carta[26].set_altura(7.20);
    carta[26].set_super_trunfo(false);

    carta[27].set_nome("Airbus A330-300");
    carta[27].set_tipo("D4");
    carta[27].set_peso(230000);
    carta[27].set_velocidade(846);
    carta[27].set_altitude_voo(11820);
    carta[27].set_comprimento(63.70);
    carta[27].set_altura(16.84);
    carta[27].set_super_trunfo(false);

    carta[28].set_nome("Airbus A3XX-200");
    carta[28].set_tipo("D5");
    carta[28].set_peso(583000);
    carta[28].set_velocidade(850);
    carta[28].set_altitude_voo(11820);
    carta[28].set_comprimento(78.90);
    carta[28].set_altura(24.10);
    carta[28].set_super_trunfo(false);

    carta[29].set_nome("Boeing 767-300F (ER)");
    carta[29].set_tipo("D6");
    carta[29].set_peso(186850);
    carta[29].set_velocidade(860);
    carta[29].set_altitude_voo(10600);
    carta[29].set_comprimento(55.00);
    carta[29].set_altura(15.90);
    carta[29].set_super_trunfo(false);

    carta[30].set_nome("Antonov An-225");
    carta[30].set_tipo("D7");
    carta[30].set_peso(600000);
    carta[30].set_velocidade(820);
    carta[30].set_altitude_voo(10000);
    carta[30].set_comprimento(84.00);
    carta[30].set_altura(18.10);
    carta[30].set_super_trunfo(false);

    carta[31].set_nome("Saab JA39 'Gripen'");
    carta[31].set_tipo("D8");
    carta[31].set_peso(13000);
    carta[31].set_velocidade(1700);
    carta[31].set_altitude_voo(18000);
    carta[31].set_comprimento(14.10);
    carta[31].set_altura(4.70);
    carta[31].set_super_trunfo(false);
}

void Aviao::embaralhar_cartas() {
    srand(time(0));
    std::random_shuffle(&carta[0], &carta[31]);
    std::cout << ">>> Cartas Embaralhadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Aviao::inicializar_pilhas() {
    for (int i = 0; i < 32 / 2; i++){
        stack_1.push(carta[i]);
    }
    for (int i = 32 / 2; i < 32; i++){
        stack_2.push(carta[i]);
    }

    std::cout << ">>> Pilhas de Cartas Montadas" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Aviao::jogar() {
    int rodada = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    while(!stack_1.empty() && !stack_2.empty()) {

        system("clear");
        std::cout << std::endl << ">>> Placar <<<" << std::endl;
        std::cout << "P1 - " << stack_1.size() << " Cartas" << " x " << stack_2.size() << " Cartas - " << "P2"<< std::endl;
        std::cout << "Rodada: " << rodada++ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        if (player_atual == 1)
            jogada_player(&stack_1, &stack_2);
        else
            jogada_player(&stack_2, &stack_1);

        std::this_thread::sleep_for(std::chrono::milliseconds(5500));
    }

    if (stack_1.empty())
        std::cout << std::endl << "FIM DE JOGO - PLAYER 2 VENCEU!!!" << std::endl << std::endl;
    else
        std::cout << std::endl << "FIM DE JOGO - PLAYER 1 VENCEU!!!" << std::endl << std::endl;

    std::cout << "Total de Rodadas: " << rodada;
}