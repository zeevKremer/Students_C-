

typedef enum {

	equal, bigger, smaller, biggerEqual, smallerEqual, notEqual

} enumOperators;


student* getIndexToInsertQuery(studManagar* studentsManager, student* ptrNode);
void addTolistQuery(studManagar* studentsManager, student* ptrPrv, student* newStud);
void updateStudentQuery(studManagar* studentsManager, student* ptrNode, student* newStud);
int select_firstname(student* head, int operator, char* data);
int select_secondname(student* head, int operator, char* data);
int select_id(student* head, int operator, char* data);
int select_clanguage(student* head, int operator, char* data);
int select_computernetworks(student* head, int operator, char* data);
int select_csfundamentals(student* head, int operator, char* data);
int select_average(student* head, int operator, float* data);
void deleteStudent(studManagar* studentsManager, char* data);
int genericSelect(studManagar* studentsManager, int field, int operator,void* data);
void printMenu();
void runQueries(studManagar* studentsManager);
int checkQuery(char* query, studManagar* studentsManager);
