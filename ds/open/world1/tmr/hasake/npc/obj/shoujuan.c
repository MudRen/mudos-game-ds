// bandage.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "手絹", ({ "piece"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "方");
                set("material", "cloth");
                set("long", "這是一方雪白的手絹。\n");               
        }
}
