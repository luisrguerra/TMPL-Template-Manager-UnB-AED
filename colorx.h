enum cmd_cores {
    /*0*/cor_preto,           /*1*/cor_azul,           /*2*/cor_verde,        /*3*/cor_ciano,
	/*4*/cor_vermelho,        /*5*/cor_magenta,        /*6*/cor_marrom,       /*7*/cor_cinza_claro, 
	/*8*/cor_cinza,           /*9*/cor_azul_claro,     /*10*/cor_verde_claro, /*11*/cor_ciano_claro, 
	/*12*/cor_vermelho_claro, /*13*/cor_magenta_claro, /*14*/cor_amarelo,     /*15*/cor_branco,
	corteste};

void cor_texto (cmd_cores iColor);

void cor_fundo (cmd_cores iColor);

void trocar_cor_padrao_cmd_rgb(int cor,int red,int green,int blue);

void desabilitar_cursor(bool habilitado);

void imprimir_texto_colorido(cmd_cores cor,std::string texto);

void imprimir_texto_colorido(cmd_cores cor,cmd_cores fundo,std::string texto);

void tamanho_fonte(int tamanho);

void apagartela();
