#ifndef PARSE_H
#define PARSER_H
#define MAX_TARGERS 10
#define MAX_DEPS 10
#define MAX_COMMAND_LEN 256
typedef struct{
    char target[32];//目标名称
    char dependencies[MAX_DEPS][32];//依赖列表
    int dep_count;//依赖数量
    char command[MAX_COMMAND_LEN];//编译命令
}Rule;
//函数声明
void parse_rule(const char *line,Rule*rule);
void check_duplicate_target(Rule rules[],int rule_count,const char *target);
void check_dependencies(Rule rules[],int rule_count);
#endif