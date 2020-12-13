 #include <iostream>   // necessario para o cout
 //#include <locale.h>   // em algumas situacoes parece nao ser necessario  para o setlocale
 #include <string>     // necessario para usar variaveis de string
 //#include <windows.h>  // necessario para usar a janela de pergunta
 #include <fstream>    // necessario para gravar e ler arquivos com ofstream
 #include <sstream>
 #include <list>  
 #include <stdlib.h> // atoi() string para int
 
 #include "tagx.h"
 #include "janx.h"
 #include "interface.h"
 #include "notepad.h"
 #include "abrir.h"
 #include "arquivoz.h"
 #include "funcionamentoz.h"

 
 using namespace std;


 bool executar_programa(string nome_arquivo){
  //parametros
  arquivo_atual arquivo_atual_executar;
  arquivo_atual_executar.nome_arquivo = nome_arquivo;
  
  string formato  = arquivo_atual_executar.ler_parametros("formato");
  if(formato == "%#erro"){ //correcao de erro de digitação
  	 formato = "txt";
  }
  
  string codificacao  = arquivo_atual_executar.ler_parametros("codificacao");
  if(codificacao == "%#erro"){ //correcao de erro de digitação
  	 codificacao = "ansi";
  }
  
  //parametro numero de variaveis
  string numero_variaveis_string = arquivo_atual_executar.ler_parametros("numero:variaveis");
  int    numero_variaveis;
  if(numero_variaveis_string != "%#erro"){
 		
 		std::istringstream ( numero_variaveis_string ) >> numero_variaveis;
 		
  }else{
		numero_variaveis = 1;//correcao de erro de digitação
  }
  //fim parametro numero de variaveis
  
  
  //ler tags
  string tags       [numero_variaveis];
  string variaveis  [numero_variaveis];
  string dialogos   [numero_variaveis];
  int predefinicoes [numero_variaveis];
  list<string> opcoes_predefinidas [numero_variaveis];
  list<string> dialogo_predefinidas[numero_variaveis];


  
  for(int contagem = 0; contagem < numero_variaveis; contagem++){
  	int numero = contagem + 1;
  	
	string numero_string = int_para_string(numero);   
	
  	string parametro_tag      = numero_string + ":tag";
  	string parametro_variavel = numero_string + ":variavel";
  	string parametro_dialogo  = numero_string + ":dialogo";
	string parametro_predefinicoes  = numero_string + ":predefinicoes"; // numero de opções pre-definidas
  	
  	string tag_temp = arquivo_atual_executar.ler_parametros( parametro_tag );
  	if(tag_temp != "%#erro"){
  	   tags [contagem] = tag_temp;
	}else{
	   tags [contagem] = numero_string + ":variavel";//correcao de erro de digitação
	}
	
	string variavel_temp = arquivo_atual_executar.ler_parametros( parametro_variavel );
  	if(variavel_temp != "%#erro"){
  	   variaveis [contagem] = variavel_temp;
	}else{
	   variaveis [contagem] = "Variavel " + numero_string ;//correcao de erro de digitação
	}
	
	string dialogo_temp = arquivo_atual_executar.ler_parametros( parametro_dialogo );
  	if(dialogo_temp != "%#erro"){
  	   dialogos [contagem] = dialogo_temp;
	}else{
	   dialogos [contagem] = variaveis [contagem] ;//correcao de erro de digitação
	}
	
	string predefinicoes_temp = arquivo_atual_executar.ler_parametros( parametro_predefinicoes );
  	if(predefinicoes_temp != "%#erro"){
  	   predefinicoes [contagem] = atoi(predefinicoes_temp.c_str()); // atoi converte string int e c_str converte string para string const char
	}else{
	   predefinicoes [contagem] = 0 ;//correcao de erro de digitação
	}

  }
  
  
  //opcoes pre-estabelecidas
  for(int contagem = 0; contagem < numero_variaveis; contagem++){
  	
	  for(int contagem2 = 0; contagem2 < predefinicoes [contagem]; contagem2++){
  		
  		string numero_variavel = int_para_string(contagem + 1);
  		string numero_opcao    = int_para_string(contagem2 + 1);
  		
  		string parametro_opcoes_predefinidas  = numero_variavel + ":" + numero_opcao + ":opcao";
  		string parametro_dialogo_predefinidas = numero_variavel + ":" + numero_opcao + ":dialogo";
  		
  		string opcoes_predefinidas_temp = arquivo_atual_executar.ler_parametros( parametro_opcoes_predefinidas );
  	    if(opcoes_predefinidas_temp != "%#erro"){
  	        opcoes_predefinidas[contagem].push_back(opcoes_predefinidas_temp);
	    }else{
	         opcoes_predefinidas[contagem].push_back("");//correcao de erro de digitação
	    }
	    
	    string dialogo_predefinidas_temp = arquivo_atual_executar.ler_parametros( parametro_dialogo_predefinidas );
  	    if(dialogo_predefinidas_temp != "%#erro"){
  	        dialogo_predefinidas[contagem].push_back(dialogo_predefinidas_temp);
	    }else{
	         dialogo_predefinidas[contagem].push_back("Opção " + numero_opcao);//correcao de erro de digitação
	    }
  		
	  }
	  
  }
  
  
  
  
  //perguntar valores substitutos
  string valores_substitutos[numero_variaveis];
  for(int contagem = 0; contagem < numero_variaveis; contagem++){
  	 
	if (predefinicoes[contagem] == 0){
     valores_substitutos[contagem] = entrada_texto(
	/*Titulo Cor:*/cor_amarelo,
	/*Titulo:*/"Informações",
	/*Rodapé Cor:*/cor_branco,
	/*Rodapé:*/dialogos [contagem] + ":");
    }else{
    
	 list<string> lista_dialogos = dialogo_predefinidas[contagem];	
     string dialogo_selecionado = lista_setas(lista_dialogos, dialogos [contagem]);
    
    
	 int posicao = 0;
     for (list<string>::iterator i = lista_dialogos.begin(); i != lista_dialogos.end(); i++){
    	if (*i == dialogo_selecionado){
    		break;
		}
		posicao++;
	 }
	
	 list<string> lista_opcoes = opcoes_predefinidas[contagem];
	 string valor;
	 int posicao2 = 0;
	 for (list<string>::iterator i = lista_opcoes.begin(); i != lista_opcoes.end(); i++){
		if (posicao == posicao2){
			valor = *i;
			break;
		}
		posicao2++;
	 }

	 valores_substitutos[contagem] = valor;
	 
	 if (valores_substitutos[contagem] == "inserir"){
	 	
	 	 valores_substitutos[contagem] = entrada_texto(
	     /*Titulo Cor:*/cor_amarelo,
	     /*Titulo:*/dialogos[contagem],
	     /*Rodapé Cor:*/cor_branco,
	     /*Rodapé:*/dialogo_selecionado + ":");
	 }
    	
	}
  }
  //fim valores substitutos
  
  string nome_arquivo_novo_sem_formato = entrada_texto(
	/*Titulo Cor:*/cor_verde_claro,
	/*Titulo:*/"Arquivo a ser gerado",
	/*Rodapé Cor:*/cor_branco,
	/*Rodapé:*/"Nome do arquivo:");
  
  
  

  	
  string nome_arquivo_novo = nome_arquivo_novo_sem_formato + "." + formato;
  //parametros fim
  
  //declarando arquivo
  arquivo_novo arquivo_novo_executar;
  arquivo_novo_executar.nome_arquivo_novo = nome_arquivo_novo;
  arquivo_novo_executar.apagar();
  //declarando arquivo fim
  
  
  //ler arquivo
  ifstream arquivo_atual_leitura(nome_arquivo.c_str());
  
  string linha_leitura;
  bool permitir_gravar = false;
  
  while (getline (arquivo_atual_leitura, linha_leitura)) {
  
   bool permitir_gravar_tmp = false;
  
   string inicio_e_fim_arquivo = ler_tag ("arquivo",linha_leitura);
   if (inicio_e_fim_arquivo == "inicio"){
  	   permitir_gravar_tmp = true;
   }else if(inicio_e_fim_arquivo == "fim"){
  	  permitir_gravar = false;
   }
  
   string texto;
   for(int contagem = 0; contagem < numero_variaveis; contagem++){
   	texto = linha_leitura;
    while(texto != "$#erro"){
     
	  texto = substituir_tag(/*tag:*/tags [contagem], /*variavel:*/variaveis[contagem], /*string a ser lida:*/linha_leitura,/*texto substituto:*/valores_substitutos[contagem]); 
      if (texto != "$#erro"){
        linha_leitura = texto;
      }
    }
   }
  
   if (permitir_gravar == true){
   	
      arquivo_novo_executar.salvar_linha(linha_leitura);
   }
   if (permitir_gravar_tmp == true){
   
      permitir_gravar = true;
   }
   
  } // fim do while
  arquivo_atual_leitura.close();
  
  //finalizar
  if (codificacao == "utf8"){
  	converter_utf8(nome_arquivo_novo);
  }
  janela_aviso("O arquivo foi gerado com sucesso.","Arquivo salvo");
  
  dialogo_abrir_arquivo_com_programa_padrao( arquivo_novo_executar.diretorio() );
  notepad_dialogo( arquivo_novo_executar.diretorio() );
  dialogo_abrir_no_navegador_de_arquivos(".\\arquivos gerados\\","Deseja abrir o arquivo na pasta de destino?");
  //finalizar fim
 }
 

