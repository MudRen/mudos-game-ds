// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
      set_name("ø�z������",({"erika doll","doll","undead_item"}));
	set_weight(100);
          set("value",10000);
		set("unit","��");
		set("long",@LONG
ø�z���嫬A���A����160cm�Aø�z���W�r�ѨӬO�᪺�W�r�A���Y��
�쪺�@��(Erica)�C�~�������p�֤k�몺�M�¡A���ʮ�o�O�ʪK�j���A
ø�z�����H�����ۤv���өʫܨk�Ĥl��C
LONG
		);
		set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);

setup();
}

