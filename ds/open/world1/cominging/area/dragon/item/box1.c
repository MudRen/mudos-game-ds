#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�{�ɸm���c",({"box"}));
        set("unit", "��");
        set("long",@LONG
        
  �@�ӯ}�ª��c�l�C�W���ٵe�F�@���j�s�����ϮסC�A�i�H��@����
����b�̭��άO�q�̭����F��X�ӡC

  ��F��: put [�F��] in box
  ���F��: get [�F��] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
      set_max_capacity(400); //2003.4.16  10000 -> 400  by ksj
        setup();
}

