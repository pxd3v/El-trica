/* Trabalho Final de Programação
Alunos: Isabella Santos Rocha e Pedro de Souza
Turma: Eng. Eletrica 2019
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	int mes;
	int ano;
} data;

typedef struct leitura {
	int nconta;
	char nome[20];
	data ref;
	int consumo;
} leitura;

typedef struct param {
float vlrKWh100; // Valor do custo KWh para até 100
float vlrKWh101_200; // Valor entre 101 e 201
float vlrKWh201; // valor do KW para consumo a partir de 201
char mesBandeira[12]; //(G-verde, Y-amarela, R-Vermelha
float adicBand[3]; // valor adicional para cada 100KWh p/
// as bandeiras: verde, amarela, vermelha
} param;

//variaveis
FILE *arqP;
leitura dados[48];
param parametros[1];
FILE *arqD;
int m, d;
int c=0;
char cor[9];
//função leitura dos parametros

void bubble_sort(int inicio, int fim) {
	int i, j;
	for (i = inicio; i < fim; i++) {
		for (j = inicio; j < fim; j++) {
			if (dados[j].consumo > dados[j + 1].consumo) {
				leitura aux = dados[j];
				dados[j] = dados[j + 1];
				dados[j + 1] = aux;
			}
		}
	}

}

void lerPam()
{
    int i=0;
    if(arqP = fopen("param.dat","rb"));
    {
        fread(&parametros[i], sizeof(parametros[i]), 1, arqP);
        while(!feof(arqP))
        {
            i++;
            fread(&parametros[i], sizeof(parametros[i]), 1, arqP);
        }
        fclose(arqP);
    }
    //for(i=0; i<1; i++)
    //printf("\n%f\n%f\n%f\n%s\n%f\n%f\n%f\n", parametros[i].vlrKWh100, parametros[i].vlrKWh101_200, parametros[i].vlrKWh201, parametros[i].mesBandeira, parametros[i].adicBand[1], parametros[i].adicBand[2], parametros[i].adicBand[3]);
}

//função leitura dos dados
void lerDados()
{
    int i=0;
    if(arqD = fopen("dados.dat","rb"));
    {
        fread(&dados[i], sizeof(dados[i]), 1, arqD);
        while(!feof(arqD))
        {
            i++;
            fread(&dados[i], sizeof(dados[i]), 1, arqD);
        }
        fclose(arqD);
    }
    //for(i=0; i<48; i++)
    //printf("\n%d\n%s\n%d\n%d\n%d\n", dados[i].nconta, dados[i].nome, dados[i].ref.mes, dados[i].ref.ano, dados[i].consumo);
}
//função valores
float davalor(float valor)
{
    int mult=0;
    switch(c)
    {
        case 1:
            if(dados[d].consumo<100)
            {
                valor = dados[d].consumo;
            }else if(dados[d].consumo<201)
                {
                    mult = dados[d].consumo/100;
                    valor = 3*m*1.5*dados[d].consumo;
                }else if(dados[d].consumo>200)
                    {
                        mult = dados[d].consumo/100;
                        valor = 3*m*2*dados[d].consumo;
                    }
        case 2:
            if(dados[d].consumo<100)
            {
                valor = dados[d].consumo;
            }else if(dados[d].consumo<200)
                {
                    mult = dados[d].consumo/100;
                    valor = 5*m*1.5*dados[d].consumo;
                }else if(dados[d].consumo>200)
                    {
                        mult = dados[d].consumo/100;
                        valor = 5*m*2*dados[d].consumo;
                    }
        case 3:
            if(dados[d].consumo<100)
            {
                valor = dados[d].consumo;
            }else if(dados[d].consumo<200)
                {
                    valor = 1.5*dados[d].consumo;
                }else if(dados[d].consumo>200)
                    {
                        valor = 2*dados[d].consumo;
                    }
    }
    return valor;
}
void menu();
//função listagem das contas
void listagem()
{

int inicio, fim;
for (inicio = 0, fim = 11; fim <= 47; inicio = fim + 1, fim += 12) {
	bubble_sort(inicio, fim);
}
float soma;
int aux=0;
    system("cls");
        printf("                    ***** Listagem da conta de luz *****                    \n");
        printf("Conta: 1 - Cliente 1\n");
        printf("+------------+---------+----------+---------+\n");
        printf("+ REFERENCIA + CONSUMO + BANDEIRA +  VALOR  +\n");
        printf("+------------+---------+----------+---------+\n");
        for(d=0;d<12;d++)
            {
                if(m<4)
                {
                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                    c=1;
                }else if(m<8)
                    {
                        cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                        c=2;
                    }else if(m<9)
                        {
                            cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='m', cor[4]='e', cor[5]='l', cor[6]='h', cor[7]='o', cor[8]=' ';
                            c=3;
                        }else if(m==10)
                            {
                                cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                                c=2;
                            }else if(m==11)
                                {
                                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                                    c=1;
                                }
                if(davalor(dados[d].consumo)<100)
                {
                printf("|   %2d/%d  |   %3d   | %s|  %.2f  |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                }else{
                printf("|   %2d/%d  |   %3d   | %s|  %.2f |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                     }
                soma=davalor(dados[d].consumo)+aux;
                aux=soma;
                m++;
            }
        printf("+------------+---------+----------+---------+\n");
        printf("                Total do periodo =  %.2f\n", soma);
        soma=0;
        aux=0;
        m=0;
        printf("Conta: 2 - Cliente 2\n");
        printf("+------------+---------+----------+---------+\n");
        printf("+ REFERENCIA + CONSUMO + BANDEIRA +  VALOR  +\n");
        printf("+------------+---------+----------+---------+\n");
        for(d=12;d<24;d++)
            {
                if(m<4)
                {
                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                    c=1;
                }else if(m<7)
                    {
                        cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                        c=2;
                    }else if(m<9)
                        {
                            cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='m', cor[4]='e', cor[5]='l', cor[6]='h', cor[7]='o', cor[8]=' ';
                            c=3;
                        }else if(m==10)
                            {
                                cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                                c=2;
                            }else if(m==11)
                                {
                                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                                    c=1;
                                }
                if(davalor(dados[d].consumo)<100)
                {
                printf("|   %2d/%d  |   %3d   | %s|  %.2f  |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                }else{
                printf("|   %2d/%d  |   %3d   | %s|  %.2f |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                     }
                soma=davalor(dados[d].consumo)+aux;
                aux=soma;
                m++;
            }
        printf("+------------+---------+----------+---------+\n");
        printf("                Total do periodo =  %.2f\n", soma);
        soma=0;
        aux=0;
        m=0;
        printf("Conta: 3 - Cliente 3\n");
        printf("+------------+---------+----------+---------+\n");
        printf("+ REFERENCIA + CONSUMO + BANDEIRA +  VALOR  +\n");
        printf("+------------+---------+----------+---------+\n");
        for(d=24;d<36;d++)
            {
                if(m<4)
                {
                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                    c=1;
                }else if(m<7)
                    {
                        cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                        c=2;
                    }else if(m<9)
                        {
                            cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='m', cor[4]='e', cor[5]='l', cor[6]='h', cor[7]='o', cor[8]=' ';
                            c=3;
                        }else if(m==10)
                            {
                                cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                                c=2;
                            }else if(m==11)
                                {
                                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                                    c=1;
                                }
                if(davalor(dados[d].consumo)<100)
                {
                printf("|   %2d/%d  |   %3d   | %s|  %.2f  |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                }else{
                printf("|   %2d/%d  |   %3d   | %s|  %.2f |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                     }
                soma=davalor(dados[d].consumo)+aux;
                aux=soma;
                m++;
            }
        printf("+------------+---------+----------+---------+\n");
        printf("                Total do periodo =  %.2f\n", soma);
        soma=0;
        aux=0;
        m=0;
        printf("Conta: 4 - Cliente 4\n");
        printf("+------------+---------+----------+---------+\n");
        printf("+ REFERENCIA + CONSUMO + BANDEIRA +  VALOR  +\n");
        printf("+------------+---------+----------+---------+\n");
        for(d=36;d<48;d++)
            {
                if(m<4)
                {
                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                    c=1;
                }else if(m<7)
                    {
                        cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                        c=2;
                    }else if(m<9)
                        {
                            cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='m', cor[4]='e', cor[5]='l', cor[6]='h', cor[7]='o', cor[8]=' ';
                            c=3;
                        }else if(m==10)
                            {
                                cor[0]='A', cor[1]='m', cor[2]='a', cor[3]='r', cor[4]='e', cor[5]='l', cor[6]='o', cor[7]=' ', cor[8]=' ';
                                c=2;
                            }else if(m==11)
                                {
                                    cor[0]='V', cor[1]='e', cor[2]='r', cor[3]='d', cor[4]='e', cor[5]=' ', cor[6]=' ', cor[7]=' ', cor[8]=' ';
                                    c=1;
                                }
                if(davalor(dados[d].consumo)<100)
                {
                printf("|   %2d/%d  |   %3d   | %s|  %.2f  |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                }else{
                printf("|   %2d/%d  |   %3d   | %s|  %.2f |\n", dados[d].ref.mes, dados[d].ref.ano, dados[d].consumo, cor, davalor(dados[d].consumo));
                     }
                soma=davalor(dados[d].consumo)+aux;
                aux=soma;
                m++;
            }
        printf("+------------+---------+----------+---------+\n");
        printf("                Total do periodo =  %.2f\n", soma);
        soma=0;
        aux=0;
        m=0;
        printf("Aperte alguma tecla para voltar ao menu.");
        getche();
        menu();
}

//função fim
void fim()
{
    system("pause");
}

//função menu
void menu()
{
    system("cls");
    printf("(l)Listagem\n");
    printf("(f)Fim\n");
    char letra;
    letra = getche();
    switch(letra)
    {
        case 'l':
            listagem();
            break;
        case 'f':
            fim();
            break;
    }
}

//função main
void main()
{
lerDados();
lerPam();
menu();
}

