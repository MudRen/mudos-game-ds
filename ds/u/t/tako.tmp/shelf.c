#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"���B"HIW"��"NOR,({"poo ding shelf","shelf"}));
        set("unit", "��");
        set("long",@LONG
        
�@�ӥΥ��B�y�����������l,�]�i�H��F���i�h�C

  ��F��: put xxx in shelf
  ���F��: get xxx from shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(10000);
        setup();
}

