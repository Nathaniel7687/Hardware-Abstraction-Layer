#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <math.h>
#include <tgmath.h>

#include "linked_list.h"
#include "hanback_device.h"

typedef enum {false, true} bool;

enum COMPANY_NUM {
	HANBACK
};

#define FILTER_OPT_BACKDATA     3
#define FILTER_OPT_DEPLACEMENT  4
#define FILTER_OPT_AVERAGE      5
#define FILTER_OPT_NONFILTERD	6
#define FILTER_OPT_FILTER		7

int F_checkStartBit(listNode *, unsigned char *);//센서에서오는 메시지들을 처음과 끝비트 온전하게 받기위하여서 첫비트를  비교할때 사용하는 함수
void F_readData(listNode* );//sensor 데이터를 센서에 해당하는 데이터 길이만큼 읽어온다
void F_analyzeData(listNode *, unsigned char *, int);//sensor data분석

void F_printUserData(listNode* , int data_opt);//데이터 분석을 마친 Queueing 한 데이터를 출력
void F_printQueueData(listNode* , int data_opt);
void F_printRawData(listNode* , int data_opt);

int F_filterHanbackWeather(listNode *p, int i, int data);//한백전자 weather 센서를 필터링
int F_filterHanbackThermometer(listNode *p, int index);//한백전자 thermometer 센서를 필터링
int F_filterHanbackDioxide(listNode *p, int index);
int F_filterHanbackDust(listNode* p, int index);
int F_filterHanbackVOC(listNode* p, int index);
int F_filterHanbackSensor(listNode* p,int index,int data);//data return
