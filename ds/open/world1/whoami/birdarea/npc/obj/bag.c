#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"����"HIR"�U"NOR, ({ "godwind bag","bag" }) );
        set_weight(600);
        set_max_capacity(400);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("long", "�o�O�@�f�j�U�l�A���լ۶��A���G���_�����]�O�C\n");
                set("value",5000);
               }
        setup();
}

