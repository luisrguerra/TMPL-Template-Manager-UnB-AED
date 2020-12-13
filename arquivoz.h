 #include <fstream>
  
 using namespace std;
 
  class arquivo_atual{
 	  public:
 	    string nome_arquivo;
	  
	    string ler_parametros(string tag){
	  	 setlocale(LC_ALL,"");
	  	 
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
 
 class arquivo_novo{
 	public:
 	string nome_arquivo_novo;
	
	string diretorio(){
	  return "./arquivos gerados/" + nome_arquivo_novo;
	}
	void apagar(){
		string diretorio_arquivo = diretorio();
		fstream arquivo_apagar(diretorio_arquivo.c_str(), /*apagar com trunc:*/ ios::out | ios::trunc );
		        arquivo_apagar.close();
	}
	void salvar_linha(string texto){
	
    string diretorio_arquivo = diretorio();
    
	
	fstream arquivo_iniciado(diretorio_arquivo.c_str(), /*escrever no final do arquivo:*/ ios::out | ios::app);
	 if (arquivo_iniciado.is_open()){
		   
		   arquivo_iniciado << texto << endl; ///escreve no arquivo
		   
		   arquivo_iniciado.close(); /// fecha o arquivo
     }
		
	}	
 	
 };
