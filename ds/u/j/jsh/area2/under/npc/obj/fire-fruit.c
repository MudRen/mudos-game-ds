#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"�����G"NOR, ({ "fire fruit","fruit" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�j�Ӹ̪������W�G�l�A�~�[�O�������@���A�����ᱼ���b�a�W�C\n");
                set("unit", "��");
                set("value", 3000);  
                set("food_remaining",5);
                set("heal_hp",500);  
        }
}

