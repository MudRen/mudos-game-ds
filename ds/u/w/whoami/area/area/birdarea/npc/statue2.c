#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW""BLK"石像"NOR, ({ "statue"}));
        set("long", 
"這是一尊雕工粗糙的石像，從它釉黑的顏色看來，應該是屬於深\n"
"山礦石。石像的頭看起來有被人轉動的痕跡....\n");
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

