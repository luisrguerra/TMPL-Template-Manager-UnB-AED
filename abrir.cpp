 #include <iostream>   // necessario para o cout

 #include "janx.h"
 #include "interface.h"
 #include "notepad.h"

 
 using namespace std;

void dialogo_abrir_arquivo_com_programa_padrao(string arquivo_diretorio){
 	bool bool_abrir_arquivo_com_programa_padrao = janela_sim_nao ("Deseja abrir o arquivo no programa padrão?","Abrir arquivo");
 	
	if (bool_abrir_arquivo_com_programa_padrao == true){
	 	
	 	abrir_no arquivo;
	 	arquivo.set(arquivo_diretorio);
	 	arquivo.app_padrao();
 		//std::string comando_cmd = "\"" + arquivo_diretorio + "\"";
	    //system(comando_cmd.c_str());
	}
 	
}

void dialogo_abrir_no_navegador_de_arquivos(string diretorio,string descricao){
 	bool bool_abrir_no_navegador_de_arquivos = janela_sim_nao (descricao,"Abrir pasta");
 	
	if (bool_abrir_no_navegador_de_arquivos == true){
	 	
 		std::string comando_cmd = "explorer \"" + diretorio + "\"";
	    system(comando_cmd.c_str());
	}
}

void notepad_dialogo(string arquivo_diretorio){
	bool bool_abrir_no_notepad = janela_sim_nao ("Deseja abrir o arquivo no notepad?","Abrir arquivo");
	if (bool_abrir_no_notepad == true){
	 
	 string opcoes_abrir_arquivo[2] = {"Abrir no Notepad do Windows","Abrir no Notepad++"};
	 int opcoes_abrir_arquivo_resultado = lista_setas(2,opcoes_abrir_arquivo, "Selecione em qual abrir");
	 
	 notepad abrir_bloco;
     abrir_bloco.set(arquivo_diretorio);
        
     if (opcoes_abrir_arquivo_resultado == 1){
     	
     	abrir_bloco.notepad_windows();
		//abrir_no_notepad();
		system("cls");
     	
	 }else if (opcoes_abrir_arquivo_resultado == 2){
		
		abrir_bloco.notepad_plus_plus();
		//abrir_no_notepad_plus_plus(arquivo_diretorio);
		system("cls");
		
	 }	
	}
	
}
