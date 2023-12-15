#ifndef UTILS_H
#define UTILS_H

void ImprimirVetor(int vet[], int tamanho);
void preencherVetorAleatorio(int vet[], int tamanho);
void preencherVetorOrdenado(int vet[], int tamanho) ;
void copiarVetor(int origem[], int destino[], int tamanho);
void imprimirEstatisticas(int algoritmo, int tamanho, const char *tipoVetor, int comparacoes, int trocas, double tempo);
const char *algoritmoNome(int indice);
void testarAlgoritmo(int algoritmo, int vet[], int tamanho, const char *tipoVetor, int imprimir);

#endif