// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("��ͤ��]",({"undeath ball","ball","undead_item"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value",0);
		set("no_drop",1);
		set("can_give",1);
		set("needaward",5);
		set("unit","��");
		set("long",@LONG
  �@���C�Ŧ⪺�����]�C�̭�ĭ�t�F�j�N�����z�P�L�W���]�O�A
�]�l�̭��^�F�ӤH�Τp�참�A����¶�ۯ��t���F��C
[SAVE]
LONG
		);
	}
		set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�z���F!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }
