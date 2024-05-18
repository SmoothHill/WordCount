#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
int countCharacters(FILE* file);
int countWords(FILE* file);

int main() {
    char parameter[10];
    char inputFileName[100];

    // 提示用户输入参数和文件名
    printf("请输入参数（-c 或 -w）：");
    scanf("%s", parameter);
    printf("请输入要处理的文件名：");
    scanf("%s", inputFileName);

    // 打开文件(file指向文件的指针)
    FILE* file = fopen(inputFileName, "r");
    if (file == NULL) {
        printf("打开文件错误。\n");
        return 1;
    }

    // 统计字符数或单词数
    int count = 0;
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("字符数：%d\n", count);
    }
    else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("单词数：%d\n", count);
    }
    else {
        printf("无效参数。请使用 -c 或 -w。\n");
        return 1;
    }

    // 关闭文件
    fclose(file);

    return 0;
}

// 统计字符数
int countCharacters(FILE* file) {
    int count = 0;
    int c;

    //// 循环读取文件中的每一个字符，直到文件结束符 EOF
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// 统计单词数
int countWords(FILE* file) {
    int count = 0;

    //用于标记当前是否处于一个单词内部的变量，0表示不在单词内，1表示在单词内
    int inWord = 0;

    //// 用于存储读取的字符的变量
    int c;
    while ((c = fgetc(file)) != EOF) {
        // 如果当前字符是空格、换行符或制表符,标记不在单词内
        if (c == ' ' || c == '\n' || c == '\t') {
            inWord = 0;
        }
        else if (!inWord) {
            count++;
            inWord = 1;
        }
    }
    return count;
}







