#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW+BLK"闇夜"NOR+YEL"巨鱷"NOR"的皮"NOR,({ "crocodile fur","fur" }));
        set_weight(3000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","從闇夜巨鱷身上所撥下來的皮。\n");
                set("unit","張");
        }
        setup();
}

