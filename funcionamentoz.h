void converter_utf8(string nome_arquivo){
 	string comando = "powershell -NoProfile -command \"Get-Content '.\\arquivos gerados\\" + nome_arquivo +"' | Out-File -encoding utf8 -filepath '.\\arquivos gerados\\" + "utf8" + nome_arquivo +"' \"";
	system(comando.c_str());
    string comando2 = "del \".\\arquivos gerados\\" + nome_arquivo + "\"";
    system(comando2.c_str());
    string comando3 = "rename \".\\arquivos gerados\\utf8" + nome_arquivo + "\" \"" + nome_arquivo + "\"";
    system(comando3.c_str());

}

 string int_para_string(int numero){
 	ostringstream convert;
  	convert << numero; 
	return convert.str();   
 }
