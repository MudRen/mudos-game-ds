#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIB "���s��" NOR , ({ "blue dragon pill", "pill" }));
        set("long","�o�O�@���Ŧ⪺���ġA�����_�j�q����O�C\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
               set("value",300);
                   set("heal_hp",100);
              set("food_remaining", 1);
        }
        setup();
}
