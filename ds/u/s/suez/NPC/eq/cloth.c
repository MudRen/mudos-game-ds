#include <armor.h>

inherit CLOTH;

void create()
{
set_name("布衣",({"cloth"}) );

set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一件普通的布衣，無論你再怎麼看，它仍然只是\n"
                "件布衣，如果你想拿它當抹布也沒有人會反對的。\n"
 );
set("material", "cloth");
set("unit", "件");
set("value",100);

set("armor_prop/armor", 2);

        }
        setup();
}
