#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�@���窺�O�o",({"kilogram lamp oil", "oil", "_LAMP_OIL_"}) );
        set("long",@LONG
�o�O�@�ӳy���륩�����~�A���Y�˵��I�U�ѿO�Ϊ��O�o�C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�~");
        }
        set("value", 1);
        set("time", 1000 );
        setup();
}


