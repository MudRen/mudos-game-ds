#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�ڽ��|"NOR, ({ "loo bou-gow","gow" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����ҭ��������C\n");
                set("unit", "��");
                set("value", 5000);  
                set("food_remaining",10);
                set("heal_hp",500);   
                set("heal_ap",500);
                set("heal_mp",500);
        }
}

