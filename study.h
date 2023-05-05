typedef struct{
    char name[20];
    char data[20];
    char startTime[20];
    char endTime[20];
    char level[5];
    char explain[40];
    } Study;
int addStudy(Study *s);
void readStudy(Study s);
int updateStudy(Study *s);
int selectMenu();
void listStudy(Study* s[],int count);
int selectDataNo(Study *s[], int count);
void saveData(Study *s[], int top);
int loadData(Study *s[]);
int findName(Study *s[], int count);
void lineup(Study *s[], int count);

