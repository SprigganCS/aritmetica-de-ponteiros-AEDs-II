#include <iostream>
#include <fstream>
#include <math.h>
#include "funcoes.h"

/*-------------------------------------------------------------
* UNIFAL - Universidade Federal de Alfenas.
* BACHARELADO EM CIENCIA DA COMPUTACAO.
* Atividade.: Processamento de imagens com ponteiros
* Disciplina: AEDs II
* Professor.: Paulo Bressan
* Aluno.....: Andre Neves Medeiros
* Data......: 10/12/2020
-------------------------------------------------------------*/

using namespace std;
int main(){
    int *p, *psaida;
    int lin, col, escala;
    int cont;
    char texto[30];
    ifstream arq("imagem.pgm");
    arq>>texto;
    arq>>texto;
    arq>>lin>>col>>escala;
    int mat [600][404];
    int matsaida[600][400];
    for(p=&mat[0][0]; p<&mat[lin][col]; p++){
        arq>>*p;
    }
    arq.close();

    
    ruido(&mat[0][0], &matsaida[0][0], lin, col);
    
    psaida=&matsaida[0][0];//ESCRITA ARQUIVO I
    ofstream arqsaida1("FILTRO_RUIDO.pgm");
    arqsaida1<<"P2"<<endl;
    arqsaida1<<"#Andre_Neves_Medeiros"<<endl;
    arqsaida1<<lin<<" "<<col<<endl<<escala<<endl;
    p=&mat[0][0];
    for(psaida=&matsaida[0][0]; psaida<&matsaida[0][0]+lin*col; psaida++, cont++){
        arqsaida1<<*psaida<<" ";
        if(cont==col){
            arqsaida1<<endl;
        }
    }
    arqsaida1.close();
    cout<<"Arquivo 1 gravado"<<endl;



    bordas(&mat[0][0], &matsaida[0][0], lin, col);

    psaida=&matsaida[0][0];//ESCRITA ARQUIVO II
    ofstream arqsaida2("BORDAS.pgm");
    arqsaida2<<"P2"<<endl;
    arqsaida2<<"#Andre_Neves_Medeiros"<<endl;
    arqsaida2<<lin<<" "<<col<<endl<<escala<<endl;
    p=&mat[0][0];
    for(psaida=&matsaida[0][0]; psaida<&matsaida[0][0]+lin*col; psaida++, cont++){
        arqsaida2<<*psaida<<" ";
        if(cont==col){
            arqsaida2<<endl;
        }
    }
    arqsaida2.close();
    cout<<"Arquivo 2 gravado"<<endl;




    int matsaida_icone[64][64];
    icone(&mat[0][0], &matsaida_icone[0][0], lin, col);

    psaida=&matsaida_icone[0][0];//ESCRITA ARQUIVO III
    ofstream arqsaida3("ICONE.pgm");
    arqsaida3<<"P2"<<endl;
    arqsaida3<<"#Andre_Neves_Medeiros"<<endl;
    arqsaida3<<"64 64"<<endl<<escala<<endl;
    p=&mat[0][0];
    for(psaida=&matsaida_icone[0][0]; psaida<&matsaida_icone[0][0]+64*64; psaida++, cont++){
        arqsaida3<<*psaida<<" ";
        if(cont==64){
            arqsaida3<<endl;
        }
    }
    arqsaida3.close();
    cout<<"Arquivo 3 gravado"<<endl;

    return 0;
}
