#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIR"脆蟻殼"NOR,({ "ant armor","armor" }) );
        set("long","螞蟻王的殼, 有高度的防禦力。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",7000);
                set("armor_prop/armor", 55);
                set("armor_prop/dodge",-14);
        }
        setup();
}

