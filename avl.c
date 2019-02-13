/* Autor: Airam Saile Ripardo Costa */
/* airamcosta@gmail.com */
/* Contribui��es s�o bem-vindas! */

#include<stdio.h>
#include<stdlib.h>
#include<windows.h> //Utilizado para acessar as configura��es de tela

#define MAX 100 //Define o tamanho m�ximo do nome/caminho do arquivo e de caracteres (por linha) que ser�o lidos na importa��o

/* In�cio dos c�digos de tela */

/* Define os valores para altura x lagura da tela e remove as barras de rolagens vertical e horizontal */
void configtela()//fun��o q configura o tamanho da tela e do buffer
{
COORD outbuff;
outbuff.X = 81; // tem que ser 1 maior que o tamanho X
outbuff.Y = 40; // tem que ser 1 maior que o tamanho Y
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleScreenBufferSize(hConsole, outbuff);
Sleep(130);
SMALL_RECT windowSize = {0, 0, 80, 39};
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

/* Limpa a tela */
void limpa_tela()
{
    system("cls");
}

/* Cabe�alho do programa */
void imprime_tela_cabecalho()
{
    limpa_tela();
    printf("\n");
    printf("                                                                Th3 W4lk1n6 D34d\n");
    printf(" ###############################################################################\n");
    printf(" #                                                                             #\n");
    printf(" #                    ALGORITMOS E ESTRUTURA DE DADOS AVAN%cADOS                #\n", 128);
    printf(" #                                  CIM03S1 - v1.0                             #\n");
    printf(" #                                                                             #\n");
    printf(" #                                 The Binary Tree%c                            #\n", 184);
    printf(" #                                                                             #\n");
    printf(" ###############################################################################\n\n");
}

/* Cabe�alho do menu principal */
void menu_principal()
{
    printf(" ====================================== MENU ===================================\n\n");
}

/* Imprime o texto sobre o programa e AVL na abertura do programa */
void imprime_tela_abertura()
{
    imprime_tela_cabecalho();
    printf("\n                                   %cRVORE BIN%cRIA\n\n", 181, 181);
    printf("                              INSER%c%cO, BUSCA E REMO%c%cO\n\n\n", 128, 199, 128, 199);
    printf("       Esta %c uma aplica%c%co desenvolvida aplicando uma t%ccnica computacional \n\n", 130, 135, 198, 130);
    printf("   conhecida como AVL - %crvore Bin%cria (Auto-Balanceada) de Busca. \n\n", 181, 160);
    printf("       %c uma estrutura de dados avan%cada que permite que grande quantidade de \n\n", 144, 135);
    printf("   dados possam ser manipulados sem que isso afete o desempenho do computador, \n\n");
    printf("   pois as opera%c%ces de inser%c%co, busca e remo%c%co dos elementos possuem \n\n", 135, 228, 135, 198, 135, 198);
    printf("   complexidade (log2n), no qual n %c o n%cmero de elementos da %crvore. \n\n", 130, 163, 160);     
    printf("       A AVL leva as iniciais de seus criadores, Adelson Velsky e Landis e a \n\n");
    printf("   sua primeira refer%cncia encontra-se no documento Algoritmos para \n\n", 136); //Se ativar a linha abaixo remover \n\n\n\n\n\n\n (7)
    printf("   organiza%c%co da informa%c%co, de 1962. \n\n\n\n", 135, 198, 135, 198); //Se ativar a linha abaixo remover \n\n\n\n\n\n\n (7)     
//    printf("                                       Digite 0 no menu para ver os cr%cditos\n\n\n\n\n\n\n", 130);
    printf("   "); //Esta linha � utilizada para fazer a tabula��o na mensagem Pressione qualquer tecla para continuar...
}

/* Cr�ditos do programa que pode ser chamado no menu ou neste caso, na finaliza��o do processo */
void creditos()
{
    imprime_tela_cabecalho();
    printf(" ==================================== CR%cDITOS =================================\n\n", 144);
    printf("   Trabalho solicitado pelo Prof. Msc. Diego da Silva Froner para a disciplina\n\n");
    printf("   de Algoritmos e Estruturas de Dados Avan%cados, do Terceiro Per%codo do Curso\n\n", 135, 161);
    printf("   de Ci%cncia da Computa%c%co da Faculdade UNINORTE - LAUREATE.\n\n\n", 136, 135, 198);
    printf("   Desenvolvido por:\n\n\n", 162);
    printf("   Alunos:                                                          Matr%ccula:\n\n", 161);
    printf("     Airam Saile Ripardo Costa (airamcosta%cgmail.com)                13307738\n\n", 64);
    printf("     Brendon Eloi de Oliveira Pinheiro (brendonribeiro%chotmail.com)  13216597\n\n", 64);
    printf("             \n\n\n  ");  
    printf("                     Manaus, Abril de 2014 | Per%codo 03/08\n\n\n\n\n   ", 161);
    system("pause");
}
/* Fim dos c�digos de tela */



/*Inicio do c�digo das fun��es e procedimentos do programa */
/* Registro */
typedef struct No
{
    int Id; //Valor que � informado para o n�
    struct No *Esquerda; //Liga��o com outro n�(valor) pela esquerda
    struct No *Direita; //Liga��o com outro n�(valor) pela direita
    int Altura; //Altura do N�
} No;

/* Fun��o que retorna o fator de balanceamento do n� */
int Balanceamento(No *Raiz)
{
    if (Raiz == NULL)
    return 0;
    return Altura(Raiz-> Esquerda) - Altura(Raiz-> Direita);
}

/* Fun��o que retorna o maior valor entre dois inteiros (Utilizado pelas rota��es */
int Maior(int a, int b);

/* Fun��o que retorna o maior valor entre dois inteiros (Utilizado pelas rota��es */
int Maior(int a, int b)
{
    return (a > b)? a : b;
}

/* Fun��o para a rota��o da sub-�rvore (� direita) */
No *RotDir(No *Raiz)
{
    No *AuxiliarEsquerda = Raiz-> Esquerda;
    No *AuxiliarDireita = AuxiliarEsquerda-> Direita;
 
    // Realizando rota��o
    AuxiliarEsquerda-> Direita = Raiz;
    Raiz-> Esquerda = AuxiliarDireita;
 
    // Atualizando alturas
    Raiz-> Altura = Maior(Altura(Raiz-> Esquerda), Altura(Raiz-> Direita))+1;
    AuxiliarEsquerda-> Altura = Maior(Altura(AuxiliarEsquerda-> Esquerda), Altura(AuxiliarEsquerda-> Direita))+1;
 
    // Retornando a nova raiz (Raiz alterada)
    return AuxiliarEsquerda;
}
 
/* Fun��o para a rota��o da sub-�rvore (� esquerda) */
No *RotEsq(No *Raiz)
{
    No *AuxiliarDireita = Raiz-> Direita;
    No *AuxiliarEsquerda = AuxiliarDireita-> Esquerda;
 
    // Realizando rota��o
    AuxiliarDireita-> Esquerda = Raiz;
    Raiz-> Direita = AuxiliarEsquerda;
 
    // Atualizando alturas
    Raiz->Altura = Maior(Altura(Raiz-> Esquerda), Altura(Raiz-> Direita))+1;
    AuxiliarDireita->Altura = Maior(Altura(AuxiliarDireita-> Esquerda), Altura(AuxiliarDireita-> Direita))+1;
 
    // Retornando a nova raiz (Raiz alterada)
    return AuxiliarDireita;
}

/* Fun��o para verificar se o ponteiro Raiz do tipo No (registro) � nulo */
int IsNull(No *Raiz) //Podia ser feito sem ela, mas dava mais trabalho pra fazer toda vez que fosse preciso verificar isso
{
	return (Raiz == (No*)NULL); //Sempre retorna nulo se for
}

/* Fun��o que verifica e imprime na tela a altura da �rvore ou do n� */
int Altura(No *Raiz)
{
    if (Raiz == NULL) //Se raiz for nulo
        return -1; //retorna 0
    return Raiz-> Altura; //Sen�o usa recursividade
}

/* Fun��o auxiliar que aloca um novo n� para a chava informada - Chamada pela fun��o AdicionarNo */
No* NovoNo(int Id)
{
    No* Raiz = (No*)malloc(sizeof(No)); //Aloca espa�o na mem�ria para o registro
    Raiz-> Id = Id; //Id de Raiz recebe a chave informada pelo usu�rio
    Raiz-> Esquerda = NULL; // Como o n� � novo -> Esquerda e -> Direita apontam para nulo
    Raiz-> Direita = NULL;
    Raiz-> Altura = 0;  // O novo n� inserido � inicialmente uma folha portanto sua altura � 1
    return(Raiz); //Retorna a Raiz
}

/* Fun��o que insere um novo N� - Utiliza a fun��o auxiliar NovoNo */
No* AdicionarNo(No *Raiz, int Id)
{
    /* Passo 1 - Executa a inser��o normal */
    if(Raiz == NULL) //Se a Raiz � nula(Vazia)
    {
        return(NovoNo(Id)); //Chama a fun��o auxiliar que insere a chave informada pelo usu�rio
    }
else
    if(Raiz != NULL) //Se a Raiz n�o for nula(Vazia)
    {
        if(Id < Raiz-> Id) //Verifica se a chave informada pelo usu�rio � menor que a chave da Raiz
        {
            Raiz-> Esquerda  = AdicionarNo(Raiz-> Esquerda, Id); //se for menor, chama novamente a fun��o(recursividade), fazendo a �ltima chave(esquerda) apontar para a nova chave
        }
     //Sen�o (veja linha abaixo)
        if(Id > Raiz-> Id) //Verifica se a chave informada pelo usu�rio � maior que a chave da Raiz
        {
            Raiz-> Direita = AdicionarNo(Raiz-> Direita, Id); //sen�o for menor, � maior e chama novamente a fun��o(recursividade), fazendo a �ltima chave(direita) apontar para a nova chave
        }
 
        /* Passo 2 - Atualiza a altura do novo n� (em rela��o ao anterior) */
        Raiz-> Altura = Maior(Altura(Raiz-> Esquerda), Altura(Raiz-> Direita)) + 1;
 
        /* Passo 3 - Declarada uma v�ri�vel inteira que tem por objetivo obter o fator de balanceamento deste n� em rela��o ao anterior(pai) para saber se a arvore ficou desbalanceada*/
        int fb = Balanceamento(Raiz); //Verifica o fator de balanceamento
 
        //Se o novo n� causou desbalanceamento da �rvore, ser� necess�rio obter o balanceamento por meio de uma das 4 formas (dependendo do caso)

        //Rota��o simples � esquerda
        if (fb > 1 && Id < Raiz-> Esquerda-> Id) //Se o fator de balanceamento da Raiz for maior que 1 e o Id informado pelo usu�rio for menor que o Id que est� na Raiz -> Esquerda
            return RotDir(Raiz); //Retorna a Raiz, depois de aplicada a Rota��o � Direita(Fun��o)
 
        //Rota��o simples � direita
        if (fb < -1 && Id > Raiz-> Direita-> Id)
            return RotEsq(Raiz);
 
        //Rota��o dupla � esquerda
        if (fb > 1 && Id > Raiz-> Esquerda-> Id)
        {
            Raiz-> Esquerda =  RotEsq(Raiz-> Esquerda);
            return RotDir(Raiz);
        }
 
        //Rota��o dupla � direita
        if (fb < -1 && Id < Raiz-> Direita-> Id)
        {
            Raiz-> Direita = RotDir(Raiz-> Direita);
            return RotEsq(Raiz);
        } //Fim das rota��es
 
        /* Passo 4 - Retorna a nova Raiz(alterada) */
        return Raiz;
    }
}

/* Fun��o para buscar um n� e saber se um valor existe na �rvore */
No* BuscarNo(No *Raiz, int Id)
{
    if (Raiz == (No*) NULL) //Se Raiz for igual a nulo
        return NULL; //Retorna Nulo
    
    if (Raiz-> Id == Id) //Se Id de Raiz for igual a Id passado por par�metro
        return Raiz; //Retorna a pr�pria Raiz pois n�o h� nada a ser feito pois o valor j� existe na �rvore e n�o vamos duplicar esse bagulho, he he, t� gostando dessa parada Brendon
    
    if (Id > Raiz-> Id) //Se Id(par�metro) for maior que Id de Raiz
        return BuscarNo(Raiz-> Direita, Id); //Chama novamente a fun��o (recursividade) para iserir o valor a direita
    else if (Id < Raiz-> Id) //Caso n�o seja Maior, ent�o � menor e
        return BuscarNo(Raiz-> Esquerda, Id); //chama novamente a fun��o para inserir a esquerda informando os novos par�metros
}

/* Procedimento para exibir (imprimir) os valores na ordem em que foram inseridos aplicando recursividade */
void PreOrdem(No *NoAtual)
{
    if(NoAtual == (No*) NULL) //Se o ponteiro NoAtual do Tipo No(registro) for nulo
        return; //Retorna Nulo
  //Sen�o
    printf("%d ", NoAtual->Id ); //Imprime um inteiro Id de Atual
    PreOrdem(NoAtual-> Esquerda); //E chama novamente a fun��o para imprimir esquerda caso n�o seja nulo
    PreOrdem(NoAtual-> Direita); //E a direita caso n�o seja nulo
}

/* Procedimento para exibir (imprimir) os valores na ordem (maior e menor ao lado do valor) em que foram inseridos aplicando recursividade */
void PosOrdem(No *NoAtual)
{
    if (NoAtual == (No*) NULL) //Se o ponteiro passado como par�mentro for nulo
        return; //Retorna nulo
  //Sen�o
    PosOrdem(NoAtual-> Esquerda); //Chama novamente a fun��o apontando para a esquerda
    PosOrdem(NoAtual-> Direita); //E depois para a direita
    printf("%d ", NoAtual->Id ); //imprimindo o valor
}

/* Procedimento para exibir (imprimir) os valores na ordem em que foram inseridos (tipo pr�-ordem) aplicando recursividade */
void EmOrdem(No *NoAtual) //Varredura e-r-d (= inorder traversal = percurso em in-ordem) Ordem Raiz-Esquerda_Direita.
{
    if (NoAtual == (No*) NULL) //Se o ponteiro NoAtual do tipo No(registro) for nulo
        return; //Retorna nulo
  //Sen�o  
    EmOrdem(NoAtual-> Esquerda); //Sen�o chama novamente a fun��o indo para a esquerda
    printf("%d ", NoAtual->Id ); //Imprimindo o Id
    EmOrdem(NoAtual-> Direita); //E depois chamando novamente a fun��o indo para a direita
}

/* Procedimento para exibir (imprimir) os valores na ordem em que foram inseridos (tipo p�s-ordem) aplicando recursividade */
void EmOrdemInversa(No *NoAtual)
{
    if (NoAtual == (No*) NULL) //Se NoAtual � nulo
        return; //Retorna nulo
  //Sen�o
    EmOrdemInversa(NoAtual-> Direita); //Chama novamente a fun��o indo para a direita
    printf("%d ", NoAtual->Id ); //Imprimindo o Id
    EmOrdemInversa(NoAtual-> Esquerda); //E chama novamente a fun��o indo para a esquerda
}

/* Fun��o auxiliar(ser� utilizada pela fun��o RemoverNo) que retorna o menor valor(Id, ou chave) encontrado na �rvore */
No* MenorId(No *Raiz)
{
    No *Atual = Raiz; //Vari�vel Auxiliar do tipo No(registro) � igual a Raiz
 
    /* Repeti��o(La�o) para baixo at� encontrar a folha mais a esquerda(Menor valor) (A �rvore j� est� balanceada aqui)*/
    while (Atual-> Esquerda != NULL) //Enquanto esquerda de Atual n�o for Nulo
        Atual = Atual-> Esquerda; //Atual recebe (� igual) a Atual -> Esquerda (desce um n�vel na �rvore)
 
    return Atual; //retorna Atual
}

/* Fun��o para remover o n� da �rvore sem ponteiro para ponteiro */
No* RemoverNo(No *Raiz, int Id)
{
    /* Passo 1 - Executa a remo��o normal */
    if (Raiz == NULL)
        return Raiz;

    if ( Id < Raiz->Id ) //Verifica se a chave informada pelo usu�rio � menor que a chave da Raiz
        Raiz->Esquerda = RemoverNo(Raiz->Esquerda, Id); //se for menor, chama novamente a fun��o(recursividade), fazendo a �ltima chave(esquerda) apontar para a nova chave

else //Sen�o (veja linha abaixo)

    if( Id > Raiz->Id ) //Verifica se a chave informada pelo usu�rio � maior que a chave da Raiz
        Raiz->Direita = RemoverNo(Raiz->Direita, Id); //sen�o for menor, � maior e chama novamente a fun��o(recursividade), fazendo a �ltima chave(direita) apontar para a nova chave
 
    else //Se n�o � nenhum dos casos acima (maior ou menor), ent�o � igual e este ser� o n� a ser removido
    {
        if( (Raiz->Esquerda == NULL) || (Raiz->Direita == NULL) ) //Verifica se o n� tem pelo menos 1 filho (folha)
        {
            No *Temp = Raiz->Esquerda ? Raiz->Esquerda : Raiz->Direita;
 
            if(Temp == NULL) //Casos de n�o ter filho
            {
                Temp = Raiz;
                Raiz = NULL;
            }
            else //Sen�o, caso tenha 1 filho
             *Raiz = *Temp; //Copia o conte�do do filho n�o vazi para a Raiz
 
            free(Temp); //Libera o registro (n�) tempor�rio
        }
        else
        {
            //Caso o n� tenha 2 filhos, obter o menor Id da sub-�rvore direita (poderia ser o maior da sub-�rvore esquerda).
            No *Temp = MenorId(Raiz->Direita);
 
            //Copia o valor de Id de Temp para a Raiz
            Raiz->Id = Temp->Id;
 
            //E a direita de raiz passar� a apontar para o resultado da fun��o RemoverNo passando como par�metros a direita de Raiz e o Id de Temp
            Raiz->Direita = RemoverNo(Raiz->Direita, Temp->Id);
        }
    }

    if (Raiz == NULL) //Se a �rvore for nula
      return Raiz; //Retorna ela pr�pria
 
    /* Passo 2 - Atualiza a altura do novo n� (em rela��o ao anterior) */
    Raiz->Altura = Maior(Altura(Raiz->Esquerda), Altura(Raiz->Direita)) + 1;
 
    /* Passo 3 - Declarada uma v�ri�vel inteira que tem por objetivo obter o fator de balanceamento deste n� em rela��o ao anterior(pai) para saber se a arvore ficou desbalanceada*/
    int fb = Balanceamento(Raiz);
 
    //Se o novo n� causou desbalanceamento da �rvore, ser� necess�rio obter o balanceamento por meio de uma das 4 formas (dependendo do caso)
 
    //Rota��o simples � esquerda
    if (fb > 1 && Balanceamento(Raiz->Esquerda) >= 0)
        return RotDir(Raiz);
 
    //Rota��o dupla � esquerda
    if (fb > 1 && Balanceamento(Raiz->Esquerda) < 0)
    {
        Raiz->Esquerda =  RotEsq(Raiz->Esquerda);
        return RotDir(Raiz);
    }
 
    //Rota��o simples � direita
    if (fb < -1 && Balanceamento(Raiz->Direita) <= 0)
        return RotEsq(Raiz);
 
    //Rota��o dupla � direita
    if (fb < -1 && Balanceamento(Raiz->Direita) > 0)
    {
        Raiz->Direita = RotDir(Raiz->Direita);
        return RotEsq(Raiz);
    }
 
    return Raiz;
}

/* Procedimento para remo��o da �rvore completa utilizando ponteiro para ponteiro*/
No* RemoverAVL(No *Raiz)
{
    if(Raiz != NULL)
    {
    	No *Menor = MenorId(Raiz);
    	Raiz = RemoverNo(Raiz, Menor->Id);
    	Raiz = RemoverAVL(Raiz);
    }
else
	free(Raiz);
    return NULL;
}
/* Fim do c�digo das fun��es e procedimentos do menu */



/* In�cio do c�digo das fun��es de importa��o e exporta��o */
/* Cria o arquivo que conter� os dados exportados PreOrdem */
GravaPreOrdem(No *Raiz)
{
    char Exporta;
    printf("\n\n   Deseja exportar estes dados? [s=Sim / Qualquer tecla = N%co]: ", 198);
    Exporta = getch(Exporta);
    Exporta = tolower(Exporta);

    if(Exporta == 's')
    {
    	char NomeArq[] = "preordem.txt";
    
    	FILE *Arq = fopen (NomeArq, "w"); //abre o arquivo para escrita, e devolve o endereco em memoria para Arq
    	
        ExportaPreOrdem(Raiz, Arq); //Chama a fun��o recursiva que ir� inserir os dados no arquivo
        
        fclose(Arq); //Fecha o arquivo
        
		printf("\n\n                       Exporta%c%co realizada com sucesso!\n", 135, 198); //Mensagem de confirma��o da exporta��o
        printf("           (Um arquivo preordem.txt foi gerado na pasta do aplicativo)\n\n\n   "); //Nome do arquivo gerado
    }
else
	if(Exporta != 's')
	{
		printf("\n\n\n\n\n\n   ");
	}
}

/* Cria o arquivo que conter� os dados exportados PosOrdem */
GravaPosOrdem(No *Raiz)
{
    char Exporta;
    printf("\n\n   Deseja exportar estes dados? [s=Sim / Qualquer tecla = N%co]: ", 198);
    Exporta = getch(Exporta);
    Exporta = tolower(Exporta);

    if(Exporta == 's')
    {
        char NomeArq[] = "posordem.txt";
    
	    FILE *Arq = fopen (NomeArq, "w"); //abre o arquivo para escrita, e devolve o endereco em memoria para Arq

        ExportaPosOrdem(Raiz, Arq); //Chama a fun��o recursiva que ir� inserir os dados no arquivo

		fclose(Arq); //Fecha o arquivo
        
    	printf("\n\n                       Exporta%c%co realizada com sucesso!\n", 135, 198); //Mensagem de confirma��o da exporta��o
    	printf("           (Um arquivo posordem.txt foi gerado na pasta do aplicativo)\n\n\n   "); //Nome do arquivo gerado
    }
else
	if(Exporta != 's')
	{
		printf("\n\n\n\n\n\n   ");
	}
}

/* Cria o arquivo que conter� os dados exportados EmOrdem */
GravaEmOrdem(No *Raiz)
{
    char Exporta;
    printf("\n\n   Deseja exportar estes dados? [s=Sim / Qualquer tecla = N%co]: ", 198);
    Exporta = getch(Exporta);
    Exporta = tolower(Exporta);

    if(Exporta == 's')
    {
    	char NomeArq[] = "emordem.txt";
    
    	FILE *Arq = fopen (NomeArq, "w"); //abre o arquivo para escrita, e devolve o endereco em memoria para Arq
    	
        ExportaEmOrdem(Raiz, Arq); //Chama a fun��o recursiva que ir� inserir os dados no arquivo
        
        fclose(Arq); //Fecha o arquivo
        
		printf("\n\n                       Exporta%c%co realizada com sucesso!\n", 135, 198); //Mensagem de confirma��o da exporta��o
    	printf("           (Um arquivo emordem.txt foi gerado na pasta do aplicativo)\n\n\n   "); //Nome do arquivo gerado
    }
else
	if(Exporta != 's')
	{
		printf("\n\n\n\n\n\n   ");
	}
}

/* Cria o arquivo que conter� os dados exportados em EmOrdemInversa */
GravaEmOrdemInversa(No *Raiz)
{
    char Exporta;
    printf("\n\n   Deseja exportar estes dados? [s=Sim / Qualquer tecla = N%co]: ", 198);
    Exporta = getch(Exporta);
    Exporta = tolower(Exporta);

    if(Exporta == 's')
    {
    	char NomeArq[] = "emordeminversa.txt";
    
    	FILE *Arq = fopen (NomeArq, "w"); //abre o arquivo para escrita, e devolve o endereco em memoria para Arq

        ExportaEmOrdemInversa(Raiz, Arq); //Chama a fun��o recursiva que ir� inserir os dados no arquivo
        
        fclose(Arq); //Fecha o arquivo
        
    	printf("\n\n                       Exporta%c%co realizada com sucesso!\n", 135, 198); //Mensagem de confirma��o da exporta��o
    	printf("           (Um arquivo emordeminversa.txt foi gerado na pasta do aplicativo)\n\n\n   "); //Nome do arquivo gerado
    }
else
	if(Exporta != 's')
	{
		printf("\n\n\n\n\n\n   ");
	}
}

/* Procedimento para exportar os valores na ordem em que foram inseridos aplicando recursividade */
ExportaPreOrdem(No *Raiz, FILE *Arq)
{    
    if(Raiz != (No*) NULL) //Se o ponteiro Raiz do Tipo No(registro) for nulo
    {
        fprintf(Arq, "%d", Raiz->Id ); //Imprime um inteiro Id de Atual
        fprintf(Arq,"\n"); //Quebra de linha (Enter)
        ExportaPreOrdem(Raiz-> Esquerda, Arq); //E chama novamente a fun��o para imprimir esquerda caso n�o seja nulo
        ExportaPreOrdem(Raiz-> Direita, Arq); //E a direita caso n�o seja nulo
    }
}

/* Procedimento para exportar os valores na ordem (maior e menor ao lado do valor) em que foram inseridos aplicando recursividade */
ExportaPosOrdem(No *Raiz, FILE *Arq)
{    
    if (Raiz != (No*) NULL) //Se o ponteiro passado como par�mentro for nulo
    {
        ExportaPosOrdem(Raiz-> Esquerda, Arq); //Chama novamente a fun��o apontando para a esquerda
        ExportaPosOrdem(Raiz-> Direita, Arq); //E depois para a direita
        fprintf(Arq, "%d ", Raiz->Id ); //imprimindo o valor
        fprintf(Arq,"\n"); //Tabula��o
    }
}

/* Procedimento para exportar os valores na ordem em que foram inseridos (tipo pr�-ordem) aplicando recursividade */
ExportaEmOrdem(No *Raiz, FILE *Arq) //Varredura e-r-d (= inorder traversal = percurso em in-ordem) Ordem Raiz-Esquerda_Direita.
{
    if (Raiz != (No*) NULL) //Se o ponteiro passado como par�mentro for nulo
    {
        ExportaEmOrdem(Raiz-> Esquerda, Arq); //Sen�o chama novamente a fun��o indo para a esquerda
        fprintf(Arq, "%d ", Raiz->Id ); //Imprimindo o Id
        fprintf(Arq,"\n"); //Tabula��o
        ExportaEmOrdem(Raiz-> Direita, Arq); //E depois chamando novamente a fun��o indo para a direita
    }
}

/* Procedimento para exportar os valores na ordem em que foram inseridos (tipo p�s-ordem) aplicando recursividade */
ExportaEmOrdemInversa(No *Raiz, FILE *Arq)
{
    if (Raiz != (No*) NULL) //Se o ponteiro passado como par�mentro for nulo
    {
        ExportaEmOrdemInversa(Raiz-> Direita, Arq); //Chama novamente a fun��o indo para a direita
        fprintf(Arq,"%d ", Raiz->Id ); //Imprimindo o Id
        fprintf(Arq,"\n"); //Tabula��o
        ExportaEmOrdemInversa(Raiz-> Esquerda, Arq); //E chama novamente a fun��o indo para a esquerda
    }
}

/* Fun��o para importar os valores a partir de um arquivo */
No *Importa(No *Raiz)
{
	char NomeArq[MAX]; //O nome/caminho do arquivo conter� a quantidade m�xima de caracteres definida em MAX
	char linha[MAX]; //Guardar� at� a quantidade m�xima de caracteres lidos por linha
  	char *resultado;
  	int i; //Incrementado para a contagem de linha
  	int valor; //Conter� uma string convertida para inteiro e ser� inserido na �rvore
	
	FILE *Arq;
	
	printf("\n   Informe o nome/caminho do arquivo: ");
	gets(NomeArq);
	fflush(stdin); //Limpa o bufer de teclado evitando erros na coleta dos pr�ximos comandos
	
	Arq = fopen (NomeArq, "r"); //abre para leitura, guardando o endereco no ponteiro Arq

	if(Arq != NULL)
	{
		i = 1; //Inicia o contador com 1, afinal ele come�a a ler na linha 1.
	
    	while (!feof(Arq)) //while (fscanf(Arq, "%s", conteudo) != EOF) //enquanto nao for o final do arquivo (enquanto n�o for nulo)
    	{
    		// L� uma linha (inclusive com o '\n')
    	  	resultado = fgets(linha, MAX, Arq);  // o 'fgets' l� at� a quantidade m�xima de caracteres definida ou at� o '\n' (o que ocorrer primeiro)
      		if(resultado)  // Se foi poss�vel ler, retorna o resultado
	  		//printf("Linha %d : %s",i,linha); //Imprime o valor da linha adquidira
	  		valor = atoi(linha);
	  		Raiz = AdicionarNo(Raiz, valor);
      		i++; //Incrementa o contado de linha
    	}
    	fclose(Arq); //Fecha o arquivo
    	return Raiz; //Retorna a Raiz com os valores inseridos
    	printf("\n\n                         Impora%c%co realizada com sucesso!\n\n\n\n\n   ", 135, 198);
    	system("pause");
	}
	
    if(Arq == NULL) //Se n�o conseguir abrir o arquivo (pode ser escrito if ((Arq = fopen(NomeArq, "r")) == NULL))
    {
        printf("\n\n                             Arquivo n%co encontrado!\n\n\n\n\n   ", 198); //Exibe uma mensagem de erro para usu�rio
        system("pause");
        return;
    }
}
/* Fim do c�digo das fun��es de importa��o e exporta��o */



/* In�cio do c�digo para impress�o da AVL */
/* Procedimento que imprime na tela a �rvore completa com as liga��es de cada n� */
void ImprimeAVL(No *Raiz) //O n� principal � impresso antes da chamada no pr�prio menu
{  
    if(Raiz == NULL) //Se chegou a um n� nulo
    {
        return; //Retorna sem nada a fazer
    }
    
    if(Raiz != NULL) //Se ainda n�o encontrou um n� nulo
    {
        if(Raiz->Esquerda == NULL && Raiz->Direita == NULL) //Verifica se n�o h� n�s descendentes
        {
            printf("\n   %d n%co tem filhos", Raiz->Id, 198); //E constatado retorna a mensagem de que o n� n�o tem filhos
        }
        
        if(Raiz->Esquerda != NULL && Raiz->Direita != NULL) //Verifica se h� filho somente na esquerda
        {
            printf("\n   %d tem %d %c esquerda e %d %c direita", Raiz->Id, Raiz->Esquerda->Id, 133, Raiz->Direita->Id, 133);
        }
        
        if(Raiz->Esquerda != NULL && Raiz->Direita == NULL) //Verifica se h� filho somente na direita
        {
            printf("\n   %d tem %d %c esquerda e n%co tem filho %c direita", Raiz->Id, Raiz->Esquerda->Id, 133, 198, 133);
        }
        
        if(Raiz->Esquerda == NULL && Raiz->Direita != NULL) //Verifica se h� os dois filhos (direita e esquerda)
        {
            printf("\n   %d n%co tem filho %c esquerda e tem %d %c direita", Raiz->Id, 198, 133, Raiz->Direita->Id, 133);
        }
       
        ImprimeAVL(Raiz->Esquerda); //Recurs�o � esquerda
        ImprimeAVL(Raiz->Direita); //Recurs�o � direita
    }
}

/* Procedimento que imprime na tela a altura e fator de balanceamento de cada n� */
void Estatistica(No *Raiz) //O n� principal � impresso antes da chamada no pr�prio menu
{  
    if(Raiz == NULL) //Se chegou a um n� nulo
    {
        return; //Retorna sem nada a fazer
    }
    
    if(Raiz != NULL) //Se ainda n�o encontrou um n� nulo
    {
        printf("\n   %d tem Altura igual a %d e Fator de Balanceamento igual a %d", Raiz->Id, Raiz->Altura, Balanceamento(Raiz)); //E constatado retorna a mensagem com os valores
    }
    
    Estatistica(Raiz->Esquerda);
    Estatistica(Raiz->Direita);
}
/* Fim do c�digo para impress�o da AVL */



/* Inc�cio do corpo principal da aplica��o */
int main()
{
    configtela(); //Define os par�mentros de tela
	
	No *Raiz = (No*) NULL; //Define uma vari�vel (ponteiro) do tipo registro (No) como Nula

    imprime_tela_abertura(); //Imprime o cabe�alho da aplica��o
    
    system("pause"); //Pausa do sistema

    int Opt; //Vari�vel que recebe o comando do usu�rio (Menu)
    do
    {
        int Id; //Recebe o valor a ser inserido na �rvore
        
        limpa_tela(); //Limpa tela
        
        imprime_tela_cabecalho(); //Imprime o cabe�alho da aplica��o
        
        menu_principal(); //Imprime o menu principal na tela
        
        printf("                              1 - Inserir Manualmente\n");
        printf("                              2 - Inserir do Arquivo\n");
        printf("                              3 - Exibir Pr%c-Ordem\n", 130);
        printf("                              4 - Exibir P%cs-Ordem\n", 162);
        printf("                              5 - Exibir Em-Ordem\n");
        printf("                              6 - Exibir Em-Ordem Inversa\n");
        printf("                              7 - Buscar Elemento\n");
        printf("                              8 - Remover Elemento\n");
        printf("                              9 - Remover %crvore\n", 181);
        printf("                             10 - Altura da %crvore\n", 181);
        printf("                             11 - Exibir %crvore Completa\n", 181);        
        printf("                              0 - Sair\n\n\n");
        
        printf("   Informe a op%c%co: ", 135, 198);
        
        scanf("%d", &Opt);

		fflush(stdin); //Limpa o bufer de teclado evitando erros na coleta dos pr�ximos comandos
        
        if (Opt == 1)
        {
            printf("\n   Informe o Id: ");
            scanf("%d", &Id);
            Raiz = AdicionarNo(Raiz, Id);
        }
        
        if (Opt == 2)
        {
			Raiz = Importa(Raiz);
			//printf("\n\n                                 Op%c%co Indispon%cvel!\n\n\n\n\n\n\n  ", 135, 198, 161);
            //system("pause");
        }
        
        else if (Opt == 3)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                PreOrdem(Raiz); //Chama a fun��o para imprimir os dados na tela
                GravaPreOrdem(Raiz);

            }
            
            if(Raiz == (No*) NULL)
            {
                printf("\n\n                                A %crvore est%c vazia!\n\n\n\n\n\n   ", 160, 160);
            }

			system("pause");
        }
        
        else if (Opt == 4)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                PosOrdem(Raiz);
                GravaPosOrdem(Raiz);
            }

            if(Raiz == (No*) NULL)
            {
            printf("\n\n                                A %crvore est%c vazia!\n\n\n\n\n\n   ", 160, 160);
            }

			system("pause");
        }
        
        else if (Opt == 5)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                EmOrdem(Raiz);
                GravaEmOrdem(Raiz);
            }

            if(Raiz == (No*) NULL)
            {
            	printf("\n\n                                A %crvore est%c vazia!\n\n\n\n\n\n   ", 160, 160);
            }

            system("pause");
        }

        else if (Opt == 6)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                EmOrdemInversa(Raiz);
                GravaEmOrdemInversa(Raiz);
            }

            if(Raiz == (No*) NULL)
            {
            	printf("\n\n                                A %crvore est%c vazia!\n\n\n\n\n\n   ", 160, 160);
            }
            system("pause");
        }

        else if (Opt == 7)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                printf("\n   Informe o Id: ");
                scanf("%d", &Id);

                No *NoLocalizado = BuscarNo(Raiz, Id);
                
                if (NoLocalizado == (No*) NULL)
                    printf("\n                                 N%co localizado!\n\n\n\n\n   ", 198);
                else
                    printf("\n                            Localizado no endere%co %x\n\n\n\n\n   ", 135, NoLocalizado);
            }
            
            if(Raiz == (No*) NULL)
            {
                printf("\n\n                                A %crvore est%c vazia!\n\n\n\n\n\n   ", 160, 160);
            }
            system("pause");
        }
        
        else if (Opt == 8)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                printf("\n   Informe o Id: ");
                scanf("%d", &Id);
                printf("\n\n\n\n\n\n   ");
                Raiz = RemoverNo(Raiz, Id); //Esta linha faz a mesma coisa da linha de baixo, utiliza ponteiro para ponteiro na fun��o
            }
            
            if(Raiz == (No*) NULL)
            {
                printf("\n\n                                A %crvore est%c vazia!\n\n\n\n\n\n   ", 160, 160);
            }
            
        system("pause");
        }
        
        else if (Opt == 9)
        {
            printf("\n   ");
            if(Raiz != (No*) NULL)
            {
            	char RemoveAVL;
                printf("\n\n   Deseja realmente excluir toda a %crvore? [s=Sim / Qualquer tecla = N%co]: ", 160, 198);
                RemoveAVL = getch(RemoveAVL);
                RemoveAVL = tolower(RemoveAVL);

            	if(RemoveAVL == 's')
				{
					while(Raiz != NULL)
                	{
                		Raiz = RemoverAVL(Raiz);
                		printf("\n   ");
                	}
        	    }
        	else
				printf("\n\n\n\n\n\n   ");
            }
            
            if(Raiz == (No*) NULL)
            {
                printf("\n\n                                A %crvore est%c vazia!\n\n\n   ", 160, 160);
            }
            
        	system("pause");
        }

        else if (Opt == 10)
        {
            printf("\n\n                        A %crvore tem a altura igual a %d\n\n\n\n\n\n\n   ", 160, Altura(Raiz));
            system("pause");
        }

        else if (Opt == 11)
        {
        	printf("\n   ");
            if(Raiz != (No*) NULL)
            {
                limpa_tela(); //Limpa tela

                imprime_tela_cabecalho(); //Imprime o cabe�alho da aplica��o

                /* Fase 1 - Exibe apenas a �rvore completa com todas a liga��es */
                printf(" ==================================== LIGA%c%cES =================================\n", -128, -27);
   				printf("\n   %d %c o n%c principal desta %crvore", Raiz->Id, 130, 162, 160);
				ImprimeAVL(Raiz);

				printf("\n\n");

                /* Fase 2 - Exibe apenas a altura e o fator de balanceamento de cada n� da �rvore */               
                printf(" ======================== ALTURA E FATOR DE BALANCEAMENTO ======================\n");                
				Estatistica(Raiz);
				printf("\n\n\n   ");
            }
        else
            if(Raiz == (No*) NULL)
            {
            printf("\n\n                                A %crvore est%c vazia!", 160, 160);
            printf("\n                    (a altura de uma %crvore vazia %c igual a -1)\n\n\n\n\n   ", -96, -126);
            }
            system("pause");
        }

        else if (Opt == 0)
        {
            creditos();
        }

        else if (Opt > 11)
        {
            printf("\n\n                                 Op%c%co Inv%clida!\n\n\n\n\n\n\n  ", 135, 198, 160);
            system("pause");
        }

    } while (Opt != 0);

    return 0;
}
/* Fim do corpo principal da aplica��o */
