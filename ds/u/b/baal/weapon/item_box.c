#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"���_���c"NOR,({"treasure box","box"}));
        set("unit", "��");
        set("long",@LONG
        
  �@�ӥΨӦs���m�����S��άO��ڻ�ɪ̭̪��p�H���~�C�A�i
  �H��öQ�����~��J�c���O�s�άO�q�c�����X�A�һݭn�����~�C

  ��F��: put [�F��] in box
  ���F��: get [�F��] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
	setup();
        add_money("coin",10000000000);
}


