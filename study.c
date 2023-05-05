#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "study.h"

int addStudy(Study *s){
    printf("이름은? ");
    scanf("%s",s->name);
    printf("날짜는? ex)10/23 : ");
    scanf("%s", s->data);
    printf("시작시간은? ex)16:30 : ");;
    scanf("%s", s->startTime);
    printf("종료시간은? ex)18:30 : ");
    scanf("%s", s->endTime);
    printf("만족도는 어느정도입니까? : ");
    scanf("%s", s->level);
    printf("한줄 정리 : ");
    getchar();
    scanf("%[^\n]s", s->explain);
    return 1;
}

void readStudy(Study s){
    printf("%8s %4s %4s %4s %4s %4s \n",
    s.name, s.data, s.startTime, s.endTime, s.level, s.explain);
}

int updateStudy(Study *s){
    printf("이름은? ");
    scanf("%s",s->name);
    printf("날짜는? ex)10/23 : ");
    scanf("%s", s->data);
    printf("시작시간은? ex)16:30 : ");;
    scanf("%s", s->startTime);
    printf("종료시간은? ex)18:30 : ");
    scanf("%s", s->endTime);
    printf("만족도는 어느정도입니까? : ");
    scanf("%s", s->level);
    printf("한줄 정리 : ");
    getchar();
    scanf("%[^\n]s", s->explain);
    printf("=> 수정성공!\n");
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** 공부시간 정리표 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 횟수\n");
    printf("7. 정렬\n");
    printf("0. 종료 >>");
    scanf("%d", &menu);
    return menu;
}


void listStudy(Study* s[],int count){
    printf("\nNum Name Date StartTime EndTime Level Explain\n");
    printf("==================================================\n");
    for(int i = 0 ; i < count; i++){
        if(s[i] == NULL) continue;
        printf("%2d ",i+1);
        readStudy(*s[i]);
    }
    printf ("\n");
}

int selectDataNo(Study *s[], int count){
    int no;
    listStudy(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
void saveData(Study *s[], int top){

    FILE *fp;
    fp = fopen("Study.txt","wt");

    for(int i = 0 ; i < top ; i ++){
        if(s[i] == NULL)continue;
        fprintf(fp, "%s %s %s %s %s %s\n",s[i]->name,s[i]->data,s[i]->startTime,s[i]->endTime,s[i]->level,s[i]->explain);
    }
    fclose(fp);
    printf("=>저장됨! ");

}

int loadData(Study *s[]){

    int i = 0;
    FILE *fp;
    fp = fopen("Study.txt", "rt");
    if(fp==NULL){
        printf("\n=>파일없음\n");
        return 0;
    }

    for(; i < 100 ; i ++){
        s[i] = (Study *)malloc(sizeof(Study));
        fscanf(fp,"%s", s[i]->name);
        if(feof(fp)) break;
        fscanf(fp,"%s", s[i]->data);
        fscanf(fp,"%s", s[i]->startTime);
        fscanf(fp,"%s", s[i]->endTime);
        fscanf(fp,"%s", s[i]->level);
        fscanf(fp,"%[^\n]s", s[i]->explain);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;

}

int findName(Study *s[], int count){
    char wantname[20];
    int scnt = 0;

    printf("검색할 이름? ");
    scanf("%s",wantname);

    for(int i = 0 ; i < count ; i ++){
        if(s[i]==NULL)continue;
        if(strstr(s[i]->name, wantname)){
            scnt++;
        }

    }
    if(scnt == 0)printf("=> 검색된 데이터 없음!");
    printf("\n");
    return scnt;
}

void lineup(Study *s[], int count){
	Study *a;

	for(int i = 0 ; i < count ; i ++){
		if(s[i] == NULL){
		s[i] = s[i+1];
		continue;
		}
		for(int j = 0 ; j < count ; j ++){
			
        		if(strcmp(s[i]->level,s[j]->level)<0){
               			a=s[i];
                		s[i]=s[j];
                		s[j]=a;
            		}
            		if(strcmp(s[i]->level,s[j]->level)==0)continue;
        	}
    	}

}
