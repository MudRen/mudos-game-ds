#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name("�����",({ "leather cloth","cloth" }) );
        set("long","���稭�W����֡A�b���禺��A�|�۰ʲ渨�C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",4);
        set("material","golden");
        set("unit", "��" );
        set("value",6000);
        } 
        set("armor_prop/armor", 5); 
        setup();
}
