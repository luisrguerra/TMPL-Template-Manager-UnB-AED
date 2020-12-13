#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <list>

#include "colorx.h"
#include "janx.h"
#include "teclax.h"


 void pular_linha(int numero_de_linhas){ // ex: pular_linha(1); //pula uma linha
      for(int contagem = 1; contagem <= numero_de_linhas; contagem++){
	  std::cout << std::endl;
	  }
 }



std::string entrada_texto(cmd_cores titulo_cor,std::string titulo,cmd_cores rodape_cor,std::string rodape){
	system("cls");
	tamanho_fonte(38);
	system("MODE 40, 13");
	
	
	
	imprimir_texto_colorido(/*cor texto:*/titulo_cor,/*cor fundo:*/cor_preto ,/*texto:*/titulo.substr(0, 39) + "\n");
	
	pular_linha(10);
	
	imprimir_texto_colorido(/*cor texto:*/rodape_cor,/*cor fundo:*/cor_preto ,/*texto:*/rodape.substr(0, 39) + "\n");
	
	std::string entrada;
	
	SetConsoleOutputCP ( 1252 );//corrigir bug de acentuação
    SetConsoleCP ( 1252 ); //corrigir bug de acentuação
	getline (std::cin, entrada);
	system("cls");
	return entrada;
}
std::string entrada_texto(std::string titulo,std::string rodape){
	return entrada_texto(cor_branco,titulo,cor_branco,rodape);
}
std::string entrada_texto(){
	return entrada_texto(cor_branco,"Entrada de texto",cor_branco,"Texto:");
}


int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6, std::string opcao7, std::string opcao8, std::string opcao9){
	system("cls");
	desabilitar_cursor(true);
	tamanho_fonte(38);
	system("MODE 40, 13");
	
	
	imprimir_texto_colorido(/*cor texto:*/cor_amarelo,/*cor fundo:*/cor_preto ,/*texto:*/"Selecione uma opção\n");
	
	pular_linha(1);
	
	if(opcao1 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"1) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao1.substr(0, 36) +"\n");
	
	if(opcao2 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"2) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao2.substr(0, 36) +"\n");
	
	if(opcao3 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"3) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao3.substr(0, 36) +"\n");
	
	if(opcao4 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"4) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao4.substr(0, 36) +"\n");
	
	if(opcao5 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"5) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao5.substr(0, 36) +"\n");
	
	if(opcao6 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"6) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao6.substr(0, 36) +"\n");
	
	if(opcao7 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"7) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao7.substr(0, 36) +"\n");
	
	if(opcao8 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"8) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao8.substr(0, 36) +"\n");
	
	if(opcao9 != ""){
	 imprimir_texto_colorido(/*cor texto:*/cor_verde_claro,/*cor fundo:*/cor_preto ,/*texto:*/"9) ");
	}
	imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/opcao9.substr(0, 36) +"\n");
	
	
	


	int tecla = getch();
	system("cls");
	desabilitar_cursor(false);
	if (tecla == 49){
		return 1;
	}
	else if (tecla == 50){
		return 2;
	}
	else if (tecla == 51){
		return 3;
	}
	else if (tecla == 52){
		return 4;
	}
	else if (tecla == 53){
		return 5;
	}
	else if (tecla == 54){
		return 6;
	}
	else if (tecla == 55){
		return 7;
	}
	else if (tecla == 56){
		return 8;
	}
	else if (tecla == 57){
		return 9;
	}
	else{
		return 0;
	}
}

int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6, std::string opcao7, std::string opcao8){
	
	return selecionar_opcoes(opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, opcao8, "");
}

int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6, std::string opcao7){
	
	return selecionar_opcoes(opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, opcao7, "", "");
}

int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6){
	
	return selecionar_opcoes(opcao1, opcao2, opcao3, opcao4, opcao5, opcao6, "", "", "");
}

int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5){
	
	return selecionar_opcoes(opcao1, opcao2, opcao3, opcao4, opcao5, "", "", "", "");
}

int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4){
	
	return selecionar_opcoes(opcao1, opcao2, opcao3, opcao4, "", "", "", "", "");
}

int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3){
	
	return selecionar_opcoes(opcao1, opcao2, opcao3, "", "", "", "", "", "");
}

int selecionar_opcoes(std::string opcao1, std::string opcao2){
	
	return selecionar_opcoes(opcao1, opcao2, "", "", "", "", "", "", "");
}







int lista_setas(int tamanho,std::string opcoes[], std::string titulo){
	
	desabilitar_cursor(true);
	system("cls");
	tamanho_fonte(38);
	system("MODE 40, 13");
	
	SetConsoleOutputCP ( 860 );//corrigir bug de acentuação
    SetConsoleCP ( 860 ); //corrigir bug de acentuação
	
	int tamanho_maximo = 11;
	int posicao = 0;
	int selecionado = 0;
	int tamanho_lista = tamanho;
	
	bool rodando = true;
	while (rodando == true){
	
	// \22 seta pra cima e para baixo
	// \21 seta pra esquerda
	// \20 seta pra direita
	// \26 barra grossa no meio
	// \27 seta pra cima e para baixo e barra em baixo
	// \30 seta pra cima
	// \31 seta pra baixo
	// \32 seta pra direita
	// \34 canto esquerda baixo
	// \35 seta esquerda direita
	// \36 seta pra cima
	// \36 seta pra baixo
	
	std::string titulo_str = "  " + titulo + "\n";
	imprimir_texto_colorido(/*cor texto:*/cor_amarelo,/*cor fundo:*/cor_preto ,/*texto:*/ titulo_str);
	
	
	
	if (tamanho_lista > tamanho_maximo){
		tamanho_lista = tamanho_maximo;
	}
	
	for (int contagem = 0; contagem < tamanho_lista; contagem++){
		std::string string_texto = opcoes[contagem + (selecionado - posicao)] + "                                    ";
		string_texto = string_texto.substr(0, 37);
		
		if(posicao == contagem){
		imprimir_texto_colorido(/*cor texto:*/cor_preto,/*cor fundo:*/cor_branco ,/*texto:*/"->" + string_texto +"\n");	
		}
		else{
		imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/ "  " +  string_texto +"\n");		
		}
	}
	
	char tecla = tecla_prescionada();
    if (tecla == 80){//para baixo
    	posicao = posicao + 1;
    	selecionado = selecionado +1;
    	
	}
	else if (tecla == 72){//para cima
    	posicao = posicao - 1;
    	selecionado = selecionado -1;
    	
	}
	else if (tecla == '\r'){//enter
    	apagartela();
	    desabilitar_cursor(false);
		return selecionado + 1;
    	
	}
	
	
	
	if(posicao < 0){
		posicao = 0;
	}
	if(selecionado < 0){
		selecionado = 0;
	}
	if(selecionado > (tamanho -1)){
		selecionado = tamanho -1;
	}

	
	if(posicao >= tamanho_lista -1){
		posicao = tamanho_lista -1;
	}
	apagartela();
	
	}//fim do while
	
	
	apagartela();
	desabilitar_cursor(false);
}


std::string lista_setas(std::list<std::string> lista, std::string titulo){

	
	desabilitar_cursor(true);
	system("cls");
	tamanho_fonte(38);
	system("MODE 40, 13");
	
	SetConsoleOutputCP ( 860 );//corrigir bug de acentuação
    SetConsoleCP ( 860 ); //corrigir bug de acentuação
	
	int tamanho_maximo = 11;
	int posicao = 0;
	int selecionado = 0;
	int tamanho = lista.size();
	int tamanho_lista = tamanho;
	
	std::string opcoes[tamanho];
	int posicao_array = 0;
	for(std::list<std::string>::iterator it = lista.begin(); it != lista.end() ; it++){
		opcoes[posicao_array] = *it;
		posicao_array++;
	}
	
	bool rodando = true;
	while (rodando == true){
	
	// \22 seta pra cima e para baixo
	// \21 seta pra esquerda
	// \20 seta pra direita
	// \26 barra grossa no meio
	// \27 seta pra cima e para baixo e barra em baixo
	// \30 seta pra cima
	// \31 seta pra baixo
	// \32 seta pra direita
	// \34 canto esquerda baixo
	// \35 seta esquerda direita
	// \36 seta pra cima
	// \36 seta pra baixo
	
	std::string titulo_str = "  " + titulo + "\n";
	imprimir_texto_colorido(/*cor texto:*/cor_amarelo,/*cor fundo:*/cor_preto ,/*texto:*/ titulo_str);
	
	
	
	if (tamanho_lista > tamanho_maximo){
		tamanho_lista = tamanho_maximo;
	}
	
	for (int contagem = 0; contagem < tamanho_lista; contagem++){
		std::string string_texto = opcoes[contagem + (selecionado - posicao)] + "                                    ";
		string_texto = string_texto.substr(0, 37);
		
		if(posicao == contagem){
		imprimir_texto_colorido(/*cor texto:*/cor_preto,/*cor fundo:*/cor_branco ,/*texto:*/"->" + string_texto +"\n");	
		}
		else{
		imprimir_texto_colorido(/*cor texto:*/cor_branco,/*cor fundo:*/cor_preto ,/*texto:*/ "  " +  string_texto +"\n");		
		}
	}
	
	char tecla = tecla_prescionada();
    if (tecla == 80){//para baixo
    	posicao = posicao + 1;
    	selecionado = selecionado +1;
    	
	}
	else if (tecla == 72){//para cima
    	posicao = posicao - 1;
    	selecionado = selecionado -1;
    	
	}
	else if (tecla == '\r'){//enter
    	apagartela();
	    desabilitar_cursor(false);
		return opcoes [selecionado];
    	
	}
	
	
	
	if(posicao < 0){
		posicao = 0;
	}
	if(selecionado < 0){
		selecionado = 0;
	}
	if(selecionado > (tamanho -1)){
		selecionado = tamanho -1;
	}

	
	if(posicao >= tamanho_lista -1){
		posicao = tamanho_lista -1;
	}
	apagartela();
	
	}//fim do while
	
	
	apagartela();
	desabilitar_cursor(false);
}
