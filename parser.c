#include<stdio.h>
#include<string.h>
#include"parser.h"
//解析单行规则
void parse_rule(const char *line,Rule*rule){
    char buffer[256];
    strcpy(buffer,line);
    //检查是否有冒号分隔符
    char *colon=strchr(buffer,':');
    if(colon==NULL){
        fprintf(stderr,"错误：目标行缺少冒号！\n");
        return ;
    }
    //提取目标
    *colon='\0';//分割字符串
    strncpy(rule->target,buffer,32);
    //提取依赖
    char *deps=colon+1;
    rule->dep_count=0;
    char *token=strtok(deps," ");
    while(token!=NULL&&rule->dep_count<MAX_DEPS){
        strncpy(rule->dependencies[rule->dep_count],token,32);
        rule->dep_count++;
        token=strtok(NULL," ");
    }
//假设下一行是命令(需要外部处理)
}
//检查依赖是否存在
void check_dependencies(Rule rule[],int rule_count){
    for(int i=0;i<rule_count;i++){
        for(int j=0;j<rules[i].dep_count;j++){
            const char *dep=rules[i].dependencies[j];
            int exists=0;
            //检查是否为文件或已定义的目标
            FILE*file=fopen(dep,"r");
            if(file!=NULL){
                fclose(file);
                exists=1;
            }else {
                for(int k=0;k<rule_count;k++){
                    if(strcmp(rules[k].target,dep)==0){
                        exists=1;
                        break;
                    }
                }
            }
            if(!exists){
                fprintf(stderr,"错误：依赖'%s'不存在！\n",dep);
            }
        }
    }
}