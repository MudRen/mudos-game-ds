#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(GRN "��M��" NOR , ({ "green pill", "pill" }));
        set("long","�o�O�@����⪺���ġA�O�@���Q���������_���A���򳣯����_�C\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("value", 750);
           set("heal_hp",80);
                 set("heal_mp",80);
           set("heal_ap",80);
              set("food_remaining", 1);
        }
        setup();
}
