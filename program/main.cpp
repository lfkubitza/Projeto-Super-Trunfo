#include <iostream>
#include <string>
#include <stack>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>

#include "Aviao.h"
#include "Carro.h"
#include "Dinossauro.h"
#include "Heroi.h"
#include "Cartas.h"

const int num_cartas = 32;

Aviao aviao;
Carro carro;
Dinossauro dinossauro;
Heroi heroi;

void cartas_aviao();
void embaralhar_cartas();
void inicializar_pilhas();
void jogar();

void cartas_carro();
void embaralhar_cartasC();
void inicializar_pilhas_c();
void jogarc();

void cartas_dinossauro();
void embaralhar_cartasD();
void inicializar_pilhas_d();
void jogard();

void cartas_heroi();
void embaralhar_cartasH();
void inicializar_pilhas_h();
void jogarh();

int main() {

    for(;;) {
        int x = 0;
        std::cout << "Escolha uma opcao: " << std::endl;
        std::cout << "1 - Baralho Aviao" << std::endl;
        std::cout << "2 - Baralho Carro" << std::endl;
        std::cout << "3 - Baralho Dinossauro" << std::endl;
        std::cout << "4 - Baralho Heroi" << std::endl;
        std::cout << "5 - Regras" << std::endl << std::endl;
        std::cout << "OPCAO: ";
        std::cin >> x;

        switch(x){
        case 1:
            std::cout << "Super Trunfo Aviao!" << std::endl;

            aviao.cartas_aviao();
            aviao.embaralhar_cartas();
            aviao.inicializar_pilhas();
            aviao.jogar();

            break;
        case 2:
            std::cout << "Super Trunfo Carro!" << std::endl;
            
            carro.cartas_carro();
            carro.embaralhar_cartasC();
            carro.inicializar_pilhas_c();
            carro.jogarc();

            break;
        case 3:
            std::cout << "Super Trunfo Dinossauro!" << std::endl;
            
            dinossauro.cartas_dinossauro();
            dinossauro.embaralhar_cartasD();
            dinossauro.inicializar_pilhas_d();
            dinossauro.jogard();

            break;
        case 4:
            std::cout << "Super Trunfo Heroi!" << std::endl;
            
            heroi.cartas_heroi();
            heroi.embaralhar_cartasH();
            heroi.inicializar_pilhas_h();
            heroi.jogarh();

            break;
        case 5:
            std::cout << "Super Trunfo Regras!" << std::endl;
            std::cout << "1. Observe em cada carta qual valor vence em cada rodada: o maior ou o menor" << std::endl;
            std::cout << "2. Para iniciar, escolha entre as informações da sua carta, aquela que você julga" << std::endl;
            std::cout << "   ter o valor capaz de vencer as cartas dos seus adversários." << std::endl;
            std::cout << "3. Se você vencer - as cartas dos outros jogadores irão para trás do seu monte de" << std::endl;
            std::cout << "   cartas e você continua escolhendo a informação da sua próxima carta." << std::endl;
            std::cout << "4. Se outro jogador vencer - as cartas irão para trás do monte de cartas dele e a" << std::endl; 
            std::cout << "   vez de escolher passa para ele." << std::endl;
            std::cout << "5. Em caso de empate - as cartas irão para o monte e as próximas cartas - sua e dos" << std::endl;
            std::cout << "   seus adversários - aparecem. Uma nova disputa é feita sendo que o jogador que " << std::endl; 
            std::cout << "   escolheu as cartas que empataram deve escolher novamente." << std::endl;
            std::cout << "6. Existe entre as cartas uma carta SUPER TRUNFO. Esta carta vence todas as cartas do" << std::endl; 
            std::cout << "   baralho independentemente do valor de suas características. Ela perde apenas para as" << std::endl;
            std::cout << "   cartas que tenham a letra A (1A, 2A, 3A, etc), marcado na parte superior de cada uma." << std::endl;
            std::cout << "7. Quando a carta SUPER TRUNFO aparecer, a comparação será automática com as cartas dos adversários." << std::endl;
            std::cout << "8. O jogo termina quando um dos jogadores ganhar todas as cartas do baralho." << std::endl << std::endl;
            
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    }
    
	return 0;
}
