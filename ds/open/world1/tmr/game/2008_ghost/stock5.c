#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("����ױ�(snow pork stock) [�۷N %d ��]",query("time") );
}

void create()
{
        set_name(HIW"����ױ�"NOR,({"snow pork stock", "pork", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
����ױ��O�H�ަر��׬��D�A�f�t�s�A�F�J�Ϊo�渭�A�i�N�Ӧ��A
�O�@�D���W���|�t�Ʋz�C
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

