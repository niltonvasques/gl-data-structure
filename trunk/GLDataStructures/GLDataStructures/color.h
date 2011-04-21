/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
  Autores: Nilton Vasques
  Data do ínicio da implementação: 20/04/2011
  Data da última modificação: 21/04/2011

  Implementação da classe Color que recebe como parametro valores RED, GREEN,
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