#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("¸�y����(xiuqiu fish stock) [�۷N %d ��]",query("time") );
}

void create()
{
        set_name(HIM"¸�y����"NOR,({"xiuqiu fish stock", "fish", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
¸�y�����O�@�D���W���Ʋz�A�L���L��A���m�}�ɡA�f���A���A
�|�L�̵L���f�U�d���A�d�ʧѪ�C
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
        set("time", 1000 + random(1000) );
    
        setup();
        set("long", query("long") + getLong() );
}

