#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"�D�㳯�C�["NOR,({"item shelf","shelf"}));
        set("unit", "��");
        set("long",@LONG
        
  �@�ӥΨӦs��U���U�˹D�㪺�[�l�C�A�i�H��öQ���D���b�[
  �W�O�s�άO�q�[�l�����X�A�һݭn���D��C

  ��F��: put [�F��] in item shelf
  ���F��: get [�F��] from item shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(1999999);
	setup();
}


