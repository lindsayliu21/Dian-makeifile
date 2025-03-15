//main.c
#include<stdio.h>
#include"parser.h"
int main(int argc,char *argv[]){
    if(argc<2){
        printf("用法：minimake<目标>\n");
        return 1;
    }
    //示例Makefile解析
    Rule rules[MAX_TARGERS];
    int rule_count=0;
    //解析规则（示例)
    parse_rule{"app:main utils.c",&rules[rule_count]};
    rule_count++;
    //检查重复目标和依赖
    check_duplicate_target(rules,rule_count,"app");
    check_dependencies(rules,rule_count);
    return 0;

}