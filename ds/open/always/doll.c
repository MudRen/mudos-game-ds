// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("��������",({"death doll","doll","undead_item"}));
	set_weight(100);
		set("value",0);
		set("no_drop",1);
		set("can_give",1);
		set("unit","��");
		set("long",@LONG
  �@�Ӹ޲����v�����C�����⪺�Ȥl�W���۳\�h�զ⪺�p���I�A
�R�����������F��...�A���G�ݨ�o�b�w����!? �o...
[SAVE] [ANY-TIME]
LONG
		);
		set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }
