#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�G��������", ({ "chick pill","pill" }));
        set("long",
"�@���e����������Y�A�J�󲤱a�{���C\n"
        );
        set_weight(220);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("value", 500);
        set("heal_ap",70+random(16));
        set("eat_msg","$N�Y�U�@���t���a������ĤY�C\n");
        set("eff_msg",HIB "�@�Ѹ{�䪺���D�b�A�L�̤[�[����...\n" NOR );
        set("food_remaining", 20);
        }
        setup();
}

