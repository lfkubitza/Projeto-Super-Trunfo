<h1>                                                    Mudanças no código</h1>
<h1>Modo de jogo</h1>
O modo de jogo foi alterado de player vs bot para player vs player, oque era nossa idéia inicial. Reestruturamos as funções que 
rodam o jogo a fim de trazer esse modo de jogo mais complexo para nosso game, visto que era nossa proposta inicial. Agora após a 
escolha do  baralho o player 1 escolhe o primeiro atributo, e quem vence a rodada escolhe o atributo da fase seguinte.

<h1>Modularização</h1>
 Uma das principais mudanças no nosso código foi em relação a modularização, anteriormente nosso main tinha aproximadamente 2000 
 linhas, agora as funções e os atributos estão setados em classes fora do main, tais como carta.h, avião.h... e o main apenas 
 recebe o include de todos os arquivos e executa um try/catch, um cin e um switch para poder rodar o jogo, assim assumindo 
 118 linhas na versão final.

<h1>Documentação</h1>
Foi adicionada uma documentação referente ao nosso projeto no arquivo do github, na apresentação do dia 26(terça) nosso projeto não 
havia documentação.


<h1>Tratamento de exceção</h1>
Foi adicionado tratamento de exceção no nosso projeto, que na apresentação do dia 26 também não havia. Como nosso projeto é um jogo,
tivemos limitados espaços para criar as exceções, visto que o código está todo escrito em forma de programação defensiva para todas
as entradas do usuário, ou seja, se tratando de um jogo as exceções foram criadas de forma que os atributos digitados pelo usuário
na hora da execução do jogo não assumisse  valores inválidos, para isso usamos tratamentos de exceção com try e catch, e usamos 
também o switch para determinadas entradas dos usuários.

<h1>Testes</h1>
Foram adicionados testes no nosso projeto, que na apresentação do dia 26 também não havia. Como nosso projeto é um jogo, a maioria 
das funções são para executar o jogo, logo a área de cobertura de possíveis testes foi reduzida devido a complexidade das funções 
que rodam o game.


