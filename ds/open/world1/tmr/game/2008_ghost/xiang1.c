#include <ansi.h>
inherit ITEM;

string getLong()
{
        return sprintf("香燭(pudu xiang) [香火 %d 份]",query("time") );
}

void create()
{
        set_name("香燭",({"pudu xiang", "xiang", "_GHOST_XIANG_"}) );
        set("long",@LONG
這是一份香燭用品，適用在各種祭拜場合。
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
        set("time", 1 + random(100) );
    
        setup();
        set("long", query("long") + getLong() );
}


