#include <ansi.h>      //newadd
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW"�´˪L�J�|"NOR, ({ "chocolate cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"�@�Ӵ��o�ۥ��J�O�������´˪L�J�|�C\n"NOR);
                set("unit", "��");
                set("value", 200);
                set("food_remaining",6);
                set("heal_ap",30+random(6));
        }
}