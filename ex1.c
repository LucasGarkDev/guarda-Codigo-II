#include <stdio.h>
#include <stdlib.h>

#define TAMCHAVE 30
#define TAMMENSAGEM 1000

void pedirChave(char *chavePrimaria){
    printf("Digite a chave:");
    scanf(" %29[^\n]s", chavePrimaria);
}

void inserirMensagem(char *mensagem, int tam){
    int repete = 0;
    do{
        repete = 0;
        printf("Digite a mensagem: ");
        scanf(" %999[^\n]s", mensagem);
        if (strlen(mensagem) != tam){
            repete = 1;
        }
    } while (repete != 0);
}

int main(){
    char *chave;
    char *mensagem;
    pedirChave(chave);
    inserirMensagem(mensagem,TAMMENSAGEM);



    return 0;    
}