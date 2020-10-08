#ifndef USBCANDATASHARE_H
#define USBCANDATASHARE_H

////�ļ��汾��v1.00 20200222

//2.����CAN��Ϣ֡���������͡�
typedef  struct  _CANDS_CAN_OBJ{
	UINT	ID;
	//UINT	TimeStamp;
	//BYTE	TimeFlag;
	//BYTE	SendType;
	//BYTE	RemoteFlag;//�Ƿ���Զ��֡
	//BYTE	ExternFlag;//�Ƿ�����չ֡
	BYTE	DataLen;
	BYTE	Data[8];
	//BYTE	Reserved[3];
}CANDS_CAN_OBJ,*PCANDS_CAN_OBJ; 
 
#define EXTERNC		extern "C"

EXTERNC void __stdcall CANDS_ResetSharedBuffer(void);
EXTERNC void __stdcall CANDS_WriteSharedBuffer(const PCANDS_CAN_OBJ pObj);
EXTERNC BOOL __stdcall CANDS_ReadSharedBuffer(PCANDS_CAN_OBJ pObj);

#endif
