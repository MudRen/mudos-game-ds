#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIB "�º���"NOR, ({ "pill" }));
        set("long","�o�@���O�Ѭ���i�f���Ŧ�p�ĤY�A�Q���öQ��C\n");
        set("weight", 20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("value", 1750);
              set("heal_hp",200);
              set("heal_mp",200);
             set("heal_ap",170);
              set("food_remaining", 1);
        }
        setup();
}
