#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIY"�~�G�J�|"NOR, ({ "mango cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"�@�ӥηs�A�~�G�s�����J�|\n"NOR);
                set("unit", "��");
                set("value", 100);
                set("food_remaining",6);
                set("heal_mp",30);
        }
}
