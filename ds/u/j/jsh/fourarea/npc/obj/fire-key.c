#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"���V"HIW"���_"NOR,({"key of fire","key"}));
        set("long",@long
�q���������W���U�Ӫ��@���_�͡Ať���q���A���G���S�O���\�ΡC
long
                );

        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("door","firekey");
                set("value", 1);
        }
        setup();
}

