#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(MAG"天狗皮"NOR,({ "skydog fur","fur" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","傳說中天狗身上的皮。\n");
                set("unit","張");
        }
        setup();
}
