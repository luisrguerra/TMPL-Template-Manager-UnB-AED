#include "colorx.h"
//#include <vector>
#include <list>


std::string entrada_texto(cmd_cores titulo_cor,std::string titulo,cmd_cores rodape_cor,std::string rodape);
std::string entrada_texto(std::string titulo,std::string rodape);
std::string entrada_texto();


int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6, std::string opcao7, std::string opcao8, std::string opcao9);
int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6, std::string opcao7, std::string opcao8);
int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6, std::string opcao7);
int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5, std::string opcao6);
int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4, std::string opcao5);
int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3, std::string opcao4);
int selecionar_opcoes(std::string opcao1, std::string opcao2, std::string opcao3);
int selecionar_opcoes(std::string opcao1, std::string opcao2);

void pular_linha(int numero_de_linhas);

int lista_setas(int,std::string opcoes[], std::string titulo);

std::string lista_setas (std::list<std::string> lista_vetor, std::string titulo);



