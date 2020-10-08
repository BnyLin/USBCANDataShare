#ifndef USBCANDATASHARE_H
#define USBCANDATASHARE_H

////文件版本：v1.00 20200222

//2.定义CAN信息帧的数据类型。
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
 
#define EXTERNC		extern "C"

EXTERNC void __stdcall CANDS_ResetSharedBuffer(void);
EXTERNC void __stdcall CANDS_WriteSharedBuffer(const PCANDS_CAN_OBJ pObj);
EXTERNC BOOL __stdcall CANDS_ReadSharedBuffer(PCANDS_CAN_OBJ pObj);

#endif
