#include "main.h"


/*return a pointer to the node that before the place of this student
  if the list is empty or the place if before the head return NULL*/
student* getIndexToInsertQuery(studManagar* studentsManager, student* ptrNode)
{
	student* ptrPrv = NULL, * ptrCur = studentsManager->head;
	if (ptrCur == NULL || strcmp(ptrCur->SecondName, ptrNode->SecondName) >= 0)
		return ptrPrv;
	ptrPrv = studentsManager->head;
	while (ptrCur->next != NULL)
	{
		ptrPrv = ptrCur;
		ptrCur = ptrCur->next;
		if (strcmp(ptrCur->SecondName, ptrNode->SecondName) >= 0)
			return ptrPrv;
	}
	return ptrCur;
}

/*adding a student to the list by sorted*/
void addTolistQuery(studManagar* studentsManager, student* ptrPrv, student* newStud)
{

	if (ptrPrv == NULL)
	{
		newStud->next = studentsManager->head;
		studentsManager->head = newStud;
	}
	else
	{
		newStud->next = ptrPrv->next;
		ptrPrv->next = newStud;
		if (newStud->next == NULL)
			studentsManager->tail = newStud;
	}

}

/*update the value of the student
  and re sorted the list*/
void updateStudentQuery(studManagar* studentsManager, student* ptrNode, student* newStud)
{
	student* ptrPrv;	
	if (studentsManager->head->next == NULL)
	{
		updateStudent(studentsManager->head, newStud);
	}
	else
	{
		ptrPrv = getIndexToInsertQuery(studentsManager->head, ptrNode);
		if (ptrNode == studentsManager->head)
		{
			studentsManager->head = studentsManager->head->next;
			updateStudent(ptrNode, newStud);
			ptrPrv = getIndexToInsertQuery(studentsManager->head, ptrNode);
			addTolistQuery(studentsManager, ptrPrv, ptrNode);
		}
		else
		{
			ptrPrv->next = ptrNode->next;
			updateStudent(ptrNode, newStud);
			ptrPrv = getIndexToInsertQuery(studentsManager->head, ptrNode);
			addTolistQuery(studentsManager, ptrPrv, ptrNode);
		}
	}
}

/*select and print the students by firstName field*/
int select_firstname(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{				
		switch (operator)
		{
		case equal:
			if (strcmp(ptrStud->FirstName, data) == 0)
				toPrint = 1;
			break;
		case bigger:
			if (strcmp(ptrStud->FirstName, data) > 0)
				toPrint = 1;
			break;
		case smaller:
			if (strcmp(ptrStud->FirstName, data) < 0)
				toPrint = 1;
			break;
		case biggerEqual:
			if (strcmp(ptrStud->FirstName, data) >= 0)
				toPrint = 1;
			break;
		case smallerEqual:
			if (strcmp(ptrStud->FirstName, data) <= 0)
				toPrint = 1;
			break;
		case notEqual:
			if (strcmp(ptrStud->FirstName, data) != 0)
				toPrint = 1;
			break;
		}		
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}			
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/*select and print the students by secodName field*/
int select_secondname(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (strcmp(ptrStud->SecondName, data) == 0)
				toPrint = 1;
			break;
		case bigger:
			if (strcmp(ptrStud->SecondName, data) > 0)
				toPrint = 1;
			break;
		case smaller:
			if (strcmp(ptrStud->SecondName, data) < 0)
				toPrint = 1;
			break;
		case biggerEqual:
			if (strcmp(ptrStud->SecondName, data) >= 0)
				toPrint = 1;
			break;
		case smallerEqual:
			if (strcmp(ptrStud->SecondName, data) <= 0)
				toPrint = 1;
			break;
		case notEqual:
			if (strcmp(ptrStud->SecondName, data) != 0)
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/*select and print the students by id field*/
int select_id(student* head, int operator, char* data) {	
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (strcmp(ptrStud->Id, data) == 0)
				toPrint = 1;
			break;
		case bigger:
			if (strcmp(ptrStud->Id, data) > 0)
				toPrint = 1;
			break;
		case smaller:
			if (strcmp(ptrStud->Id, data) < 0)
				toPrint = 1;
			break;
		case biggerEqual:
			if (strcmp(ptrStud->Id, data) >= 0)
				toPrint = 1;
			break;
		case smallerEqual:
			if (strcmp(ptrStud->Id, data) <= 0)
				toPrint = 1;
			break;
		case notEqual:
			if (strcmp(ptrStud->Id, data) != 0)
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/*select and print the students by C Language field*/
int select_clanguage(student* head, int operator, char* data) 
{	
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->marks[0] == atoi(data))
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->marks[0] > atoi(data))
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->marks[0] < atoi(data))
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->marks[0] >= atoi(data))
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->marks[0] <= atoi(data))
				toPrint = 1;
			break;
		case notEqual:
			if (ptrStud->marks[0] != atoi(data))
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/*select and print the students by ComputerNetworks field*/
int select_computernetworks(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->marks[1] == atoi(data))
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->marks[1] > atoi(data))
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->marks[1] < atoi(data))
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->marks[1] >= atoi(data))
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->marks[1] <= atoi(data))
				toPrint = 1;
			break;
		case notEqual:
			if (ptrStud->marks[1] != atoi(data))
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/*select and print the students by CS Fundamentals field*/
int select_csfundamentals(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->marks[2] == atoi(data))
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->marks[2] > atoi(data))
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->marks[2] < atoi(data))
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->marks[2] >= atoi(data))
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->marks[2] <= atoi(data))
				toPrint = 1;
			break;
		case notEqual:
			if (ptrStud->marks[2] != atoi(data))
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/*select and print the students by average field*/
int select_average(student* head, int operator, char* data) {
	student* ptrStud = head;	
	int isFirst = 0, toPrint = 0, isFind = 0,i=0,isPoint = 0;
	float f_data;	
	while (data[i] != '\0')
	{
		if (strncmp(data + i,".",1) == 0)
			isPoint = 1;
			
		i++;
	}		
	if (isPoint)
		f_data = atof(data) + atof(data + i+1);
	else
		f_data = atof(data);	
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->average == f_data)
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->average > f_data)
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->average < f_data)
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->average >= f_data)
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->average <= f_data)
				toPrint = 1;
			break;
		case notEqual:					
			if (ptrStud->average != f_data)
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFooter();

	return isFind;
}

/**/
int genericSelect(studManagar* studentsManager, int field, int operator,void* data)
{
	student* ptrStud = studentsManager->head;
	switch (field)
	{
	case firstname:
		return (&select_firstname)(ptrStud, operator, data);
		break;
	case secondname:
		return (&select_secondname)(ptrStud, operator, data);
		break;
	case id:
		return (&select_id)(ptrStud, operator, data);
		break;
	case clanguage:
		return (&select_clanguage)(ptrStud, operator, data);
		break;
	case computernetworks:
		return (&select_computernetworks)(ptrStud, operator, data);
		break;
	case csfundamentals:
		return (&select_csfundamentals)(ptrStud, operator, data);
		break;
	case average:
		return (&select_average)(ptrStud, operator, data);
		break;
	}

	return 0;
}

/**/
void printMenu()
{
	printf("    to querying the system enter select and the query sentence\n\n");
	printf("    select firstName = beni\n\n");
	printf("    to update or insert data enter set and the data\n\n");
	printf("    set firstName = dani, secondName = haham, id = 111222333, clanguage = 45\n\n");
	printf("    to delete a student enter deleteand the id\n\n");
	printf("    delete id = 111222333\n\n");
	printf("    to print the data enter print\n\n");
	printf("    to print the menu enter menu\n\n");
	printf("    to exit enter quit\n");
}

/*remove a student from the list*/
void deleteStudent(studManagar* studentsManager, char* data)
{
	student* ptrCur = studentsManager->head,*ptrPrv;
	if (strcmp(ptrCur->Id, data) == 0)
	{
		if (ptrCur->next == NULL)
			freeList(studentsManager);
		else
		{
			studentsManager->head = studentsManager->head->next;
			freeStudent(ptrCur);
		}		
	}
	else
	{
		do
		{
			ptrPrv = ptrCur;
			ptrCur = ptrCur->next;
			if (strcmp(ptrCur->Id, data) == 0)
			{
				ptrPrv->next = ptrCur->next;
				freeStudent(ptrCur);
				if (ptrPrv->next == NULL)
					studentsManager->tail = ptrPrv;
				break;
			}
		} while (ptrCur->next != NULL);
	}			
}

/**/
void runQueries(studManagar* studentsManager)
{
    int chackOpenFile=0;
    char queryLine[MAX_ROW];
	printMenu();
    do
    {
        printf("\n  ->  ");
        gets(queryLine);
    } while (checkQuery(queryLine, studentsManager));
	if (studentsManager->isSorted == 0 || studentsManager->countDeleted > 0 || studentsManager->countAdded > 0 || studentsManager->countUpdate > 0)
	{		
		chackOpenFile = updateFile(studentsManager);
		if (chackOpenFile)
		{
			printf("cannot open the file to update");
			exit(1);
		}
	}    
}

/**/
int checkQuery(char* queryRow, studManagar* studentsManager)
{	
	char* token, field[20], operator[3], data[50], * line;
    int index = 0, range, fieldId , operatorId , isFind = 0, checkSyntax, isExist, checkQuery;
    student*  newStud, * ptrNode, * ptrPrv;
    
	while (queryRow[index] != '\0')
	{
		if (queryRow[index] >= 'A' && queryRow[index] <= 'Z')
			queryRow[index] += 32;
		index++;
	}		
	index = 0;
    while (queryRow[index] == ' ')
        index++;

    if (strncmp(queryRow + index, "quit", 4) == 0)
        return 0;
    else if (strncmp(queryRow + index, "print", 5) == 0)
	{				
        printf("\n");
        printList(studentsManager);
        return 1;
    }
    else if (strncmp(queryRow + index, "select", 6) == 0)
    {
        checkQuery = validetionSelectQuery(queryRow + index + 6, field, operator,data, 0);		
        if (checkQuery)
        {                       
			getId(field, operator,&fieldId,& operatorId);			
            isFind = genericSelect(studentsManager, fieldId, operatorId, data);
            if (!isFind)
                printf("\n  Not found students were like to the query\n\n");                
        }
        else
            printf("\n  The query is invalid\n\n");
        return 1;
    }
    else if (strncmp(queryRow + index, "set", 3) == 0)
    {        
        checkQuery = validationSetQuery(queryRow + index + 3);
        if (checkQuery)
        {            
            newStud = createStudent(queryRow + index +3);
            isExist = existInList(studentsManager, newStud);
            if (isExist)
            {
                ptrNode = getPtrToNode(studentsManager, newStud);
                updateStudentQuery(studentsManager, ptrNode, newStud);
				studentsManager->countUpdate++;
                printf("     update student successful");               
            }
            else
            {
                ptrPrv = getIndexToInsertQuery(studentsManager, newStud);
                addTolistQuery(studentsManager, ptrPrv, newStud);
				studentsManager->countAdded++;
                printf("     insert student successful");
            }           
        }
        else
            printf("\n  The query is invalid\n\n");
        
        return 1;              
    }
	else if (strncmp(queryRow + index, "delete", 6) == 0)
	{
		checkQuery = validationDeleteQuery(queryRow + index + 6, data);
		if (checkQuery)
		{
			isExist = ExistToDelete(studentsManager->head, data);
			if (isExist)
			{
				deleteStudent(studentsManager, data);
				studentsManager->countDeleted++;
				printf("     delete student successful");
			}
			else
			{
				printf("\n  Not found students were like to the query\n\n");
			}						
		}
		else
			printf("\n  The query is invalid\n\n");

		return 1;
	}
	else if (strncmp(queryRow + index, "menu", 4) == 0)
	{
		printMenu();
	}
	else
        printf("\n  The query is invalid\n\n");

    return 1;
}
