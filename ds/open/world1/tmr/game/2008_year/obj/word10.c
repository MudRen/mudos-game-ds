#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("「屎」字",({"word", "__MOUSE_WORD__"}) );
        set("long",@LONG
這是一個喜氣洋洋，用白金鑄成的「屎」字。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
        }
        set("word","屎");
        set("value", 100);
            setup();
}

