#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY"���㳯�C�["NOR,({"equip shelf","shelf"}));
        set("unit", "��");
        set("long",@LONG
        
  �@���\��۳\�h���㪺�K�[�C�A�i�H��@�Ǩ����b�[�W�O�s�άO�q
  �[�l�����F��X�ӡC

  ��F��: put [�F��] in equip shelf
  ���F��: get [�F��] from equip shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); //2003.4.16 10000->400 by ksj
        setup();
}
