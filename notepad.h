void abrir_no_notepad(std::string arquivo);

void abrir_no_notepad_plus_plus(std::string arquivo);

class notepad{
	private:
	std::string nome;
	
	public:
	void set(std::string nome_set){
		 nome = nome_set;
		
	}
	
	std::string get(){
		 return nome;
		
	}
	
	void notepad_windows(){
		std::string comando_cmd = "start Notepad \""  + nome + "\"";
	    system(comando_cmd.c_str());
	}
	
	void notepad_plus_plus(){
		std::string comando_cmd = "start ./notepad++/notepad++.exe \""  + nome + "\"";
	    system(comando_cmd.c_str());
	}
	 
};

class abrir_no : public notepad{
	public:
	void app_padrao(){
		std::string comando_cmd = "\"" + get() + "\"";
	    system(comando_cmd.c_str());
	}
	
};
