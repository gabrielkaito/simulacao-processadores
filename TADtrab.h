 #define TF 50

struct TpTarefa{
	char nome[TF];
	char processo[TF];
	int tempo, prioridade;
	TpTarefa *ant, *prox;
};


struct TpProcessador{
	int numero, fila;
	int GDI, GDE, DEL, LER, IMP;
	TpProcessador *prox;
	TpTarefa *inicio, *fim;
};

struct DescProcessador{
	TpProcessador *inicio, *fim;
};


//Struct auxiliar para a leitura/gravação em arquivos
struct TpArq{
	int processador, tempo, prioridade;
	char nome[TF], tipoProcesso[TF];
	int GDI, GDE, DEL, LER, IMP;
	
};



//------------------------------------------------------------------------------------------------------------
TpProcessador *CriarProcessador(int num){
	TpProcessador *Caixa = new TpProcessador;
	Caixa -> numero = num;
	Caixa -> prox = NULL;
	Caixa -> fila = Caixa -> GDI = 	Caixa -> GDE = Caixa -> DEL = Caixa -> LER = Caixa -> IMP = 0;
	Caixa -> inicio = Caixa -> fim = NULL;

	return Caixa;
}

//------------------------------------------------------------------------------------------------------------// OK
void Inicializar(DescProcessador &P){ 
	
	P.inicio = P.fim = NULL;
}

//---------------------------------------------------------------------------------------------------------
int ConversaoPrioridade(char tipoProcesso[TF]){
	if(stricmp(tipoProcesso, "Gravar Dispositivo Interno") == 0)
		return 1;
	else
		if(stricmp(tipoProcesso, "Gravar Dispositivo Externo") == 0)
			return 2;
		else
			if(stricmp(tipoProcesso, "Deletar") == 0)
				return 3;
			else
				if(stricmp(tipoProcesso, "Ler") == 0)
					return 4;
				else
					return 5;
}

//------------------------------------------------------------------------------------------------------------
TpTarefa *CriarCaixa(char nomeArq[TF], char tipoProcesso[TF], int tempoExec){
	TpTarefa *Caixa;
	
	Caixa = new TpTarefa;
	Caixa -> ant = Caixa -> prox = NULL;
	Caixa -> tempo = tempoExec;
	strcpy(Caixa -> nome, nomeArq);
	strcpy(Caixa -> processo, tipoProcesso);
	Caixa -> prioridade = ConversaoPrioridade(tipoProcesso);
	
	return Caixa;
}

//------------------------------------------------------------------------------------------------------------
void Inserir(TpProcessador *P,  char nomeArq[TF], char tipoProcesso[TF], int tempoExec){ 
	TpTarefa *CaixaTarefa, *Atual;
	TpTarefa AUX;
	
	CaixaTarefa = CriarCaixa(nomeArq, tipoProcesso, tempoExec);

	if(P -> inicio == NULL){
		P -> inicio = P -> fim = CaixaTarefa;
	}
	else{
		P -> fim -> prox = CaixaTarefa;
		CaixaTarefa -> ant = P -> fim;
		P -> fim = CaixaTarefa;	
		
		Atual = P -> fim;
		while(Atual -> ant != P -> inicio && Atual -> prioridade < Atual -> ant -> prioridade){
			strcpy(AUX.nome, Atual -> nome);
			strcpy(AUX.processo, Atual -> processo);
			AUX.tempo = Atual -> tempo;
			AUX.prioridade = Atual -> prioridade;
			
			strcpy(Atual -> nome, Atual -> ant -> nome);
			strcpy(Atual -> processo, Atual -> ant -> processo);
			Atual -> tempo = Atual -> ant -> tempo;
			Atual -> prioridade = Atual -> ant -> prioridade;
			
			strcpy(Atual -> ant -> nome, AUX.nome);
			strcpy(Atual -> ant -> processo, AUX.processo);
			Atual -> ant -> tempo = AUX.tempo;
			Atual -> ant -> prioridade = AUX.prioridade;
			
			Atual = Atual -> ant;
		}
		P -> fila++;
	}                                             
}

//------------------------------------------------------------------------------------------------------------
TpProcessador *BuscaProcessador(DescProcessador DescP, int num){
	TpProcessador *Atual;
	
	Atual = DescP.inicio;
	while(Atual != NULL && Atual -> numero != num)
		Atual = Atual -> prox;
	

	return Atual;
}


//------------------------------------------------------------------------------------------------------------
void ReduzirTempo(DescProcessador DescP){
	TpProcessador *Processador = DescP.inicio;
	TpTarefa *Tarefa;


	while(Processador != NULL){
		Tarefa = Processador -> inicio;

		if(Tarefa != NULL){
			Tarefa -> tempo--;
			
			if(Tarefa -> tempo == 0){
				
				if(Tarefa -> prioridade == 1)
					Processador -> GDI++;
				else
					if(Tarefa -> prioridade == 2)	
						Processador -> GDE++;
					else
						if(Tarefa -> prioridade == 3)
							Processador -> DEL++;
						else
							if(Tarefa -> prioridade == 4)
								Processador -> LER++;
							else
								Processador -> IMP++;
			
				Processador -> inicio = Tarefa -> prox;
				
				if(Processador -> inicio == NULL)
					Processador -> fim = NULL;
				else
					Processador -> inicio -> ant = NULL;
				
				delete(Tarefa);
				
				if(Processador -> fila > 0)
					Processador -> fila--;
			}
		}
		Processador = Processador -> prox;
	}
}

//------------------------------------------------------------------------------------------------------------
void LimpaTela(void){
	//Nome e processo
	gotoxy(8,14);
	printf("                                        ");
	gotoxy(8,15);
	printf("                                        ");
	gotoxy(8,18);
	printf("                                        ");
	gotoxy(8,19);
	printf("                                        ");
	gotoxy(8,22);
	printf("                                        ");
	gotoxy(8,23);
	printf("                                        ");
	gotoxy(8,26);
	printf("                                        ");
	gotoxy(8,27);
	printf("                                        ");
	//Tempo restante
	gotoxy(20,7);
	printf("   ");
	gotoxy(52,7);
	printf("   ");
	gotoxy(84,7);
	printf("   ");
	gotoxy(115,7);
	printf("   ");

}

//------------------------------------------------------------------------------------------------------------
void ExibirTeste(DescProcessador DescP){
	TpProcessador *Processador = DescP.inicio;
	TpTarefa *Tarefa;
	int i;
	LimpaTela();
	while(Processador != NULL){
		Tarefa = Processador -> inicio;
		if(Processador -> numero == 1){
			if(Tarefa != NULL){				
				textcolor(7);
				gotoxy(22,9);
				printf("%d", Processador -> fila);
				textcolor(2);
				gotoxy(5,4);
				printf("EXECUTANDO TAREFA");
				textcolor(7);
				gotoxy(5,7);
				printf("Tempo restante: ");

				textcolor(2);
				gotoxy(20,7);
				printf(" %d", Tarefa -> tempo);
				gotoxy(8,14);
				printf("%s", Tarefa -> nome);
				gotoxy(8,15);
				printf("%s", Tarefa -> processo);
			}
			else{
				textcolor(4);
				gotoxy(5,4);
				printf("   SEM TAREFAS   ");
				gotoxy(5,7);
				printf("                ");
			}
		}
		else
			if(Processador -> numero == 2){
				if(Tarefa != NULL){
					textcolor(7);
					gotoxy(54,9);
					printf("%d", Processador -> fila);
					textcolor(2);
					gotoxy(37,4);
					printf("EXECUTANDO TAREFA");
					textcolor(7);
					gotoxy(37,7);
					printf("Tempo restante: ");
					textcolor(2);
					gotoxy(52,7);
					printf(" %d", Tarefa -> tempo);
					gotoxy(8,18);
					printf("%s", Tarefa -> nome);
					gotoxy(8,19);
					printf("%s", Tarefa -> processo);
				}
				else{
					textcolor(4);
					gotoxy(37,4);
					printf("   SEM TAREFAS   ");
					gotoxy(37,7);
					printf("                ");
				}
			}
			else
				if(Processador -> numero == 3){
					if(Tarefa != NULL){	
						textcolor(7);
						gotoxy(86,9);
						printf("%d", Processador -> fila);
						textcolor(2);
						gotoxy(69,4);
						printf("EXECUTANDO TAREFA");
						textcolor(7);
						gotoxy(69,7);
						printf("Tempo restante: ");
						textcolor(2);
						gotoxy(84,7);
						printf(" %d", Tarefa -> tempo);
						gotoxy(8,22);
						printf("%s", Tarefa -> nome);
						gotoxy(8,23);
						printf("%s", Tarefa -> processo);
					}
					else{
						textcolor(4);
						gotoxy(69,4);
						printf("   SEM TAREFAS   ");
						gotoxy(69,7);
						printf("                ");
					}
				}
				else{
					if(Tarefa != NULL){
						textcolor(7);
						gotoxy(117,9);
						printf("%d", Processador -> fila);
						textcolor(2);
						gotoxy(100,4);
						printf("EXECUTANDO TAREFA");
						textcolor(7);
						gotoxy(100,7);
						printf("Tempo restante: ");
						textcolor(2);
						gotoxy(115,7);
						printf(" %d", Tarefa -> tempo);
						gotoxy(8,26);
						printf("%s", Tarefa -> nome);
						gotoxy(8,27);
						printf("%s", Tarefa -> processo);
					}
					else{
						textcolor(4);
						gotoxy(100,4);
						printf("   SEM TAREFAS   ");
						gotoxy(100,7);
						printf("                ");
					}
				}

		Processador = Processador -> prox;
	}
	//Sleep(250);
}

//------------------------------------------------------------------------------------------------------------
int Tarefas(DescProcessador DescP){
	TpProcessador *Processador = DescP.inicio;
	int i = 0, p = 0;
	
	while(Processador != NULL){
		p++;
		if(Processador -> inicio == NULL)
			i++;
		Processador = Processador -> prox;
	}
	if(p == i)
		return 0;
	else
		return -1;
}
//------------------------------------------------------------------------------------------------------------
void FinalizaTarefas(DescProcessador DescP, int &UT){
	TpProcessador *Processador = DescP.inicio; 
	TpTarefa *Tarefa;
	
	UT--;
	while(Processador != NULL){
		Tarefa = Processador -> inicio;
		if(Tarefa != NULL){
			while(Tarefa -> tempo != 0){
				Tarefa -> tempo--;
				UT++;
			}
			if(Tarefa -> prioridade == 1)
				Processador -> GDI++;
			else if(Tarefa -> prioridade == 2)	
					Processador -> GDE++;
			else if(Tarefa -> prioridade == 3)
					Processador -> DEL++;
			else if(Tarefa -> prioridade == 4)
					Processador -> LER++;
			else
				Processador -> IMP++;
		
			Processador -> inicio = Tarefa -> prox;
			
			if(Processador -> inicio == NULL)
				Processador -> fim = NULL;
			else
				Processador -> inicio -> ant = NULL;
			
			delete(Tarefa);
			
			if(Processador -> fila > 0)
				Processador -> fila--;
		}
		Processador = Processador -> prox;
	}
}


//------------------------------------------------------------------------------------------------------------
void FilaTarefas(TpProcessador *Processador){
	
	clrscr();
	if(Processador != NULL){
		TpTarefa *Tarefa = Processador -> inicio;
		int i = 5;
		
		if(Tarefa != NULL)
			Tarefa = Tarefa -> prox;
		else{
			textcolor(4);
			gotoxy(50,15);
			printf("FILA VAZIA");
		}
		textcolor(2);
		gotoxy(50,2);
		printf("Processador %d", Processador -> numero);
		if(Tarefa == NULL){
			textcolor(4);
			gotoxy(50,15);
			printf("FILA VAZIA");
		}
		else{
			while(Tarefa != NULL){
				textcolor(2);
				gotoxy(48,i);
				printf("%c", 175);
				textcolor(7);
				gotoxy(50,i);
				printf("%s", Tarefa -> nome);
				i++;
				Tarefa = Tarefa -> prox;
			}
		}
	}
	else{
		textcolor(4);
		gotoxy(50,15);
		printf("FILA VAZIA");
	}
	getch();
}
















