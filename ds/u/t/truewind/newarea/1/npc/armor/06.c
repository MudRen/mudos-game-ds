#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name("綠衫",({ "green dress","dress" }) );
        set("long","女子所穿的連身長衫，這件是綠色的。\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "件" );
        set("value",1000);
        set("armor_prop/armor", 1); 
        } 
        setup();
}