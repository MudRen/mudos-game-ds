#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("稍有缺口的"HIG"貝殼"NOR,({"breach shell","shell"}) );
        set_weight(30);
        set("long",@long
有著小缺口，看起來不是這麼的完美。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
                set("value",0);
        }
        setup();
}

