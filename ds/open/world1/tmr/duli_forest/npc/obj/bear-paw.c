#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("灰熊斷掌",({"bear paw","paw","_QUEST_ITEM_BEAR_PAW_" }) );
    set("long",@LONG
這是一隻剛從灰熊身上割下來的熊掌，上頭還血淋淋的。
LONG
        );
        if(!clonep() )
        {
                set("value",0);
                set("unit","隻");
        }
        setup();
}


