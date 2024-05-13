/*
O código começa declarando um array votos para armazenar os votos de cada candidato, votos em branco e votos nulos. 
Além disso, declara as variáveis voto, i, indMaximo, totalVotos e votosValidos.
Em seguida, o código pede ao usuário para inserir a quantidade total de votos que serão recebidos.
O código apresenta as opções de voto para o usuário.
O código entra em um loop, onde recebe o voto do usuário.
 Se o voto for válido (ou seja, entre 1 e 3), o código incrementa o voto do candidato correspondente. Se for nulo,
 o voto é apenas armazenado, e se for branco, o voto é acrescentado ao candidato com maior número de votos válidos.
 Se o voto não estiver dentro das opções de voto, o código encerra a votação. O código posteriormente entra na contagem dos votos
Depois de adicionar os votos brancos ao vencedor, o código apresenta o resultado da votação,
mostrando o número de votos para cada candidato, o número de votos em branco, o número de votos nulos, 
o total de votos, o total de votos válidos e o candidato vencedor.
*/
#include <stdio.h>

int main()
{
  int votos[5] = {0, 0, 0, 0, 0}; // Inicializa um array para armazenar os votos de cada candidato, votos em branco e votos nulos
  int voto, i = 0, indMaximo = 0, totalVotos = 0, votosValidos = 0;

  int quantidadeTotalVotos; // Quantidade total de votos
  printf("Digite a quantidade total de votos: ");
  scanf("%d", &quantidadeTotalVotos);

  printf("As opcoes sao:\n  1. Candidato 1\n  2. Candidato 2\n  3. Candidato 3\n  4. Branco\n"); // Apresenta as opções de voto

  while (totalVotos < quantidadeTotalVotos)
  { // Loop para receber votos até atingir a quantidade total
    printf("Digite o número do seu voto: ");
    scanf("%d", &voto); // Recebe o voto do usuário

    if (voto >= 1 && voto <= 3) // Verifica se o voto é para um candidato
    {
      votos[voto - 1]++; // Incrementa o voto do candidato correspondente
      totalVotos++;      // Incrementa o total de votos
      votosValidos++;    // Incrementa o total de votos válidos (não brancos) 
    }
    else if (voto == 4)// Verifica se o voto é em branco
    {                           
      votos[3]++;   // Incrementa o voto em branco
      totalVotos++; // Incrementa o total de votos
    }
    else // Qualquer outro número é considerado voto nulo
    {                           
      votos[4]++;   // Incrementa o voto nulo
      totalVotos++; // Incrementa o total de votos
    }
  ;}

  while (i < 3)
  { // Encontra o candidato com mais votos
    if (votos[i] > votos[indMaximo])
    {
      indMaximo = i;
    }
    i++;
  }
  votos[indMaximo] += votos[3]; // Adiciona os votos em branco ao candidato vencedor
  printf("Resultado da votação:\n"); // Apresenta o resultado da votação
  i = 0;
  while (i < 3)
  {
    printf("Candidato %d: %d votos\n", i + 1, votos[i]);
    i++;
  }
  printf("Votos em branco: %d\n", votos[3]);
  printf("Votos nulos: %d\n", votos[4]);
  printf("Total de votos: %d\n", totalVotos);
  printf("Total de votos válidos (não brancos): %d\n", votosValidos);
  printf("Candidato vencedor: Candidato %d\n", indMaximo + 1);
  
  return 0;
}