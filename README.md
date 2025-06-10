<h1>Super Trunfo</h1>
Implementação, em C++ , do jogo Super Trunfo via terminal. Sendo possível quatro modos de jogo, porém ambos serão jogador x máquina.

<h1>Userstories</h1>

<ul>
  <li>Como um jogador eu gostaria de escolher uma modalidade de Super Trunfo para jogar;</li>
  <li>Como um jogador eu gostaria de ver todas as regras do jogo com determinado comando;</li>
  <li>Como um jogador eu quero que o placar e a pilha de cartas estejam explícitos a todo o momento do jogo;</li>
  <li>Como um jogador eu quero a funcionalidade de interromper o jogo a qualquer momento;</li>
  <li>Como um jogador eu quero que uma carta super trunfo esteja no meu baralho;</li>
  <li>Como um jogador eu quero que na minha vez, eu escolha o atributo do card que deve ser comparado na rodada;</li>
  <li>Como a classe game eu quero garantir a comparação de atributos entre cards para escolher o vencedor da rodada.</li>
</ul>

<h1>Cartões CRC</h1>

<table style="width: 406px; height: 116px;">
<tbody>
<tr>
<td style="width: 204px;">&nbsp;CRC</td>
<td style="width: 201px;">&nbsp;</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Nome:</td>
<td style="width: 201px;">&nbsp;Card</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Responsabilidade:</td>
<td style="width: 201px;">&nbsp;Define o TAD das cartas do jogo, e seus atributos que serão específicos em cada classe filhas.</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Colabora&ccedil;&atilde;o:</td>
<td style="width: 201px;">&nbsp;Carros, aviões, dinossauros e heróis.</td>
</tr>
</tbody>
</table>

<table style="width: 406px; height: 116px;">
<tbody>
<tr>
<td style="width: 204px;">&nbsp;CRC</td>
<td style="width: 201px;">&nbsp;</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Nome:</td>
<td style="width: 201px;">&nbsp;Jogo</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Responsabilidade:</td>
<td style="width: 201px;">&nbsp;Contém os métodos para rodar o jogo.</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Colabora&ccedil;&atilde;o:</td>
<td style="width: 201px;">&nbsp;Carros, aviões, dinossauros e heróis.</td>
</tr>
</tbody>
</table>

<table style="width: 406px; height: 116px;">
<tbody>
<tr>
<td style="width: 204px;">&nbsp;CRC</td>
<td style="width: 201px;">&nbsp;</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Nome:</td>
<td style="width: 201px;">&nbsp;Carros</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Responsabilidade:</td>
<td style="width: 201px;">&nbsp;Subclasse de carta que define o tipo dos carros e seus atributos.</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Colabora&ccedil;&atilde;o:</td>
<td style="width: 201px;">&nbsp;Jogo.</td>
</tr>
</tbody>
</table>

<table style="width: 406px; height: 116px;">
<tbody>
<tr>
<td style="width: 204px;">&nbsp;CRC</td>
<td style="width: 201px;">&nbsp;</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Nome:</td>
<td style="width: 201px;">&nbsp;Avião</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Responsabilidade:</td>
<td style="width: 201px;">&nbsp;Subclasse de carta que define o tipo dos aviões e seus atributos.</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Colabora&ccedil;&atilde;o:</td>
<td style="width: 201px;">&nbsp;Jogo.</td>
</tr>
</tbody>
</table>

<table style="width: 406px; height: 116px;">
<tbody>
<tr>
<td style="width: 204px;">&nbsp;CRC</td>
<td style="width: 201px;">&nbsp;</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Nome:</td>
<td style="width: 201px;">&nbsp;Dinossauros</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Responsabilidade:</td>
<td style="width: 201px;">&nbsp;Subclasse de carta que define o tipo dos dinossauros e seus atributos.</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Colabora&ccedil;&atilde;o:</td>
<td style="width: 201px;">&nbsp;Jogo.</td>
</tr>
</tbody>
</table>

<table style="width: 406px; height: 116px;">
<tbody>
<tr>
<td style="width: 204px;">&nbsp;CRC</td>
<td style="width: 201px;">&nbsp;</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Nome:</td>
<td style="width: 201px;">&nbsp;Heróis</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Responsabilidade:</td>
<td style="width: 201px;">&nbsp;Subclasse de carta que define o tipo de herói e seus atributos.</td>
</tr>
<tr>
<td style="width: 204px;">&nbsp;Colabora&ccedil;&atilde;o:</td>
<td style="width: 201px;">&nbsp;Jogo.</td>
</tr>
</tbody>
</table>

<h1>Contribuidor</h1>

<ul>
  <li>Luiz Felipe Kubitza</li>
  
</ul>
