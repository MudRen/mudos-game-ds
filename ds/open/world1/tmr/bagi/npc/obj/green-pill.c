#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�M�F��", ({ "green pill","pill" }));
        set("long",
"�@���e�t��⪺�ĤY�A���O�H�����Ѹ����ĪG�C\n"
        );
        set_weight(220);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("value", 500);
        set("heal_mp",70+random(16));
        set("eat_msg","$N�Y�U�@���M�s������ĤY�C\n");
        set("eff_msg",HIM "�@�ѲM�D�����D���ħA�F¬�C\n" NOR );
        set("food_remaining", 20);
        }
        setup();
}


