#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM"�A���P"NOR,({"meet-fresh taro", "taro", "_GHOST_EXTRA_"}) );
        set("long",@LONG
�s�A�B�{���B�{�N�A�A���P�O���u�誺���~�P�i�Ͳ��~�A�İ_����
�h�����D�����~�A�p�P���P�몺���֡C

�C�J�A���P�i�H�����������1%���[���v�A�̰��i��30%�C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�J");
        }
        set("value", 100);
    
        setup();
}

