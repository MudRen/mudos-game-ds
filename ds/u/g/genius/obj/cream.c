#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIB"�����B�N�O"NOR,({"Black Cherry Ice Cream","cream"}));
        set_weight(90);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����Υ����a�հt���B�N�O�C\n");
                set("unit", "�M");
                set("value",48000);
                set("heal_hp",3000);
               set("food_remaining",1);
        }
     setup();
}

