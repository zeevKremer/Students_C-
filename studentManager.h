
#define MAX_ROW  255
#define SUM_COURSES  3
#define FILE_NAME "students.csv"
#define NOT_TESTED  -1
#define MOMORY_ERROR "    memory error cannot locate memory!\n"
#define OPEN_FILE_ERROR "    Cannot open the file!\n"
#define EMPTY_FILE "    The file is empty!\n"
#define ROW_TOO_LONG(row) "    Error in file, row number %d is too long!\n",row


typedef struct student {
    char* FirstName;
    char* SecondName;
    char Id[10];
    char marks[SUM_COURSES];
    float average;
    struct student* next;
}student;


typedef struct studManagar {
    student* head;
    student* tail;
    char isSorted;
    char countAdded;
    char countUpdate;
    char countDeleted;
}studManagar;


typedef enum {

    firstname = 1, secondname, id, clanguage, computernetworks, csfundamentals, average

} enumFields;



student* createStudent(char* row);
int existInList(studManagar* studentsManager, student* stud);
student* getPtrToNode(studManagar* studentsManager, student* newStud);
void updateStudent(student* ptrNode, student* newStud);
student* getIndexToInsert(studManagar* studentsManager,student* newStud);
void addTolist(studManagar* studentsManager, student* ptrPrv, student* newStud);
void updateMark(student* newStud, student* ptrNode);
studManagar* readFile(char* fileName);
int updateFile(studManagar* studentsManager);
void printError(int countRows, int checkSyntax);
void printTitle();
void printFooter();
void printNode(student* stud);
void printList(studManagar* studentsManager);
void getId(char* field,char* operator,int* fieldId, int* operatorId);
void freeStudent(student* ptrStud);
void freeList(studManagar* studentsManager);
int ExistToDelete(student*  head, char* data);
