#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "鋒魔劍" NOR , ({ "ghost sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "天下絕劍之一。
\n");
               set("value",1200);
               set("limit_int",3);
                set("volume",4);
               set("material", "copper");
        }
    init_sword(63);
   setup();
}
