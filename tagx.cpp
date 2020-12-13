 #include <iostream>

using namespace std;
 string ler_tag(string tag,string string_leitura ){
	
	//montar automáticamente as strings de tag inicial e final para serem procuradas depois
	string tag_inicial = "<"  + tag + ">";
	string tag_final   = "</" + tag + ">";
	//cout << tag_inicial << endl;
	//cout << tag_final << endl;
	
	// Procurar a posição inicial da tag inical na string que está sendo lida
	size_t posicao_tag_inicial = /*string a ser analisada:*/string_leitura .find(/*procurar:*/tag_inicial);
	//cout << posicao_tag_inicial << endl;
	
	// Procurar a posição inicial da tag final na string que está sendo lida
	size_t  posicao_tag_final = /*string a ser analisada:*/string_leitura .find(/*procurar:*/tag_final);
	//cout << posicao_tag_final << endl;
	
	//checar se há erro
	// Se a tag inicial ou final não forem encontradas retorna erro
	if ( posicao_tag_inicial == string::npos || posicao_tag_final == string::npos ){
	 return "%#erro";
	}
	
	//posição inicial do texto contido na tag
	size_t inicio = posicao_tag_inicial +tag_inicial.size();
	//posição final do texto contido na tag
	size_t final  = posicao_tag_final - posicao_tag_inicial -tag_inicial.size();
	
	//Retornar o texto contido dentro tag buscada
	return string_leitura .substr( inicio , final);
}

 string ler_tag_subtag(string tag, string subtag,string string_leitura ){
	
	//montar automáticamente as strings de tag inicial e final para serem procuradas depois
	string tag_inicial = "<" + subtag + ":" + tag + ">";
	string tag_final   = "</" + subtag + ":" + tag + ">";
	//cout << tag_inicial << endl;
	//cout << tag_final << endl;
	
	// Procurar a posição inicial da tag inical na string que está sendo lida
	size_t posicao_tag_inicial = /*string a ser analisada:*/string_leitura .find(/*procurar:*/tag_inicial);
	//cout << posicao_tag_inicial << endl;
	
	// Procurar a posição inicial da tag final na string que está sendo lida
	size_t  posicao_tag_final = /*string a ser analisada:*/string_leitura .find(/*procurar:*/tag_final);
	//cout << posicao_tag_final << endl;
	
	//checar se há erro
	// Se a tag inicial ou final não forem encontradas retorna erro
	if ( posicao_tag_inicial == string::npos || posicao_tag_final == string::npos ){
	 return "%#erro";
	}
	
	//posição inicial do texto contido na tag
	size_t inicio = posicao_tag_inicial +tag_inicial.size();
	//posição final do texto contido na tag
	size_t final  = posicao_tag_final - posicao_tag_inicial -tag_inicial.size();
	
	//Retornar o texto contido dentro tag buscada
	return string_leitura .substr( inicio , final);
}

string substituir_tag (string tag, string variavel_da_tag, string string_leitura, string string_substituta){
	
	//montar automáticamente as strings de tag inicial e final para serem procuradas depois
	string tag_completa = "<"  + tag + ">" + variavel_da_tag + "</" + tag + ">";
	//cout <<"tag completa: " << tag_completa << endl;
	
	
	// Procurar a posição inicial da tag completa na string que está sendo lida
	size_t posicao_tag_completa = /*string a ser analisada:*/string_leitura .find(/*procurar:*/tag_completa);
	//cout << posicao_tag_completa << endl;
	
	
	//checar se há erro
	// Se a tag completa não for encontrada retorna erro
	if ( posicao_tag_completa == string::npos ){
	 return "$#erro";
	}
	
	//posição inicial da tag
	size_t inicio = posicao_tag_completa;
	//posição final dda tag
	size_t final  = tag_completa.size();
	
	//Retornar a string_leitura modificada com a tag substituida
	return string_leitura .replace( inicio, final, string_substituta);
	
	
 }	

