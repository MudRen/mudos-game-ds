#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"���_�c"NOR,({"box"}));
        set("unit", "��");
        set("long",@LONG

  �˦��ܦh�ǪF�誺�c�l�A�]�O�d�p�s�����ؼСE

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
}
