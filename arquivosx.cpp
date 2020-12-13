 #include <iostream>
 //#include <locale.h>
 //#include <string>
 #include <fstream>
 //#include <vector>
 #include <list>
 
  using namespace std;

void listar_arquivos_salvar(string diretorio,string nome_arquivo_novo){
	 system("chcp 1252");
	 system("cls");
	 string comando_cmd = "dir /b /a-d \"" + diretorio + "\" > " + nome_arquivo_novo;
	 system(comando_cmd.c_str());
	 system("chcp 437");
	 system("cls");
}


std::list<std::string> listar_arquivos(std::string diretorio){
	 string linha_leitura;
	 listar_arquivos_salvar(diretorio,"listar_arquivos.temp");
	 
	 ifstream listar_arquivos_temp_leitura("listar_arquivos.temp");
     std::list<std::string> lista_arquivos;
     while (getline (listar_arquivos_temp_leitura, linha_leitura)) {
            lista_arquivos.push_back (linha_leitura);
     }
     
	 listar_arquivos_temp_leitura.close();
	 system("del /f listar_arquivos.temp");
	 return lista_arquivos;
}

std::string dialogo_abrir_arquivo(){
	system("dialogo_arquivo.bat");

    string linha_leitura;
	ifstream dialogo_arquivo_temp_leitura("filedialog.tmp");
	getline (dialogo_arquivo_temp_leitura, linha_leitura);
	
	dialogo_arquivo_temp_leitura.close();
	system("del filedialog.tmp");
	system("cls");
	if (linha_leitura.find("ECHO") != std::string::npos){
         return "vazio";
	}
    return linha_leitura;
	
}

