#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"年獸鬚"NOR, ({ "monster-beard","beard" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "年獸的鬍鬚，十分有韌性。\n");
                set("unit", "根");
                set("value", 0);  
                set("no_put", 1);  
        }
       setup();
}
