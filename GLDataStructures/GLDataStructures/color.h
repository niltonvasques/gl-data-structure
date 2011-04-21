/*-----------------------------------------------------------------------------
  Universidade Cat�lica do Salvador - UCSAL
  Disciplina - Organiza��o de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autores: Nilton Vasques
  Data do �nicio da implementa��o: 20/04/2011
  Data da �ltima modifica��o: 21/04/2011

  Implementa��o da classe Color que recebe como parametro valores RED, GREEN,
  BLUE e ALPHA.
-----------------------------------------------------------------------------*/
#ifndef COLOR_H
#define COLOR_H

class Color{
	
public:
	Color(){Color(255, 255, 255);}
	Color(unsigned char red_, unsigned char green_, unsigned char blue_, unsigned char alpha_ = 255) :
	  red(red_),
	  green(green_),
	  blue(blue_),
	  alpha(alpha_)
	{}

	~Color(){}

	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

#endif