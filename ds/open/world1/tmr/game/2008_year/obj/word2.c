#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�u�ӡv�r",({"word2", "__MOUSE_WORD__"}) );
        set("long",@LONG
�o�O�@�ӳ߮�v�v�A�Υժ�ű�����u�ӡv�r�C
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
        }
        set("word","��");
        set("value", 100);
	    setup();
}


