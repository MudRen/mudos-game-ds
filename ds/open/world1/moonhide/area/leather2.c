#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name(HIW"羽翼之衫"NOR,({ "leather cloth","cloth" }) );
        set("long","神鵰身上的毛皮，在神鵰死後，會自動脫落。\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "件" );
        set("value",2000);
        } 
        set("armor_prop/armor", 10); 
        set("armor_prop/dodge",5); 
        setup();
}
