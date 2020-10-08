// USBCANDataShare.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

typedef  struct  _CANDS_CAN_OBJ{
	UINT	ID;
	//UINT	TimeStamp;
	//BYTE	TimeFlag;
	//BYTE	SendType;
	//BYTE	RemoteFlag;//是否是远程帧
	//BYTE	ExternFlag;//是否是扩展帧
	BYTE	DataLen;
	BYTE	Data[8];
	//BYTE	Reserved[3];
}CANDS_CAN_OBJ,*PCANDS_CAN_OBJ; 

extern "C" __declspec(dllexport)void CANDS_ResetSharedBuffer(void);
extern "C" __declspec(dllexport)void CANDS_WriteSharedBuffer(const PCANDS_CAN_OBJ pObj);
extern "C" __declspec(dllexport)BOOL CANDS_ReadSharedBuffer(PCANDS_CAN_OBJ pObj);

#define BUF_LEN 10000

#pragma data_seg("DLLSharedSection")      // 声明共享数据段，并命名该数据段
int CANDS_wrIdx = 0;       // 必须在定义的同时进行初始化!!!!
int CANDS_rdIdx = 0;
CANDS_CAN_OBJ CANDS_arr[BUF_LEN] = {0};
#pragma data_seg()
#pragma comment(linker,"/SECTION:DLLSharedSection,RWS")

void CANDS_ResetSharedBuffer(void)
{
	CANDS_rdIdx = CANDS_wrIdx;
}

void CANDS_WriteSharedBuffer(const PCANDS_CAN_OBJ pObj)
{
	CANDS_wrIdx++;
	if (CANDS_wrIdx >= BUF_LEN)
	{
		CANDS_wrIdx = 0;
	}
	memcpy(&CANDS_arr[CANDS_wrIdx], pObj, sizeof(CANDS_CAN_OBJ));
}

BOOL CANDS_ReadSharedBuffer(PCANDS_CAN_OBJ pObj)
{
	BOOL newDataFlag;

	if (CANDS_wrIdx == CANDS_rdIdx)
	{
		newDataFlag = FALSE;
	}
	else
	{
		newDataFlag = TRUE;
		CANDS_rdIdx++;
		if (CANDS_rdIdx >= BUF_LEN)
		{
			CANDS_rdIdx = 0;
		}
		memcpy(pObj, &CANDS_arr[CANDS_rdIdx], sizeof(CANDS_CAN_OBJ));
	}

	return newDataFlag;
}