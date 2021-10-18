#ifndef SRC_COMMAND_DECODER_H_
#define SRC_COMMAND_DECODER_H_

/*
 * KEYWORDCODE legend:
 * INIT - initialize a gates
 * RUN - value of a encirclements
 * RSTB- reset the gate after the end of the race
 * SRST - reset the microcontroller
 * CALB - callibartion of the gates (rather auto)
 * LIVE - check if the gate is alive
 * M - minutes
 * S - seconds
 * H - miliseconds
 * ALIVE - check if gates are alive
 */
typedef enum {INIT,RUN,RSTB,SRST,STRT,STOP,CALB,LIVE,M,S,H} KeywordCode;
typedef enum { KEYWORD, NUMBER, STRING} TokenType ;
typedef enum { OK, FAIL } Result;

#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 4
#define MAX_KEYWORD_NR 10
#define DELIMITER_CHAR '+'

typedef union {
	KeywordCode eKeyword;
	unsigned int uiNumber;
	char *pcString;
} TokenValue;

typedef struct {
	TokenType eType;
	TokenValue uValue;
}Token;


typedef struct {
	KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
}Keyword;


Keyword asKeywordList[MAX_KEYWORD_NR];
Token asToken[MAX_TOKEN_NR];
extern uint8_t ui8TokenCounter;

void DecodeMsg(char *pcString);


#endif /* SRC_COMMAND_DECODER_H_ */
