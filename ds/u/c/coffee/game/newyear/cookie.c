#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�j��"NOR, ({ "cookie","cookie" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���F�L�~�S�O�s�@���j��C\n");
                set("unit", "��");
                set("value", 0);  
                set("food_remaining",7);
                set("heal_hp",500);
                set("heal_ap",500);
                set("heal_mp",500);
        }
}


