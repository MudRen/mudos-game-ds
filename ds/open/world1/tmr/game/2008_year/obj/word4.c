#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�u�B�v�r",({"word4", "__MOUSE_WORD__"}) );
        set("long",@LONG
�o�O�@�ӳ߮�v�v�A�Υժ�ű�����u�B�v�r�C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
        }
        set("word","�B");
        set("value", 100);
	    setup();
}


