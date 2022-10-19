#ifndef TAC_TOKEN_H
#define TAC_TOKEN_H

typedef struct TOKEN_STRUCT
{
	char* value;

	enum
	{
		TOKEN_ID,
		TOKEN_INT,
		TOKEN_EQUALS,
		
		TOKEN_LPAREN,
		TOKEN_RPAREN,
		
		TOKEN_LBRACES,
		TOKEN_RBRACES,
		
		TOKEN_LESSTHAN,
		TOKEN_GREATERTHAN,

		TOKEN_COLON,
		TOKEN_COMMA,
		TOKEN_SEMICOLON,
		TOKEN_RIGHT_ARROW,
	} type;
} token_t;

token_t* init_token(char* value, int type);

#endif
