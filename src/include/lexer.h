#ifndef TAC_LEXER_H
#define TAC_LEXER_H
#include "token.h"
#include <stdio.h>

typedef struct LEXER_STRUCT 
{
	char* src;
	size_t src_size;
	char c;
	unsigned int i;
} lexer_t;

lexer_t* init_lexer(char* src);

void lexer_advance(lexer_t* lexer);
void lexer_skip_whitespace(lexer_t* lexer);
token_t* lexer_next_token(lexer_t* lexer);
token_t* lexer_parse_id(lexer_t* lexer);
#endif
