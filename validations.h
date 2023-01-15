
int isChars(char* row);
int properId(char* row);
int checkCoursName(char* row);
int isScore(char* row);
int checkNamesData(char* data);
int checkIdData(char* data);
int checkScoresData(char* data);
int checkAverageData(char* data);
int checkFieldName(char* queryRow, char* field, int flag);
int checkOperator(char* queryRow, char* operator,int flag);
int checkData(char* queryRow, char* field, char* data);
int validationRow(char* Row);
int validetionSelectQuery(char* queryRow, char* field, char* operator,void* data);
int validationSetQuery(char* queryRow);
int validationDeleteQuery(char* queryRow, char* data);
