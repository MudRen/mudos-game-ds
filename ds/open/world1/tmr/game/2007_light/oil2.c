#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�ѿO�O�o(lamp oil) [�e�q %d ���J]",query("time") );
}

void create()
{
        set_name("�ѿO���ſO�o",({"advanced lamp oil", "oil", "_LAMP_OIL_"}) );
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
        set("time", 50 + random(100) );
    
    setup();
        set("long", query("long") + getLong() );
}


