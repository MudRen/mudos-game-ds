#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"��"HIW"��"HIR"�U"NOR, ({ "godwind bag","bag" }) );
        set_weight(500);
        set_max_capacity(200);
        set_max_encumbrance(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("long", "�o�O�@�f�j�U�l�A���լ۶��A���G���_�����]�O�C\n");
                set("value",0);
                set("no_sac",1);
               }
        setup();
}
