#include "main.h"



/*return 0 if the syntax of the line is good , 1 if the line is null ,
  2 if the line including chars thet not letters*/
int isChars(char* line)
{
    int rez = 0,cauntChars = 0, i = 0;
    if (line == NULL)
    {
        return  1;        
    }
    else
    {
        while (line[i] != '\0')
        {
            if (!(line[i] >= 'A' && line[i] <= 'Z' || line[i] >= 'a' && line[i] <= 'z' || line[i] == ' '))
            {
                return 2;
            }
            else if (line[i] >= 'A' && line[i] <= 'Z' || line[i] >= 'a' && line[i] <= 'z')
                cauntChars++;
            i++;
        }
        if(cauntChars == 0)
            return 2;
    }

    return rez;
}

/*return 0 if the syntax of the line is good , 1 if the line is null ,
  3 if the line including chars thet not numbers , 4 if the length of the line is not 9 chars */
int properId(char* line)
{
    int rez = 0, i = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        while (line[i] != '\0')
        {
            if (!(line[i] >= '0' && line[i] <= '9'))
            {
                rez = 3;
                return rez;
            }
            i++;
        }
        if (i != 9)
        {
            rez = 4;
            return rez;
        }
    }

    return rez;
}

/*return 0 if the syntax of the line is good , 1 if the line is null ,
  5 if not exist a coursName like the line  */
int checkCoursName(char* line)
{
    int rez = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        if (strcmp(line, "C language") == 0)
            return rez;
        else if (strcmp(line, "Computer Networks") == 0)
            return rez;
        else if (strcmp(line, "CS Fundamentals") == 0)
            return rez;
        else
        {
            rez = 5;
            return rez;
        }
    }
}

/*return 0 if the syntax of the line is good , 1 if the line is null ,
  6 if the line including chars thet not numbers , 7 if the sum of the numbers in the line is greater than 100  */
int isScore(char* line)
{
    int rez = 0, i = 0, num = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        while (line[i] != '\0')
        {
            if (!(line[i] >= '0' && line[i] <= '9'))
            {
                rez = 6;
                return rez;
            }
            num *= 10;
            num += line[i] - '0';
            if (num > 100)
            {
                rez = 7;
                return rez;
            }
            i++;
        }
    }

    return rez;
}

/**/
int checkNamesData(char* data)
{
    int i = 0;
    while (data[i] != '\0')
    {
        if (!(data[i] >= 'a' && data[i]<='z') && !(data[i] >= 'A' && data[i] <= 'Z') && data[i] != ' ')
            return  0;
        i++;
    }
    return 1;
}

/**/
int checkIdData(char* data)
{   
    int i = 0 , caunt = 0;
    while (data[i] != '\0')
    {
        if (data[i] < '0' || data[i]>'9')
            return 0;
        i++;
        caunt++;
    }
    if (caunt != 9)
        return 0;
    return 1;
}

/**/
int checkScoresData(char* data)
{
    int i = 0, scor, countDigits = 0;
    while (data[i] != '\0')
    {        
        if (i == 0)
        {
            if (data[i] >= '0' && data[i] <= '9')
            {
                countDigits++;
                i++;
            }
            else if (data[0] == '-' && data[1] == '1')
            {
                i = 2;
                while (data[i] != '\0')
                {
                    if (data[i] != ' ')
                        return 0;
                    i++;
                }
                return 1;

            }
            else
                return 0;
                
        }  
        else
        {
            if (!(data[i] >= '0' && data[i] <= '9') && data[i] != ' ')
                return 0;
                                
            else if (data[i] >= '0' && data[i] <= '9')
                countDigits++;
            i++;
        }
    }        
    scor = atoi(data);
    if (scor < 0 || scor > 100)
        return 0;
    else if (scor > 99 && countDigits > 3)
        return 0;
    else if ((scor > 9 && scor < 100) && countDigits > 2)
        return 0;
    else if ((scor >=-1 && scor < 10) && countDigits > 1)
        return 0;
    
    return 1;
}

/**/
int checkAverageData(char* data)
{   
    int i = 0, sumBeforePoint, sumAfterPoint, countDigitsBefore = 0, countDigitsAfter = 0, countPoints = 0;
    float f_data;
    while (data[i] != '\0')
    {
        if (i == 0)
        {
            if (data[i] >= '0' && data[i] <= '9')
            {
                countDigitsBefore++;
                i++;
            }
            else if (data[0] == '-' && data[1] == '1')
            {
                i = 2;
                while (data[i] != '\0')
                {
                    if (data[i] != ' ')
                        return 0;
                    i++;
                }
                return 1;

            }
            else
                return 0;
        }
        else
        {
            if (!(data[i] >= '0' && data[i] <= '9') && data[i] != ' ' && data[i] != '.')
                return 0;
            else if (data[i] >= '0' && data[i] <= '9' && countPoints ==0)
                countDigitsBefore++;
            else if (data[i] >= '0' && data[i] <= '9' && countPoints != 0)
                countDigitsAfter++;
            else if (data[i] == '.')
                countPoints++;
            i++;
        }
    }    
    if (countPoints > 1)
        return 0;        
    else if (countPoints)
    {        
        while (data[i] != '.')        
            i++;        
        sumBeforePoint = atoi(data);
        sumAfterPoint = atoi(data +i+1); 
        if (sumBeforePoint < 0 || sumBeforePoint > 100)
            return 0;
        else if (sumBeforePoint > 99 && countDigitsBefore > 3)
            return 0;
        else if ((sumBeforePoint > 9 && sumBeforePoint < 100) && countDigitsBefore > 2)
            return 0;
        else if ((sumAfterPoint >= -1 && sumBeforePoint < 10) && countDigitsBefore > 1)
            return 0;
        
        if (sumAfterPoint < 0 || sumAfterPoint > 99)
            return 0;
        else if (countDigitsAfter > 2)
            return 0;
        else if (sumBeforePoint == 100 && sumAfterPoint > 0)
            return 0;
    }
    else
    {
        sumBeforePoint = atoi(data);
        if (sumBeforePoint < 0 || sumBeforePoint > 100)
            return 0;
        else if (sumBeforePoint > 99 && countDigitsBefore > 3)
            return 0;
        else if ((sumBeforePoint > 9 && sumBeforePoint < 100) && countDigitsBefore > 2)
            return 0;
        else if ((sumBeforePoint >= -1 && sumBeforePoint < 10) && countDigitsBefore > 1)
            return 0;
    }    

    return 1;
}

/**/
int checkFieldName(char* queryRow, char* field,int flag)
{    
    char* temp;
    int index = 0, countChars, i = 0, j = 0, isProper = 0;
    while (queryRow[index] == ' ')
        index++;
    countChars = index;
    while (queryRow[countChars] >= 'a' && queryRow[countChars] <= 'z' || queryRow[countChars] >= 'A' && queryRow[countChars] <= 'Z' || queryRow[countChars] == ' ')
        countChars++;
    if (countChars == 0)
        return 0;
    temp = (char*)malloc(sizeof(char) * countChars - index + 1);
    if (temp == NULL)
    {
        printf("problem in memory");
        return 0;
    }   
    strncpy(temp, queryRow + index, countChars - index);
    temp[countChars - index] = '\0';
    while (temp[i] != '\0')
    {
        if (temp[i] != ' ')
        {
            field[j] = temp[i];
            j++;
        }

        i++;
    }
    field[j] = '\0';
    if (flag == 0)
    {
        if (strcmp(field, "firstname") != 0 && strcmp(field, "secondname") && strcmp(field, "id") && strcmp(field, "clanguage") && strcmp(field, "computernetworks") && strcmp(field, "csfundamentals") && strcmp(field, "average"))
            return 0;
    }  
    else if(flag == 1)
    {
        if (strcmp(field,  "firstname") != 0)
            return 0;
    }
    else if (flag == 2)
    {
        if (strcmp(field, "secondname") != 0)
            return 0;
    }
    else if (flag == 3)
    {
        if (strcmp(field, "id") != 0)
            return 0;
    }   
    strcpy(queryRow, queryRow + countChars + index);
    strcat(queryRow , "\0");    
    return 1;
}

/**/
int checkOperator(char* queryRow, char* operator,int flag)
{    
    char* temp;
    int index = 0, cauntChars, i, j,indexOfOperator = 0;
    while (queryRow[index] == ' ')
        index++;    
    cauntChars = index;
    while (queryRow[cauntChars] == '=' || queryRow[cauntChars] == '!' || queryRow[cauntChars] == '<' || queryRow[cauntChars] == '>' || queryRow[cauntChars] == ' ')
        cauntChars++;
    if (cauntChars == 0)
        return 0;
    i = 0, j = 0;
    temp = (char*)malloc(sizeof(char) * cauntChars - index + 1);
    if (temp == NULL)
    {
        printf("problem in memory");
        return 0;
    }
    strncpy(temp, queryRow + index, cauntChars - index);
    temp[cauntChars - index] = '\0';
    while (temp[i] != '\0')
    {
        if (temp[i] != ' ')
        {
            operator[j] = temp[i];
            j++;
        }
        i++;
    }
    operator[j] = '\0';
    if (flag != 0)
    {
        if (strcmp(operator,"=") == 0)
            indexOfOperator =  1;
        else
            return 0;
    }
    else if (strlen(operator) == 1)
    {
        if (strcmp(operator,"=") == 0)
            indexOfOperator = 1;
        else if (strcmp(operator,"<") == 0)
            indexOfOperator = 2;
        else if (strcmp(operator,">") == 0)
            indexOfOperator = 3;
        else
            return 0;
    }
    else if (strlen(operator) == 2)
    {
        if (strcmp(operator,"!=") == 0)
            indexOfOperator = 4;
        else if(strcmp(operator,"<=") == 0)
            indexOfOperator = 5;
        else if(strcmp(operator,">=") == 0)
            indexOfOperator = 6;
        else
            return 0;
    }
    else if (strlen(operator) > 2)
        return 0;
    
    strcpy(queryRow , queryRow + cauntChars );
    strcat(queryRow, "\0");
    
    return  indexOfOperator;
}

/**/
int checkData(char* queryRow, char* field, char* data)
{    
    int index = 0, isProper = 0;       
    while (queryRow[index] >= 'a' && queryRow[index] <= 'z' || queryRow[index] >= 'A' && queryRow[index] <= 'Z' || queryRow[index] >= '0' && queryRow[index] <= '9' || queryRow[index] == '-' || queryRow[index] == ' ' || queryRow[index] == '.')
        index++;   
    if (index == 0)
        return 0;   
    strncpy(data, queryRow, index);
    data[index] = '\0';
    while (data[index - 1] == ' ')
    {
        index--;
        data[index] = '\0';
    }           
    if (strcmp(field, "firstname") == 0 || strcmp(field, "secondname") == 0)
        isProper = checkNamesData(data);
    else if (strcmp(field, "id") == 0)
        isProper = checkIdData(data);       
    else if (strcmp(field, "clanguage") == 0 || strcmp(field, "computernetworks") == 0 || strcmp(field, "csfundamentals") == 0 )
        isProper = checkScoresData(data);
    else if (strcmp(field, "average") == 0)
        isProper = checkAverageData(data);
       
    return isProper;
}

/*return 0 if the syntax of the line is good , 1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationRow(char* Row)
{
    char* token, * row;
    int rez = 0, i;
    if (strlen(Row) == 0)    
        return 3;    
    row = (char*)malloc(sizeof(char) * (strlen(Row) + 1));
    if (row == NULL)
    {
        rez = 0;
        return rez;
    }
    strcpy(row, Row);
    strcpy(row + strlen(Row), "\0");
    token = strtok(row, ",");
    /*Check the firstName*/
    if (rez = isChars(token))
        return rez;
    token = strtok(NULL, ",");

    /*Check the secondName*/
    if (rez = isChars(token))
        return rez;
    token = strtok(NULL, ",");

    /*Check the Id*/
    if (rez = properId(token))
        return rez;
    token = strtok(NULL, ",");

    /*Check the coursName*/
    if (rez = checkCoursName(token))
        return rez;
    token = strtok(NULL, ",");

    /*Check the Scor*/
    if (rez = isScore(token))
        return rez;

    free(row);

    return rez;
}

/*return 0 if the quety is not good and 1 if thet is good*/
int validetionSelectQuery(char* queryRow, char* field, char* operator, char* data, int flag)
{    
    int index = 0, isProper = 0;
    while (queryRow[index] == ' ')
        index++;
    isProper = checkFieldName(queryRow + index, field, flag);      
    if (!isProper)
        return isProper;    
    isProper = checkOperator(queryRow, operator,flag);      
    if (!isProper)
        return isProper;
    isProper = checkData(queryRow, field, data);    
    return isProper;
}

/*return 0 if the syntax of the line is good and chang the syntax like a line in the file ,
  1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationSetQuery(char* queryRow)
{   
    int isProper = 1,j=0 ,index=0,count = 0;
    char* token, fild[20], operat[3], data[50], * line;
    line = (char*)malloc(sizeof(char) * (strlen(queryRow) + 1));    
    if (line == NULL)
    {
        isProper = 0;
        return isProper;
    }    
    strcpy(line, queryRow);    
    strcpy(line + strlen(queryRow), "\0");

    token = strtok(line, ",");
    while (token != NULL && count < 3)
    {        
        count++;
        isProper = validetionSelectQuery(token , fild, operat, data, count);
        if (isProper == 0)
            return isProper;
        if (count == 1)
            strcpy(queryRow, data);
        else
            strcat(queryRow, data);
        strcat(queryRow, ",");
        token = strtok(NULL, ",");
    }
    if (token != NULL)
    {        
        count++;
        isProper = validetionSelectQuery(token, fild, operat, data, count);
        if (isProper == 0)
            return isProper;
        strcat(queryRow, fild);
        strcat(queryRow, ",");
        strcat(queryRow, data);
        strcat(queryRow, "\0");
    }
    if (count != 4)
    {
        isProper = 0;
        return isProper;
    }

    return 1;        
}

/**/
int validationDeleteQuery(char* queryRow,char* data)
{
    int index , rez;
    index = strlen(queryRow);
    while (queryRow[index - 1] == ' ')
    {
        index--;
        queryRow[index] = '\0';
    }
    index = 0;
    while (queryRow[index] == ' ')
        index++;    
    if (strncmp(queryRow + index,"id",2) != 0)
        return 0;
    index += 2;    
    while (queryRow[index] == ' ')
        index++;    
    if (queryRow[index] != '=')
        return 0;
    index++;    
    while (queryRow[index] == ' ')
        index++; 
    rez = checkIdData(queryRow + index);
    if (rez)
    {
        strcpy(data, queryRow + index);
        strcat(data + strlen(data), "\0");
    }        
    return rez;
}
