#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("藥材", ({ "drug" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("long","一片普通的藥材。\n");
                set("value",1);
                set("ma_game",1);
                }
        setup();
}
