 #include <iostream>   // necessario para o cout
 //#include <locale.h>   // em algumas situacoes parece nao ser necessario  para o setlocale
 //#include <string>     // necessario para usar variaveis de string
 //#include <windows.h>  // necessario para usar a janela de pergunta
 #include <fstream>    // necessario para gravar e ler arquivos com ofstream
 #include <sstream>
 
 #include "tagx.h"
 #include "janx.h"
 #include "interface.h"
 #include "notepad.h"

 
 using namespace std;
 
 class arquivo_atual{
 	  public:
 	  string nome_arquivo;
	  
	  string ler_parametros(string tag){
	  	
	  	string linha_leitura;
	  	
	  	ifstream arquivo_atual_leitura(nome_arquivo.c_str());
	  	while (getline (arquivo_atual_leitura, linha_leitura)){
	  		
	  	 string checar_fim_parametros = ler_tag ("arquivo", linha_leitura);
	  	 if(checar_fim_parametros == "inicio"){
	  	 	break;
		 }
	  	 
	  	 string leitura_de_parametro = ler_tag (tag, linha_leitura);
	  	 if (leitura_de_parametro != "%#erro")	{
	  		return leitura_de_parametro;
		 }	
		}
		
		arquivo_atual_leitura.close();
		return "%#erro";
	  }
	  
	  
	  
	  
 };
