#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCHAVE 30
#define TAMMENSAGEM 1000

void pedir_chave(char *chave, int *tamanho) {
    printf("Digite a chave: ");
    scanf(" %29[^\n]s", chave);
    *tamanho = strlen(chave);
}

void inserir_mensagem(char *mensagem, int *tamanho) {
    int repete = 0;
    do {
        repete = 0;
        printf("Digite a mensagem: ");
        scanf(" %999[^\n]s", mensagem);
        if (strlen(mensagem) > TAMMENSAGEM) {
            repete = 1;
        }
    } while (repete != 0);
    *tamanho = strlen(mensagem);
}

void imprimir(char *mensagem, char *chave) {
    printf("------------- Chave -------------\n");
    printf("%s\n", chave);
    printf("------------- Mensagem -------------\n");
    printf("%s\n", mensagem);
    printf("----------------------------------\n");
}

int converterParaAscii(char letra) {
    return (int)letra;
}

int converterDeAscii(int numero) {
    return (char)numero;
}

void criaVetorAscii(char *chave, char *mensa, int tam1, int tam2, int *ChAscii, int *menAscii){
    int i;
    for ( i = 0; i < tam1; i++){
        ChAscii[i] = converterParaAscii(chave[i]);
    }
    for (i = 0; i < tam2; i++){
        menAscii[i] = converterParaAscii(mensa[i]);
    }
}

void transformaString(int *mensagemAscii, char *mensagemCripto, int tam){
    int i;
    for (i = 0; i < tam; i++){
        mensagemCripto[i] = converterDeAscii(mensagemAscii[i]);
    }
}

void criptografar(char *chave, char *mensagem, int tam_chave, int tam_mensagem, char* cripto){
    int i, j = 0;
    int chaveAscii[tam_chave];
    int mensagemAscii[tam_mensagem];
    criaVetorAscii(chave,mensagem,tam_chave,tam_mensagem,chaveAscii,mensagemAscii);
    for (i = 0; i < tam_mensagem; i++){
        if (j == tam_chave){
            j = 0;
        }else{
            mensagemAscii[i] += chaveAscii[j];
            j++;
        }
    }
    transformaString(mensagemAscii,cripto,tam_mensagem);
}

void descriptografar(char *chave, char *mensagem, int tam_chave, int tam_mensagem, char *descripto) {
    int i, j = 0;
    int chaveAscii[tam_chave];
    int mensagemAscii[tam_mensagem];
    criaVetorAscii(chave,mensagem,tam_chave,tam_mensagem,chaveAscii,mensagemAscii);
    for (i = 0; i < tam_mensagem; i++){
        if (j == tam_chave){
            j = 0;
        }else{
            mensagemAscii[i] -= chaveAscii[j];
            j++;
        }
    }
    transformaString(mensagemAscii,descripto,tam_mensagem);
}


int main() {
    int tamanho_chave;
    int tamanho_mensagem;
    char chave[TAMCHAVE];
    char mensagem[TAMMENSAGEM];

    pedir_chave(chave, &tamanho_chave);
    inserir_mensagem(mensagem, &tamanho_mensagem);

    char mensagem_criptografada[TAMMENSAGEM];
    char mensagem_descriptografada[TAMMENSAGEM];

    criptografar(chave, mensagem, tamanho_chave, tamanho_mensagem, mensagem_criptografada);
    imprimir(mensagem_criptografada, chave);

    descriptografar(chave, mensagem_criptografada, tamanho_chave, tamanho_mensagem, mensagem_descriptografada);
    imprimir(mensagem_descriptografada, chave);

    return 0;
}
