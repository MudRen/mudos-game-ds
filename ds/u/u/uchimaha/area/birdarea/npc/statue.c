#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW""BLK"石像"NOR, ({ "statue"}));
        set("long", "這是一個全身釉黑的石像, 石像的眼睛看起來有被人推動的痕跡....\n");
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "個");
                set("value", 1);
                set("no_get", 1);
                set("no_sac", 1);
        }
        setup();
}

