inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(WHT"�����"NOR, ({ "stone", "open-war-stone" }));
        set("long", "�@���Ϊ��_�S�����Y, �W�����W�}���㪺�ܦ��W��. \n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 1);
                set("no_sell", 1);
                set("no_sac", 1);
        }
        setup();
}


