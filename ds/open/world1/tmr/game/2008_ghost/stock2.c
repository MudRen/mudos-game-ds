#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�T�����~(animal-sacrifice stock) [�۷N %d ��]",query("time") );
}

void create()
{
        set_name("�T�����~",({"animal-sacrifice stock", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
�o�O�@�����n���ת��T�����~�A�ΨӦb�����`�����|��n�S�̡C
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


