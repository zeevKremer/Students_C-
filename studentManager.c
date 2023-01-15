#include "main.h"



/*create a new node , insert the valeu , return a ponter to the node*/
student* createStudent(char* row)
{    
    char* token;
    student* newStude;
    int i, sum = 0, caunt = 0;
    newStude = (student*)malloc(sizeof(student));
    if (newStude == NULL)
    {
        free(newStude);
        return NULL;
    }        
    token = strtok(row, ",");
    newStude->FirstName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    if (newStude->FirstName != NULL)
    {
        strcpy(newStude->FirstName, token);
        strcat(newStude->FirstName, "\0");
    }      
    token = strtok(NULL, ",");
    newStude->SecondName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    if (newStude->SecondName != NULL)
    {
        strcpy(newStude->SecondName, token);
        strcat(newStude->SecondName, "\0");
    }        
    token = strtok(NULL, ",");
    strcpy(newStude->Id, token);
    strcat(newStude->Id, "\0");    
    token = strtok(NULL, ",");
    for (i = 0; i < SUM_COURSES; i++)
        newStude->marks[i] = NOT_TESTED;    
    if (strcmp(token, "C language") == 0 || strcmp(token, "clanguage") == 0 )
    {
        token = strtok(NULL, ",");
        newStude->marks[0] = atoi(token);
    }
    else if (strcmp(token, "Computer Networks") == 0 || strcmp(token, "computernetworks") == 0)
    {
        token = strtok(NULL, ",");
        newStude->marks[1] = atoi(token);
    }
    else if (strcmp(token, "CS Fundamentals") == 0 || strcmp(token, "csfundamentals") == 0)
    {
        token = strtok(NULL, ",");
        newStude->marks[2] = atoi(token);
    }
    for (i = 0; i < SUM_COURSES; i++)
    {
        if (newStude->marks[i] > NOT_TESTED)
        {
            caunt++;
            sum += newStude->marks[i];
        }
    }
    newStude->average = ((float)sum / (float)caunt);
    newStude->next = NULL;

    return newStude;
}

/*return 1 if the student is exist in the list , return 0 if thet not exist in the list
 return -1 if exist a student with tis ID but firstName or secondName is different*/
int existInList(studManagar* studentsManager, student* stud)
{   
    student* ptr = studentsManager->head;
    if (studentsManager->tail != NULL && strcmp(studentsManager->tail->Id, stud->Id) == 0)
    {
        if (strcmp(studentsManager->tail->FirstName, stud->FirstName) == 0 && strcmp(studentsManager->tail->SecondName, stud->SecondName) == 0)
        {
            studentsManager->isSorted = 1;
            return 1;
        }            
        else
            return -1;
    }
    else
    {
        studentsManager->isSorted = 1;
        while (ptr != NULL)
        {            
            if (strcmp(ptr->Id, stud->Id) == 0)
            {                
                if (strcmp(ptr->FirstName, stud->FirstName) == 0 && strcmp(ptr->SecondName, stud->SecondName) == 0)
                {
                    studentsManager->isSorted = 0;
                    return 1;
                }                    
                else
                    return -1;
            }
            ptr = ptr->next;
        }
    }    

    return 0;
}

/*return a ponter to the node thet is like to the current node*/
student* getPtrToNode(studManagar* studentsManager, student* newStud)
{
    student* ptr = studentsManager->head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->Id, newStud->Id) == 0)
            return ptr;
        ptr = ptr->next;
    }

    return ptr;
}

/*update the value of the student*/
void updateStudent(student* ptrStud, student* newStud)
{
    
    int i, sum = 0, count = 0;
    strcpy(ptrStud->FirstName, newStud->FirstName);
    strcat(ptrStud->FirstName, "\0");
    strcpy(ptrStud->SecondName, newStud->SecondName);
    strcat(ptrStud->SecondName, "\0");
    for (i = 0; i < SUM_COURSES; i++)
    {
        if (newStud->marks[i] > NOT_TESTED)
            ptrStud->marks[i] = newStud->marks[i];
        if (ptrStud->marks[i] > NOT_TESTED)
        {
            count++;
            sum += ptrStud->marks[i];
        }
    }
    ptrStud->average = ((float)sum / (float)count);
}

/*return a pointer to the node that before the place of this student
  check if the place is efter the last student in the list
  if the list is empty or the place if before the head return NULL*/
student* getIndexToInsert(studManagar* studentsManager, student* newStud)
{
    student* ptrCur = studentsManager->head, * ptrPrv = NULL;
    if (ptrCur == NULL || strcmp(ptrCur->SecondName, newStud->SecondName) >= 0)
        return ptrPrv;
    else if (strcmp( newStud->SecondName, studentsManager->tail->SecondName) >= 0)
        return studentsManager->tail;
    else
    {
        ptrPrv = studentsManager->head;

        while (ptrCur->next != NULL)
        {
            ptrPrv = ptrCur;
            ptrCur = ptrCur->next;
            if (strcmp(ptrCur->SecondName, newStud->SecondName) >= 0)
                return ptrPrv;
        }
        return ptrCur;
    }
}

/*adding a student to the list by sorted
  check if the file is sorted*/
void addTolist(studManagar* studentsManager, student* ptrPrv, student* newStud)
{
    student* ptrStud;
    if (ptrPrv == NULL)
    {
        if (studentsManager->head == NULL)
        {
            newStud->next = NULL;
            studentsManager->head = newStud;
            studentsManager->tail = newStud;
            studentsManager->isSorted = 1;
        }
        else
        {            
            newStud->next = studentsManager->head;
            studentsManager->head = newStud;
            studentsManager->isSorted = 0;
        }

    }
    else
    {
        if (ptrPrv->next == NULL)
        {
            studentsManager->tail = newStud;
            newStud->next = NULL;
            ptrPrv->next = newStud;
            studentsManager->isSorted = 1;
        }
        else
        {
            newStud->next = ptrPrv->next;
            ptrPrv->next = newStud;
            studentsManager->isSorted = 0;
        }
    }    
}

/*update the marks of the student*/
void updateMark(student* ptrNode , student* newStud)
{
    int i,sum=0,count=0;
    for (i = 0; i < SUM_COURSES; i++)
    {
        if (newStud->marks[i] > NOT_TESTED)
            ptrNode->marks[i] = newStud->marks[i];
        if (ptrNode->marks[i] > NOT_TESTED)
        {
            count++;
            sum += ptrNode->marks[i];
        }
    }  
    ptrNode->average = ((float)sum / (float)count);
}

/*opening the file , read the value , bild the list , closing the file*/
studManagar*  readFile(char* fileName)
{
    FILE* fRead;
    char row[MAX_ROW];
    int checkSyntax = 0, isExist, countRows = 0;
    student* newStud, * ptrPrv, * ptrNode;
    studManagar* studentsManager;
    studentsManager = (studManagar*)malloc(sizeof(studManagar));
    if (studentsManager == NULL)
    {
        printf(MOMORY_ERROR);
        return NULL;
    }
    studentsManager->head = NULL;
    studentsManager->tail = NULL;
    studentsManager->countAdded = 0;
    studentsManager->countUpdate = 0;
    studentsManager->countDeleted = 0;
    studentsManager->isSorted = 0;
    fRead = fopen(fileName, "rt");
    if (fRead == NULL)
    {            
        printf(OPEN_FILE_ERROR);
        free(studentsManager);
        return NULL;
    }
    else if (fgetc(fRead) == EOF)
    {        
        printf(EMPTY_FILE);
        free(studentsManager);
        return NULL;
    }
    else
    {
        do
        {
            fseek(fRead, -1, SEEK_CUR);
            fgets(row, MAX_ROW, fRead);
            countRows++;
            if (row[strlen(row) - 1] == '\n')
            {
                row[strlen(row) - 1] = '\0';
                checkSyntax = validationRow(row);
                if (checkSyntax)                    
                    printError(countRows, checkSyntax);
                else
                {

                    newStud = createStudent(row);
                    isExist = existInList(studentsManager, newStud);

                    if (isExist == -1)
                    {
                        printError(countRows, 8);
                        freeStudent(newStud);
                    }
                    else if (isExist == 1)
                    {
                        ptrNode = getPtrToNode(studentsManager, newStud);
                        updateMark(ptrNode, newStud);
                        freeStudent(newStud);

                    }
                    else if (!(isExist))
                    {
                        ptrPrv = getIndexToInsert(studentsManager, newStud);
                        addTolist(studentsManager, ptrPrv, newStud);
                    }
                }
            }
            else
            {
                while (fgetc(fRead) != '\n');
                printf(ROW_TOO_LONG(countRows));
            }
        } while (fgetc(fRead) != EOF);
    }    
    fclose(fRead);    
    return studentsManager;
}

/*opening the file , rewrite the student list , closing the file*/
int updateFile(studManagar* studentsManager)
{
    FILE* fWrite;
    char courses[3][20] = {"C language","Computer Networks","CS Fundamentals"};
    int i;      
    fWrite = fopen(FILE_NAME, "w+");
    if (fWrite == NULL)
    {        
        return 1;
    }
    while (studentsManager->head != NULL)
    {        
        for (i = 0; i < SUM_COURSES; i++)
        {
            if (studentsManager->head->marks[i] > NOT_TESTED)
            {               
                    fprintf(fWrite, "%s,%s,%s,%s,%d\n", studentsManager->head->FirstName, studentsManager->head->SecondName, studentsManager->head->Id, courses[i], studentsManager->head->marks[i]);
            }
        }
        studentsManager->head = studentsManager->head->next;
    }
    fclose(fWrite);
    return 0;
}

/*print a error message and What row in file is the error*/
void printError(int countRows, int checkSyntax)
{
    char* arrError[8] = { "the row is empty","the row is empty","the row is empty","the row is empty","the row is empty","the row is empty","the row is empty","the row is empty" };
    int i;
    for (i = 0; i < 8 && i < checkSyntax; i++);
    printf("Error in file line number %d ", countRows);
    printf("%s\n", arrError[checkSyntax]);
}

/*ptint thr field Names*/
void printTitle()
{
    printf("\n+------------+--------------+-----------+--------------------+--------------------+--------------------+-----------+\n");    
      printf("| First Name | Second Name  |     ID    |     C Language     |  Computer Networks |   CS Fundamentals  |  Average  |\n");
      printf("+------------+--------------+-----------+--------------------+--------------------+--------------------+-----------+\n");
}

/*ptint thr Footer*/
void printFuter()
{
    printf("+------------+--------------+-----------+--------------------+--------------------+--------------------+-----------+\n\n");
}

/*print one node */
void printNode(student* stud)
{
    int i;
    printf("| %-8s   | %-8s     |%10s |", stud->FirstName, stud->SecondName, stud->Id);
    for (i = 0; i < SUM_COURSES; i++)
    {
        if (stud->marks[i] > NOT_TESTED)
        {
            printf("         %-11d|", stud->marks[i]);
        }
        else
            printf("         --         |");
    }
    if (stud->average > NOT_TESTED)
    {
        printf(" %-8.2f  |", stud->average);
    }
    else
        printf("      --   |");
    printf("\n");
}

/*print the list */
void printList(studManagar* studentsManager)
{
    student* ptrStud = studentsManager->head;
    printTitle();
    while (ptrStud != NULL)
    {
        printNode(ptrStud);
        ptrStud = ptrStud->next;
    }
    printFooter();
}

/**/
void getId(char* field, char* operator,int* fieldId, int* operatorId)
{       
    int arrFields[7] = { "firstname", "secondname", "id", "clanguage", "computernetworks", "csfundamentals", "average" }, arrOperators[6] = { "=", ">", "<", ">=", "<=", "!=" };
    int i;
    for (i = 0; i < 7; i++)
    {
        if (strcmp(arrFields[i], field) == 0)
            *fieldId = i+1;
    }
    for (i = 0; i <6; i++)
    {
        if (strcmp(arrOperators[i], operator) == 0)
            *operatorId = i;
    }    
}

/*free memory of one student*/
void freeStudent(student* ptrStud)
{
    free(ptrStud->FirstName);
    free(ptrStud->SecondName);
    free(ptrStud);
}

/*free memory of the list*/
void freeList(studManagar* studentsManager)
{
    student* ptrStud;
    while (studentsManager->head)
    {
        ptrStud = studentsManager->head;
        studentsManager->head = studentsManager->head->next;
        freeStudent(ptrStud);        
    }    
    free(studentsManager);
}

/**/
int ExistToDelete(student* head, char* data)
{
    student* ptrStud = head;
    while (ptrStud != NULL)
    {
        if (strcmp(ptrStud->Id, data) == 0)
            return 1;
        ptrStud = ptrStud->next;
    }
    return 0;
}
