#include <ansi.h>
inherit ITEM;

void create()
{
         set_name( HIW "天使之卵" NOR , ({ "angel egg", "egg", "_ANGLE_EGG_"}));
        set("long", "這是一顆散發著潔白光輝的石頭。\n");
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("value", 0);
                  set("no_put", 1);
                start_light(1);
        }
        setup();
}


