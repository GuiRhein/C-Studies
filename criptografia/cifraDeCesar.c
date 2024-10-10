#include <stdio.h>

char * encrypt(char texto_secreto[], int n){
    int numero;

    if(n > 26 || n < 0){
        numero = n % 26;
    }else{
        numero = n;
    }

    int i = 0;


    while(texto_secreto[i] != NULL){
        char newLetter = texto_secreto[i] + numero;
        //space
        if (texto_secreto[i] == 32){
            texto_secreto[i] = 32;
        }
        //ASCII entre 65 e 90 "MAIUSCULAS"
        else if(texto_secreto[i] >= 65 && texto_secreto[i] <= 90){
            if(newLetter >= 65 && newLetter <= 90){
                texto_secreto[i] = newLetter;
            }else if(newLetter < 65){
                texto_secreto[i] = newLetter + 26;
            }else if (newLetter > 90){
                texto_secreto[i] = newLetter - 26;
            }
        }
        //ASCII entre 97 e 122 "Minusculas"
        else if (texto_secreto[i] >= 97 && texto_secreto[i] <= 122){
            if(newLetter >= 97 && newLetter <= 122){
                texto_secreto[i] = newLetter;
            }else if(newLetter > 0 && newLetter < 97){
                texto_secreto[i] = newLetter + 26;
            }else if (newLetter > 122){
                texto_secreto[i] = newLetter - 26;
            }else if (newLetter < 0){
                texto_secreto[i] = newLetter +  230;
            }
        }
        i++;
    }

    return texto_secreto;
}

char * decrypt(char texto_protegido[], int n){
    encrypt(texto_protegido, -n);
}


int main(){
    char texto_secreto[50];
    fgets(texto_secreto, 50, stdin);
    int n = 2602;

    char* criptografar = encrypt(texto_secreto, n);
    printf("%s\n", criptografar);

    char* descriptografar  = decrypt(texto_secreto, n);
    printf("%s", descriptografar);

}
