#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

lexer_t* init_lexer(char* src){
	lexer_t* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
	lexer->src = src;
	lexer->src_size = strlen(src);
	lexer->i = 0;
	lexer->c = src[lexer->i];

	return lexer;
}

void lexer_advance(lexer_t* lexer)
{
	if (lexer->i < lexer->src_size && lexer->c != '\0')
	{
		lexer->i += 1;
		lexer->c = lexer->src[lexer->i];
	}
}

void lexer_skip_whitespace(lexer_t* lexer)
{
	while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
	{
		lexer_advance(lexer);
	}
}

token_t* lexer_parse_id(lexer_t* lexer)
{
	char* value = calloc(1, sizeof(char));
	while(isalnum(lexer->c))
	{
		value = realloc(value, (strlen(value) + 2) * sizeof(char));
		strcat(value, (char[]){lexer->c, 0} );
		lexer_advance(lexer);
	}

	return init_token(value, TOKEN_ID);
}

token_t* lexer_next_token(lexer_t* lexer)
{
	while(lexer->c != '\0')
	{
		if (isalnum(lexer->c))
		{
			return lexer_advance_with(lexer_parse_id(lexer));
		}
	}
}
