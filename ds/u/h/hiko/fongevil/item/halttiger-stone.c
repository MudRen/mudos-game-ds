#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("半虎石", ({ "halftiger stone", "stone" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
        "一個雕著虎的石雕，可是只有一半\n");
                set("unit", "顆");
                set("value",0);                
        }
        setup();
}






