#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�E��^�R��", ({ "nine pill","pill" }));
        set("long",
"�@���V�¦⪺���Y�A�����a�������A�ݤ��X��ĥΦp�ΡC\n"
        );
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("value", 400);
        set("heal_hp",60+random(11));
        set("food_remaining", 20);
        set("eat_msg","$N�Y�U�@���¦⪺�ĤY�C\n");
        set("eff_msg",HIG "�Aı�o�@�}�}�W���b�L�̴��}��...\n" NOR );
        }
        setup();
}

