#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIR"������"NOR, ({ "beef noodle","noodle" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�J���j���j�����ת��ѡC\n");
                set("unit","�J");
                    set("value",600);
           set("heal_hp",50);
                set("food_remaining",3);
     }
     setup();
}
