#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <ctype.h>

#include "TADtrab.h"
//------------------------------------------------------------------------------------------------------------
void Moldura(int CI, int LI, int CF, int LF, int cor)
{
	int i;
	
	//FundoMoldura(CI,LI,CF,LF,cor);
	textcolor(cor);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	textcolor(7);
}

//------------------------------------------------------------------------------------------------------------
char TelaInicial(void){
	char a;
	
	Moldura(20,1,100,18,1);	//moldura pequena
	textcolor(1);
	for(int i=20+1;i<100;i++)
	{
		gotoxy(i,4);
		printf("%c",205);
	}
	for(int i=20+1;i<100;i++)
	{
		gotoxy(i,16);
		printf("%c",205);
	}
	textcolor(7);
	gotoxy(52,2);
	printf("Trabalho Pratico");
	gotoxy(50,3);
	printf("Estruturas de Dados I");
	gotoxy(54,6);
	printf("- Iniciar -");
	gotoxy(52,7);
	textcolor(2);
	printf("PRESSIONE ENTER");
	gotoxy(53,11);
	textcolor(7);
	printf("- Finalizar -");
	gotoxy(58,12);
	textcolor(4);
	printf("ESC");
	textcolor(7);
	gotoxy(68,17);
	printf("Cassiano Biloria - Gabriel Kaito");
	gotoxy(22,17);
	printf("Opcao: ");
	
	gotoxy(29,17);
	
	a = getch();
	if(a == 27){
		textcolor(4);
		gotoxy(29,17);
		printf("- Finalizar -");
	}
	else{
		textcolor(2);
		gotoxy(29,17);
		printf("- Iniciar -");
		Sleep(800);
	}
	
	return a;
}

//------------------------------------------------------------------------------------------------------------
char TelaRetomada(void){
	char a;
	
	clrscr();
	Moldura(20,1,100,18,1);	//moldura pequena
	textcolor(1);
	for(int i=20+1;i<100;i++)
	{
		gotoxy(i,4);
		printf("%c",205);
	}
	for(int i=20+1;i<100;i++)
	{
		gotoxy(i,16);
		printf("%c",205);
	}
	textcolor(7);
	gotoxy(52,2);
	printf("Trabalho Pratico");
	gotoxy(50,3);
	printf("Estruturas de Dados I");
	gotoxy(28,6);
	printf("Finalizando tarefas pendentes para retomar a leitura do arquivo...");
	
	textcolor(7);
	gotoxy(54,13);
	printf("- Retomar -");
	gotoxy(52,14);
	textcolor(2);
	printf("PRESSIONE ENTER");

	textcolor(7);
	gotoxy(68,17);
	printf("Cassiano Biloria - Gabriel Kaito");
	gotoxy(22,17);
	printf("Opcao: ");
	
	gotoxy(29,17);
	
	a = getch();

	textcolor(2);
	gotoxy(29,17);
	printf("- Retomar -");
	Sleep(800);
	
	
	return a;
}
//------------------------------------------------------------------------------------------------------------
void TelaTarefasTerminadas(void){
	clrscr();
	Moldura(1,1,120,30,1);
	gotoxy(45,5);
	printf("Tarefas pendentes finalizadas");
	textcolor(2);
	gotoxy(35,10);
	printf("Pressione ENTER para retomar a leitura do arquivo");
	gotoxy(60,20);
	getch();
}

//------------------------------------------------------------------------------------------------------------
void TelaProcessos(void){
	Moldura(1,1,120,30,1);
	Moldura(3,3,23,8,1);
	Moldura(35,3,55,8,1);
	Moldura(67,3,87,8,1);
	Moldura(98,3,118,8,1);
	Moldura(3,12,118,28,1);
	
	gotoxy(22,9);
	printf("0");
	gotoxy(54,9);
	printf("0");
	gotoxy(86,9);
	printf("0");
	gotoxy(117,9);
	printf("0");
	
	
	gotoxy(7,2);
	printf("PROCESSADOR 1");
	gotoxy(39,2);
	printf("PROCESSADOR 2");
	gotoxy(71,2);
	printf("PROCESSADOR 3");
	gotoxy(102,2);
	printf("PROCESSADOR 4");
	gotoxy(3,9);
	printf("Processos na FILA: ");
	gotoxy(35,9);
	printf("Processos na FILA: ");
	gotoxy(67,9);
	printf("Processos na FILA: ");
	gotoxy(98,9);
	printf("Processos na FILA: ");
	gotoxy(6,13);
	printf("%c", 175);
	gotoxy(8,13);
	printf("Processador 1");
	
	gotoxy(6,17);
	printf("%c", 175);
	gotoxy(8,17);
	printf("Processador 2");
	
	gotoxy(6,21);
	printf("%c", 175);
	gotoxy(8,21);
	printf("Processador 3");
	
	gotoxy(6,25);
	printf("%c", 175);
	gotoxy(8,25);
	printf("Processador 4");
	
	
	gotoxy(94,29);
	printf("Tempo percorrido:");
	
	textcolor(4);
	gotoxy(2,29);
	printf("%c", 174);
	gotoxy(3,29);
	printf(" ESC");
}

void TelaFinal(DescProcessador DescP, int UT){
	TpProcessador *Processador = DescP.inicio;
	int totalGDI = 0, totalGDE = 0, totalDEL = 0, totalLER = 0, totalIMP = 0;
	clrscr();
	
	Moldura(1,1,120,30,1);
	textcolor(7);
	gotoxy(47,2);
	printf("Tempo total percorrido:");
	textcolor(2);
	gotoxy(55,3);
	printf("%d UT", UT);
	
	while(Processador != NULL){
		if(Processador -> numero == 1){
			textcolor(9);
			gotoxy(2,6);
			printf("%c Processador 1", 175);
			textcolor(7);
			gotoxy(3,7);
			printf("Gravar Dispositivo Interno: ");
			gotoxy(3,8);
			printf("Gravar Dispositivo Externo: ");
			gotoxy(3,9);
			printf("Deletar: ");
			gotoxy(3,10);
			printf("Ler: ");
			gotoxy(3,11);
			printf("Imprimir: ");
			gotoxy(3,12);
			printf("Total tarefas -  ");
			textcolor(11);
			gotoxy(31,12);
			printf("%d", Processador -> GDI + Processador -> GDE + Processador -> DEL + Processador -> IMP + Processador -> LER);
			
			textcolor(2);
			gotoxy(31,7);
			printf("%d", Processador -> GDI);
			gotoxy(31,8);
			printf("%d", Processador -> GDE);
			gotoxy(31,9);
			printf("%d", Processador -> DEL);
			gotoxy(31,10);
			printf("%d", Processador -> LER);
			gotoxy(31,11);
			printf("%d", Processador -> IMP);
			
			totalGDE = totalGDE + Processador -> GDE;
			totalGDI = totalGDI + Processador -> GDI;
			totalDEL = totalDEL + Processador -> DEL;
			totalIMP = totalIMP + Processador -> IMP;
 			totalLER = totalLER + Processador -> LER;

		}
		else if(Processador -> numero == 2){
				textcolor(9);
				gotoxy(87,5);
				printf("%c Processador 2", 175);
				textcolor(7);
				gotoxy(88,6);
				printf("Gravar Dispositivo Interno: ");
				gotoxy(88,7);
				printf("Gravar Dispositivo Externo: ");
				gotoxy(88,8);
				printf("Deletar: ");
				gotoxy(88,9);
				printf("Ler: ");
				gotoxy(88,10);
				printf("Imprimir: ");
				gotoxy(88,11);
				printf("Total tarefas -  ");
				textcolor(11);
				gotoxy(116,11);
				printf("%d", Processador -> GDI + Processador -> GDE + Processador -> DEL + Processador -> IMP + Processador -> LER);
				
				textcolor(2);
				gotoxy(116,6);
				printf("%d", Processador -> GDI);
				gotoxy(116,7);
				printf("%d", Processador -> GDE);
				gotoxy(116,8);
				printf("%d", Processador -> DEL);
				gotoxy(116,9);
				printf("%d", Processador -> LER);
				gotoxy(116,10);
				printf("%d", Processador -> IMP);
				
				totalGDE = totalGDE + Processador -> GDE;
				totalGDI = totalGDI + Processador -> GDI;
				totalDEL = totalDEL + Processador -> DEL;
				totalIMP = totalIMP + Processador -> IMP;
	 			totalLER = totalLER + Processador -> LER;
			
		}
		else if(Processador -> numero == 3){
				textcolor(9);
				gotoxy(2,14);
				printf("%c Processador 3", 175);
				textcolor(7);
				gotoxy(3,15);
				printf("Gravar Dispositivo Interno: ");
				gotoxy(3,16);
				printf("Gravar Dispositivo Externo: ");
				gotoxy(3,17);
				printf("Deletar: ");
				gotoxy(3,18);
				printf("Ler: ");
				gotoxy(3,19);
				printf("Imprimir: ");
				gotoxy(3,20);
				printf("Total tarefas -  ");
				textcolor(11);
				gotoxy(31,20);
				printf("%d", Processador -> GDI + Processador -> GDE + Processador -> DEL + Processador -> IMP + Processador -> LER);
				
				textcolor(2);
				gotoxy(31,15);
				printf("%d", Processador -> GDI);
				gotoxy(31,16);
				printf("%d", Processador -> GDE);
				gotoxy(31,17);
				printf("%d", Processador -> DEL);
				gotoxy(31,18);
				printf("%d", Processador -> LER);
				gotoxy(31,19);
				printf("%d", Processador -> IMP);
			
				totalGDE = totalGDE + Processador -> GDE;
				totalGDI = totalGDI + Processador -> GDI;
				totalDEL = totalDEL + Processador -> DEL;
				totalIMP = totalIMP + Processador -> IMP;
	 			totalLER = totalLER + Processador -> LER;
		}
		else{
			textcolor(9);
			gotoxy(87,14);
			printf("%c Processador 4", 175);
			textcolor(7);
			gotoxy(88,15);
			printf("Gravar Dispositivo Interno: ");
			gotoxy(88,16);
			printf("Gravar Dispositivo Externo: ");
			gotoxy(88,17);
			printf("Deletar: ");
			gotoxy(88,18);
			printf("Ler: ");
			gotoxy(88,19);
			printf("Imprimir: ");
			gotoxy(88,20);
			printf("Total tarefas -  ");
			textcolor(11);
			gotoxy(116,20);
			printf("%d", Processador -> GDI + Processador -> GDE + Processador -> DEL + Processador -> IMP + Processador -> LER);
			
			textcolor(2);
			gotoxy(116,15);
			printf("%d", Processador -> GDI);
			gotoxy(116,16);
			printf("%d", Processador -> GDE);
			gotoxy(116,17);
			printf("%d", Processador -> DEL);
			gotoxy(116,18);
			printf("%d", Processador -> LER);
			gotoxy(116,19);
			printf("%d", Processador -> IMP);
			
			totalGDE = totalGDE + Processador -> GDE;
			totalGDI = totalGDI + Processador -> GDI;
			totalDEL = totalDEL + Processador -> DEL;
			totalIMP = totalIMP + Processador -> IMP;
 			totalLER = totalLER + Processador -> LER;
		}
		Processador = Processador -> prox;
	}
	textcolor(1);
	for(int i=2;i<120;i++)
	{
		gotoxy(i,21);
		printf("%c",205);
	}
	textcolor(7);
	gotoxy(45,22);
	printf("Total por tipo de processo:");
	textcolor(2);
	gotoxy(54,24);
	printf("GDI: %d", totalGDI);
	gotoxy(54,25);
	printf("GDE: %d", totalGDE);
	gotoxy(54,26);
	printf("DEL: %d", totalDEL);
	gotoxy(54,27);
	printf("LER: %d", totalLER);
	gotoxy(54,28);
	printf("IMP: %d", totalIMP);
}

//------------------------------------------------------------------------------------------------------------
void GravaInfo(DescProcessador DescP, int UT, FILE *ptr){
	TpProcessador *Processador = DescP.inicio;
	TpTarefa *Tarefa;
	TpArq P1, P2, P3, P4;
	int contProcessador = 0;
	int posPtr = ftell(ptr);
	
	P1.processador = P2.processador = P3.processador = P4.processador = 0;
	
	while(Processador != NULL){
		contProcessador++;
		if(Processador -> numero == 1){
			P1.processador = 1;
			P1.GDI = Processador -> GDI;
			P1.GDE = Processador -> GDE;
			P1.DEL = Processador -> DEL;
			P1.LER = Processador -> LER;
			P1.IMP = Processador -> IMP;
		}
		else if(Processador -> numero == 2){
			P2.processador = 2;
			P2.GDI = Processador -> GDI;
			P2.GDE = Processador -> GDE;
			P2.DEL = Processador -> DEL;
			P2.LER = Processador -> LER;
			P2.IMP = Processador -> IMP;
		}
		else if(Processador -> numero == 3){
			P3.processador = 3;
			P3.GDI = Processador -> GDI;
			P3.GDE = Processador -> GDE;
			P3.DEL = Processador -> DEL;
			P3.LER = Processador -> LER;
			P3.IMP = Processador -> IMP;
		}	
		else{
			P4.processador = 4;
			P4.GDI = Processador -> GDI;
			P4.GDE = Processador -> GDE;
			P4.DEL = Processador -> DEL;
			P4.LER = Processador -> LER;
			P4.IMP = Processador -> IMP;
		}	
		Processador = Processador -> prox;
	} 
	FILE *ptrAux = fopen("i.txt", "w");
	rewind(ptrAux);
	fprintf(ptrAux, "%d,%d,%d\n", contProcessador, UT, posPtr);
	if(P1.processador != 0){
		fprintf(ptrAux, "%d,%d,%d,%d,%d,%d\n", P1.processador, P1.GDI, P1.GDE, P1.DEL, P1.LER, P1.IMP);
	}
	if(P2.processador != 0){
		fprintf(ptrAux, "%d,%d,%d,%d,%d,%d\n", P2.processador, P2.GDI, P2.GDE, P2.DEL, P2.LER, P2.IMP);
	}	
	if(P3.processador != 0){
		fprintf(ptrAux, "%d,%d,%d,%d,%d,%d\n", P3.processador, P3.GDI, P3.GDE, P3.DEL, P3.LER, P3.IMP);
	}
	if(P4.processador != 0){
		fprintf(ptrAux, "%d,%d,%d,%d,%d,%d\n", P4.processador, P4.GDI, P4.GDE, P4.DEL, P4.LER, P4.IMP);
	}
	Processador = DescP.inicio;
	while(Processador != NULL){
		Tarefa = Processador -> inicio;
		while(Tarefa != NULL){
			fprintf(ptrAux, "%d,%s,%s,%d\n", Processador -> numero, Tarefa -> nome, Tarefa -> processo, Tarefa -> tempo);
			Tarefa = Tarefa -> prox;
		}
		Processador = Processador -> prox;
	}
	fclose(ptrAux);
}


//------------------------------------------------------------------------------------------------------------
void Executar(FILE *ptrArq, DescProcessador &DescP, int &UT){
	char op = 32;
	int processador, tempoExec, aux = -1;
	char nomeArq[TF], tipoProcesso[TF];
	TpProcessador *i;
	
	clrscr();
	TelaProcessos();
	while(op != 27 && aux != 0){
		if(UT != 0)
			ReduzirTempo(DescP);	

		if(!feof(ptrArq) && UT%2 == 0){
			fscanf(ptrArq, "%d,%[^,],%[^,],%d\n", &processador, &nomeArq, &tipoProcesso, &tempoExec);

			if(DescP.inicio == NULL)
				DescP.inicio = DescP.fim = CriarProcessador(processador);

			i = BuscaProcessador(DescP, processador);

			if(i == NULL){
				DescP.fim -> prox = CriarProcessador(processador);		
				DescP.fim = DescP.fim -> prox;
				i = DescP.fim;
			}			
			Inserir(i, nomeArq, tipoProcesso, tempoExec); 
		}
		ExibirTeste(DescP);	
		if(feof(ptrArq))
			aux = Tarefas(DescP);
		textcolor(2);
		gotoxy(111,29);
		printf(" %d UT", UT);
		UT++;
		
		op = getch();	
		if(op == 49){
			i = BuscaProcessador(DescP, 1);
			FilaTarefas(i);
			clrscr();
			TelaProcessos();
		}
		if(op == 50){
			i = BuscaProcessador(DescP, 2);
			FilaTarefas(i);
			clrscr();
			TelaProcessos();
		}
		if(op == 51){
			i = BuscaProcessador(DescP, 3);
			FilaTarefas(i);
			clrscr();
			TelaProcessos();
		}
		if(op == 52){
			i = BuscaProcessador(DescP, 4);
			FilaTarefas(i);
			clrscr();
			TelaProcessos();
		}
		if(op == 27){
			FinalizaTarefas(DescP, UT);
			if(!feof(ptrArq))
				GravaInfo(DescP, UT, ptrArq);
		}		
	}
}

//------------------------------------------------------------------------------------------------------------
void ExecutarRetomada(FILE *ptrAux, FILE *ptrArq, int &UT, DescProcessador &DescP){
		TpArq ARQ;
		int qtdProcessador, aux = -1, pos;
		TpProcessador *Processador;
		
		TelaRetomada();
		rewind(ptrAux);
		fscanf(ptrAux, "%d,%d,%d\n", &qtdProcessador , &UT, &pos);
		fseek(ptrArq, pos, 0);

		
		for(int i = 0; i < qtdProcessador; i++){
			fscanf(ptrAux, "%d,%d,%d,%d,%d,%d\n", &ARQ.processador, &ARQ.GDI, &ARQ.GDE, &ARQ.DEL, &ARQ.LER, &ARQ.IMP);
			if(DescP.inicio == NULL){
				DescP.inicio = DescP.fim = CriarProcessador(ARQ.processador);
				DescP.inicio -> GDI = ARQ.GDI;
				DescP.inicio -> GDE = ARQ.GDE;
				DescP.inicio -> DEL = ARQ.DEL;
				DescP.inicio -> LER = ARQ.LER;
				DescP.inicio -> IMP = ARQ.IMP;
			}
			else{
				DescP.fim -> prox = CriarProcessador(ARQ.processador);
				DescP.fim = DescP.fim -> prox;
				DescP.fim -> GDI = ARQ.GDI;
				DescP.fim -> GDE = ARQ.GDE;
				DescP.fim -> DEL = ARQ.DEL;
				DescP.fim -> LER = ARQ.LER;
				DescP.fim -> IMP = ARQ.IMP;
			}	
		}
		while(!feof(ptrAux)){
			fscanf(ptrAux, "%d,%[^,],%[^,],%d\n", &ARQ.processador, &ARQ.nome, &ARQ.tipoProcesso, &ARQ.tempo);
			Processador = BuscaProcessador(DescP, ARQ.processador);
			Inserir(Processador, ARQ.nome, ARQ.tipoProcesso, ARQ.tempo); 
		}
		clrscr();
		TelaProcessos();//processos pendentes 
		aux = Tarefas(DescP);
		while(aux != 0){
			FinalizaTarefas(DescP, UT);
			aux = Tarefas(DescP);
		}
		fclose(ptrAux);
}

//------------------------------------------------------------------------------------------------------------
int main(void){
	FILE *ptrArq = fopen("texto.txt", "r");
	FILE *ptrAux = fopen("i.txt", "r");
	char op; 
	int UT;
	DescProcessador DescP;
	
	
	
	Inicializar(DescP); 
	rewind(ptrArq);
	
	if(ptrAux == NULL || feof(ptrAux)){
		fclose(ptrAux);
		UT = 0;
		op = TelaInicial();
		fscanf(ptrArq, "%*[^\n]\n");
		if(op != 27)
			Executar(ptrArq, DescP, UT);
	}	
	else{
		ExecutarRetomada(ptrAux, ptrArq, UT, DescP);
		TelaTarefasTerminadas();
		Executar(ptrArq, DescP, UT);
		if(feof(ptrArq))
			remove("i.txt");
	}
	TelaFinal(DescP, UT);
	
	fclose(ptrArq);
	getch();
}

//------------------------------------------------------------------------------------------------------------




