#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name(HIW"���l���m"NOR,({ "leather cloth","cloth" }) );
        set("long","���稭�W����֡A�b���禺��A�|�۰ʲ渨�C\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "��" );
        set("value",2000);
        } 
        set("armor_prop/armor", 10); 
        set("armor_prop/dodge",5); 
        setup();
}
