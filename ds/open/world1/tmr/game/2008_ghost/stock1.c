#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�A�G���~(fruit-sacrifice stock) [�۷N %d ��]",query("time") );
}

void create()
{
        set_name("�A�G���~",({"fruit-sacrifice stock", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
�o�O�@����O�U���A�G�զX�����~�A�]�A����᪺��ʡA����|�����R��~�G
�A �٦����H�Y�F�����U�Ӫ��s�����C
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
        set("time", 1 + random(100) );
    
        setup();
        set("long", query("long") + getLong() );
}

