#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name("羽鵰皮",({ "leather cloth","cloth" }) );
        set("long","神鵰身上的毛皮，在神鵰死後，會自動脫落。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",4);
        set("material","golden");
        set("unit", "件" );
        set("value",6000);
        } 
        set("armor_prop/armor", 5); 
        setup();
}
