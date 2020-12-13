//#include <iostream> // necessario para o cout
#include <string> // necessario para usar recursos de string
#include <windows.h> // necessario para usar sleep

void abrir_no_notepad(std::string arquivo){
  	std::string comando_cmd = "start Notepad \""  + arquivo + "\"";
	system(comando_cmd.c_str());
}

void abrir_no_notepad_plus_plus(std::string arquivo){
  	std::string comando_cmd = "start ./notepad++/notepad++.exe \""  + arquivo + "\"";
	system(comando_cmd.c_str());
}
