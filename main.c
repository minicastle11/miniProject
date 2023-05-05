#include "study.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    Study *s[20];
    int top = 0;
    int count = 0, menu;
    int num;

    count = loadData(s);
    top = count;


    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>=1){
                listStudy(s,top);
            }else{
                printf("데이터가 없습니다. ");
            }
        }else if ((menu == 2)&&(count >= 0)){
            s[top] = (Study *)malloc(sizeof(Study));
            count += addStudy(s[top++]);
        }else if ((menu == 3)&&(count >= 1)){
            int no = selectDataNo(s, top);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateStudy(s[no-1]);        
        }else if (menu == 4){
            int no = selectDataNo(s, top);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(s[no-1]) free(s[no-1]);
                s[no-1] = NULL;
            }
        }else if(menu == 5){
            saveData(s, top);
        }else if(menu == 6){
            num = findName(s,top);
            printf("총 %d 회 공부를 하였습니다.", num);
        }else if(menu == 7){
            lineup(s,top);
        
        }
    }//asdf
    printf("종료됨!\n");
    return 0;
}

