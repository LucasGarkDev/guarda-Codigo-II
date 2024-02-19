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

int converterParaAscii(char letra){ 
    return (int)letra; 
}

int converterDeAscii(int numero){ 
    return (char)numero; 
}

void criptografar(char *chave, char *mensagem_criptografada, int tam_chave, int tam_mensagem) {
    int i, j, num_tabela;
    int k = 0;
    char letra_chave;
    for (i = 0; i < tam_mensagem; i++) {
        if (j == tam_chave - 1) {
            j = 0;
        } else {
            letra_chave = chave[j];
            num_tabela = converterParaAscii(letra_chave);
            j++;
        }
        mensagem_criptografada[k] = num_tabela + i;
        k++;
    }
}

void descriptografar(char *chave, char *mensagem_descriptografada, int tam_chave, int tam_mensagem) {
    int i, j, num_tabela;
    int k = 0;
    char letra_chave;
    for(i = 0; i < tam_mensagem; i++){
        if (j == tam_chave - 1) {
            j = 0;
        }else{
            letra_chave = chave[j];
            num_tabela = converterParaAscii(letra_chave);
            j++;
        }
        mensagem_descriptografada[k] = num_tabela - i;
        k++;
    }
}

int main() {
    int tamanho_chave;
    int tamanho_mensagem;
    char chave[TAMCHAVE];
    char mensagem[TAMMENSAGEM];

    pedir_chave(chave, &tamanho_chave);
    inserir_mensagem(mensagem, &tamanho_mensagem);

    char mensagem_criptografada[tamanho_mensagem];
    char mensagem_descriptografada[tamanho_mensagem];

    criptografar(chave, mensagem_criptografada, tamanho_chave, tamanho_mensagem);
    imprimir(mensagem_criptografada, chave);
    descriptografar(chave, mensagem_descriptografada, tamanho_chave, tamanho_mensagem);
    imprimir(mensagem_descriptografada, chave);

    return 0;
}