#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("���᭻��(lotus pudu xiang) [���� %d ��]",query("time") );
}

void create()
{
        set_name("���᭻��",({"lotus pudu xiang", "xiang", "_GHOST_XIANG_"}) );
        set("long",@LONG
�o�O�@�����᭻��A�A�Φb�U�ز������X�C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
        }
        set("value", 100);
        set("time", 100 + random(500) );
    
        setup();
        set("long", query("long") + getLong() );
}


