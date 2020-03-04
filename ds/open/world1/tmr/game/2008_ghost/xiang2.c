#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("蓮花香燭(lotus pudu xiang) [香火 %d 份]",query("time") );
}

void create()
{
        set_name("蓮花香燭",({"lotus pudu xiang", "xiang", "_GHOST_XIANG_"}) );
        set("long",@LONG
這是一份蓮花香燭，適用在各種祭拜場合。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","份");
        }
        set("value", 100);
        set("time", 100 + random(500) );
    
        setup();
        set("long", query("long") + getLong() );
}


