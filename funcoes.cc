void ruido (int *p, int *psaida, int lin, int col)
{
	int *limite;
	limite=p;
	int aux;

    limite=p;
	while(p<limite+(lin-1)*(col-1))
	{ 
        aux=*p*4+*(p+1)*2+*(p-2)*2+*(p+1-col)*2+*(p+1)+*(p-2)+*(p+col+col)+*(p+1)*2+*(p+1);
        //aux=*p*4+*(p+1)*2+*(p-1)*2+*(p-col)*2+*(p-col+1)+*(p-col-1)+*(p+col)*2+*(p+col+1)+*(p+col-1);
        aux=aux/16;
        *psaida=aux;
        psaida++, p++;
	}
}

void bordas(int *p, int *psaida, int lin, int col)
{
    
    int fator=255;
    int *ponte;
    ponte=psaida;
    for(ponte=p; ponte<p+242400; ponte+=col){
        int *aux;
        for(aux=ponte; aux<ponte+col; aux++, psaida++)
        {
            *psaida=*aux-fator;
            if(*psaida<0){
                *psaida=0;
            }

        }
        fator-=2;
        if(fator<0){
            fator=0;
        }
    }
}


void icone (int *p,  int *psaida, int lin, int col)
{
    int *aux;
    int auxi;
    int i=0;
    for(aux=psaida; aux<psaida+4096; p+=22, aux++)
    {
        auxi=*p;
        *aux=auxi/2;
        i++;
    }
}
