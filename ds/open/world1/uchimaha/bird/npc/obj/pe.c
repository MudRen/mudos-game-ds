#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"九尾的皮"NOR,({ "fox fur","fur" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","從九尾身上脫落下來的皮。\n");
                set("unit","張");
                set("value",0);
        }
        setup();
}
