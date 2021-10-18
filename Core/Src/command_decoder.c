#include "main.h"
#include <string.h>
#include <stdio.h>
#include "command_decoder.h"

Keyword asKeywordList[MAX_KEYWORD_NR] = {
		{INIT,"INIT"},
		{STRT,"STRT"},
		{STOP,"STOP"},
		{RUN,"RUN"},
		{RSTB,"RSTB"},
		{SRST,"SRST"},
		{CALB,"CALB"},
		{LIVE,"LIVE"},
		{M,"M"},
		{S,"S"},
		{H,"H"}
};

enum State {TOKEN,DELIMITER};
uint8_t ui8TokenCounter = 0;

uint8_t ui8FindTokensInString(char *pcString){
	enum State eState = DELIMITER;
		uint8_t ui8TokenCounter = 0;
		uint8_t ui8CharCounter = 0;
		char cActualChar;

		for(ui8CharCounter=0; pcString[ui8CharCounter] != NULL; ui8CharCounter++){
			cActualChar = pcString[ui8CharCounter];
			switch(eState){
				case DELIMITER:
					if(cActualChar == DELIMITER_CHAR){
						eState = DELIMITER;
					}else if(ui8TokenCounter < MAX_TOKEN_NR){
						eState = TOKEN;
						asToken[ui8TokenCounter].uValue.pcString = pcString + ui8CharCounter;
						ui8TokenCounter++;
					}else{
						return(ui8TokenCounter);
					}
					break;
				case TOKEN:
					if(cActualChar!= DELIMITER_CHAR){
						eState = TOKEN;
					}else{
						eState = DELIMITER;
					}
					break;
			}
		}
		return ui8TokenCounter;
}

Result eStringToKeyword(char pcStr[], KeywordCode *peKeywordCode){
	unsigned char ucKeywordCounter;

	for(ucKeywordCounter=0;ucKeywordCounter<MAX_KEYWORD_NR;ucKeywordCounter++){
		if(strcmp(pcStr,asKeywordList[ucKeywordCounter].cString) == 0){
			*peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
			return OK;

		}
	}
	return FAIL;
}

Result DecodeTokens(){

    unsigned int uiNumber;
    unsigned char ucTokenIndex;
    KeywordCode eKeyword;

    for(ucTokenIndex=0; ucTokenIndex < ui8TokenCounter; ucTokenIndex++){
        if((eStringToKeyword (asToken[ucTokenIndex].uValue.pcString, &eKeyword))== OK){
            asToken[ucTokenIndex].eType = KEYWORD;
            asToken[ucTokenIndex].uValue.eKeyword=eKeyword;
        }
        else if(sscanf(asToken[ucTokenIndex].uValue.pcString,"%u",&uiNumber) == 1){
            asToken[ucTokenIndex].eType = NUMBER;
            asToken[ucTokenIndex].uValue.uiNumber = uiNumber;
        }
        else{
            asToken[ucTokenIndex].eType = STRING;
        }
    }
    return OK;
}

void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	char *pString = pcString;
	while((pString = strchr(pString,cOldChar)) != NULL){
		*pString++ = cNewChar;
	}
}

void DecodeMsg(char *pcString){
	ui8TokenCounter = ui8FindTokensInString(pcString);
	ReplaceCharactersInString(pcString,DELIMITER_CHAR,NULL);
	DecodeTokens();
}


