#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�δο}"NOR, ({ "candy" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ڴδο}�A�i�Ա`�Y���s���C\n");
                set("unit", "��");
                set("value", 10);  
                set("food_remaining",50);
                set("heal_hp",0);
        }
}

