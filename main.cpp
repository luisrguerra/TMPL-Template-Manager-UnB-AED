#include <locale.h>
#include <iostream> // necessario para o cout
#include <string> // necessario para usar recursos de string
#include <list>
#include <windows.h> // necessario para usar sleep

//#include <conio.h>

//#include "tagx.h"
//#include "colorx.h"
#include "janx.h"
#include "interface.h"
#include "funcionamento.h"
//#include "notepad.h"
#include "arquivosx.h"
#include "cores.h"

using namespace std;  //usado para não precisar std::

// indice do conteudo de AED abordado

//orientação a objeto: presente em "arquivoz.h", "notepad.h"
//listas presente em "funcionamento.cpp"
//busca: presente  em "tagx.h"
//metodos set e get: "notepad.h"
//Modificadores de visibilidade: "notepad.h"
//Erança de classe: "notepad.h"
//Encapisulamento: bibliotecas ".h" e ".cpp" no geral





int main() {
	setlocale(LC_ALL,"Portuguese");
	//setlocale(LC_ALL,"");
	//SetConsoleOutputCP ( 1252 );
    //SetConsoleCP ( 1252 );
	
	system("title Gerenciador TMPL");
	
	cores_padrao();
	
	std::list<string> lista_arquivos = listar_arquivos("./templates");
	lista_arquivos.push_front("Abrir diretório");
	lista_arquivos.push_front("Procurar arquivo");
    
    string nome_arquivo = lista_setas(lista_arquivos, "Selecione um template");
    
    if(nome_arquivo == "Abrir diretório"){
       #include "abrir.h"
       dialogo_abrir_no_navegador_de_arquivos(".\\templates\\","Deseja abrir a pasta que contém os templates?");
       main();
	}
    
	string diretorio_arquivo = "./templates/" + nome_arquivo;
	
	if(nome_arquivo == "Procurar arquivo"){
		//#include "abrir.h"
		diretorio_arquivo = dialogo_abrir_arquivo();
		if(diretorio_arquivo == "vazio"){
			main();
		}
	}
	
	executar_programa(diretorio_arquivo);


    
    bool reiniciar = janela_sim_nao ("Deseja reiniciar o programa?", "Reiniciar");
    if (reiniciar == true){
    	main();
	} else{
	return 0;	
	}
}
