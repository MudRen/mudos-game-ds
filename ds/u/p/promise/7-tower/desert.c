#include <ansi.h>
inherit ROOM;

string *room_long = 
({
//1
"�b�@��L�ڪ��F�z���A�n������������ⳣ�@�Ҥ@�ˡA�[�W�Ѯ�
�����ż��A�b�o�̦h�ݤ@�ɥb�賣�O�@�طμ��C���G�W�ѨSť��A��
�ߪ��o�ۡA�ݻŪ��Ѯ���«���C\n",
//2
"�u�u���F�б��\\�F�e�����h���A���A�N���M�{�b�Ҧb���a�z��m
�s���O�b���A�O���F�٬O�V��A���G�S���@�ӵ��סA�{�b�ߤ@�����N
�O�A�쩳�o���F�мɦ�ɧ����C�C\n",});

string ROOM_LONG()
{
        return room_long[random(sizeof(room_long))];
}


