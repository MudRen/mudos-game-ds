#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"黃金便便"NOR,({ "gold-shit","shit" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一沱黃金做成的便便..是sexking的玩物。\n");
                set("unit","沱");
                set("value",0);
        }
        setup();
}

