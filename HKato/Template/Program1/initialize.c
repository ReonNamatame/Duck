#include "initialize.h"
#include "iodefine.h"

void initialize(void)
{
	//���W�X�^���C�g�v���e�N�V������OFF
	SYSTEM.PRCR.WORD 	= 0xA50B;
	
	//�N���b�N	
	SYSTEM.SCKCR.BIT.PCKB = 0x0;		//���Ӄ��W���[���N���b�N1����
	SYSTEM.SCKCR.BIT.PCKD = 0x0;		//���Ӄ��W���[���N���b�N1����
	SYSTEM.SCKCR.BIT.ICK = 0x0;		//�V�X�e���N���b�N1����
	SYSTEM.SCKCR3.BIT.CKSEL = 0x01;		//��N���b�N��HOCO�ɐݒ�
	SYSTEM.HOCOCR2.BIT.HCFRQ = 0x0; 	//HOCO������g����32MHz�ݒ�
	SYSTEM.HOCOCR.BIT.HCSTP = 0x0; 		//HOCO����J�n
	SYSTEM.HOCOPCR.BIT.HOCOPCNT = 0x0;	//HOCO�̓d��ON
	
	//GPIO�ݒ�
	
}