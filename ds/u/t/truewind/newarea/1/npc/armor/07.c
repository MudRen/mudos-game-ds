#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name("黑袍",({ "black suit","suit" }) );
        set("long","非常貼身的黑色袍子，穿著戰鬥可以更加敏捷。\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "件" );
        set("value",5000);
        set("armor_prop/armor", 7); 
        set("armor_prop/dex", 3);
        } 
        setup();
}