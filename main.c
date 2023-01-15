#include "main.h"


int main()
{    
    studManagar* studentsManager;
    studentsManager = readFile(FILE_NAME);
    if (studentsManager == NULL)
    {        
        return -1;
    }
    else
    {
        printList(studentsManager);
        runQueries(studentsManager);
        freeList(studentsManager);
    }
            
	return 0;
}
