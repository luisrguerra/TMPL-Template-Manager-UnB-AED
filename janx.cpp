#include <string>
#include <windows.h>

void janela_aviso_exclamacao (std::string texto, std::string titulo){
 MessageBox( 0, texto.c_str(), titulo.c_str(), 0 | MB_ICONEXCLAMATION );	
	
}

void janela_aviso_erro (std::string texto, std::string titulo){
 MessageBox( 0, texto.c_str(), titulo.c_str(), 0 | MB_ICONERROR );	
	
}

void janela_aviso_interrogacao (std::string texto, std::string titulo){
 MessageBox( 0, texto.c_str(), titulo.c_str(), 0 | MB_ICONQUESTION );	
	
}

void janela_aviso_informacao (std::string texto, std::string titulo){
 MessageBox( 0, texto.c_str(), titulo.c_str(), 0 | MB_ICONINFORMATION );	
	
}
void janela_aviso (std::string texto, std::string titulo){
 MessageBox( 0, texto.c_str(), titulo.c_str(), 0 );	
	
}

bool janela_sim_nao (std::string texto, std::string titulo){
	
    int bool_janela_sim_nao = MessageBox( 0, texto.c_str(), titulo.c_str(), MB_YESNO );
    switch (bool_janela_sim_nao){
  	case IDYES:
  		
  		return true;
  		
        break;
    case IDNO:
    	
    	return false;
    	
        break;
    }

}

bool janela_repetir_cancelar (std::string texto, std::string titulo){
	
	int bool_janelafinal = MessageBox( 0, texto.c_str(), titulo.c_str(), MB_RETRYCANCEL ); 
    
	switch (bool_janelafinal){
  	case IDRETRY:

        return true;
        break;
    case IDCANCEL:

        return false;
        break;
  }
}


bool janela_ok_cancelar (std::string texto, std::string titulo){
	
	int bool_janela_ok_cancelar = MessageBox( 0, texto.c_str(), titulo.c_str(), MB_OKCANCEL );
    switch (bool_janela_ok_cancelar){
  	case IDOK:
  		
  		return true;
        break;
    case IDCANCEL:

        return false;
        break;
  }
	
}
