#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

void ImprimeVetor (char vetor[], char tamanho)
{
    int n;
    for (n=0; n<tamanho; n++)
        if(vetor[n]==1)
            cout<<"*";
        else if (vetor[n]!=1)
            cout<<" ";
    cout<<"\n";
}

void CopiaVetor (char entrada[], char saida[], int tamanho)
{
    int n;
    for (n=0; n<tamanho; n++)
        saida[n]=entrada[n];
}

void calcularegra_30 (int Nlinhas, int tamanho, char *linha_anterior, char *linha_atual)
{
    int aux, aux2, n;

    for (aux2=2; aux2<Nlinhas; aux2++)
    {
        for (aux=1; aux<tamanho; aux++)
        {
            n = linha_anterior[aux-1]*4+linha_anterior[aux]*2+linha_anterior[aux+1];
            linha_atual[aux] = (30&(1<<n))!=0;
        }
        ImprimeVetor(linha_anterior, tamanho);
        CopiaVetor(linha_atual, linha_anterior, tamanho);
    }
}
void calcularegra_90 (int Nlinhas, int tamanho, char *linha_anterior, char *linha_atual)
{
    int aux, aux2, n;

    for (aux2=2; aux2<Nlinhas; aux2++)
    {
        for (aux=1; aux<tamanho; aux++)
        {
            n = linha_anterior[aux-1]*4+linha_anterior[aux]*2+linha_anterior[aux+1];
            linha_atual[aux] = (90&(1<<n))!=0;
        }
        ImprimeVetor(linha_anterior, tamanho);
        CopiaVetor(linha_atual, linha_anterior, tamanho);
    }
}
void calcularegra_110 (int Nlinhas, int tamanho, char *linha_anterior, char *linha_atual)
{
    int aux, aux2, n;

    for (aux2=2; aux2<Nlinhas; aux2++)
    {
        for (aux=1; aux<tamanho; aux++)
        {
            n = linha_anterior[aux-1]*4+linha_anterior[aux]*2+linha_anterior[aux+1];
            linha_atual[aux] = (110&(1<<n))!=0;
        }
        ImprimeVetor(linha_anterior, tamanho);
        CopiaVetor(linha_atual, linha_anterior, tamanho);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc, Nlinhas, tamanho, aux;
    char *linha_anterior, *linha_atual, cond;

    while (1)
    {
        cout << "Digite o número de linhas: ";
        cin >> Nlinhas;
        cout << "Digite o tamanho da linha: ";
        cin >> tamanho;
        cout << "\n\nqual regra de autômato celular deseja aplicar?\n";
        cout << "regra 30.\n";
        cout << "regra 90.\n";
        cout << "regra 110.\n";
        cin >> opc;

        system("cls");

        linha_anterior = (char*) malloc(tamanho*sizeof(char));
        linha_atual = (char*) malloc(tamanho*sizeof(char));

        for (aux=0; aux<tamanho; aux++)
            linha_anterior[aux] = 0;

        linha_anterior[aux/2] = 1;
        linha_atual[0]=linha_anterior[tamanho-1] = 0;

        switch(opc)
        {
        case 30:
        {
            calcularegra_30(Nlinhas, tamanho, linha_anterior, linha_atual);
            system("pause");
            system("cls");
            break;
        }
        case 90:
        {
            calcularegra_90(Nlinhas, tamanho, linha_anterior, linha_atual);
            system("pause");
            system("cls");
            break;
        }
        case 110:
        {
            calcularegra_110(Nlinhas, tamanho, linha_anterior, linha_atual);
            system("pause");
            system("cls");
            break;
        }
        default:
        {
            cout<<"\nregra digitada inválida\n\n";
            system("pause");
            system("cls");
            break;
        }
        }
        cout<<"deseja testar outra(s) regra(s)  <s/n>\n";
        cin>>cond;
        if (cond=='s')
            system("cls");
        if (cond=='n')
            break;
        if (cond!='s' && cond!='n')
        {
            cout<<"\nopção digitada invalida, saindo do programa\n";
            break;
        }
    }
    return 0;
}
