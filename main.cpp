#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char palavra[30],letra[1],secreta[30];
    int acertos, chances, tamanho, i;
    bool acerto;
    
    acertos = 0;
    chances = 6;
    tamanho = 0;
    acerto = false;
    i = 0;
    
    cout<<"Este é um Jogo da Forca.";
    cout<<"\n"<<"Digite uma palavra qualquer de até 30 letras para ser advinhada por outra pessoa: ";
    cin >> palavra;
    
//apagamento da palavra digitada
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

//definição do tamanho da palavra
    while (palavra[i] != '\0') {
        i++;
        tamanho++;
    }
    
//definição de 'secreta'(quantidade de letras a serem descobertas) e sua demonstração
    cout<< "Palavra: \n";
    for (i = 0; i<tamanho; i++){
        secreta[i] = '_';
        cout << " " << secreta[i];
    }
    while ((chances>0)&&(acertos<tamanho)){
        cout<<"\n\n"<<"Chances restantes: "<<chances;
        cout<<"\n"<<"Digite uma letra: ";
        cin >> letra[0];
        
        for (i=0;i<tamanho;i++){
            if (letra[0]==palavra[i]){
                acerto = true;
                acertos++;
                secreta[i]=palavra[i];
            }
        }
        if (!acerto){
            chances--;
        }
        for (i = 0; i<tamanho;i++){
            cout <<" " << secreta[i];
        }
        acerto = false;
//apagar o processo até então para limpar para os processos seguintes
        system("clear");
    }
    
    if(acertos == tamanho){
        cout<<"\n\n"<<"Parabéns, você venceu!";
    }
    else{
        cout << "\n\n"<<"Você perdeu...";
    }
    cin.get();
    return 0;
}