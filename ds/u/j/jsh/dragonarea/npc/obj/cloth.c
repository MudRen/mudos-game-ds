#include <ansi.h> 
#include <armor.h>
inherit CLOTH;

void create() 
{
        set_name("�զ�",({ "white cloth","cloth" }) );
        set("long","�@���������դW��C\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","skin");
                set("unit", "��" );
       set("value",600);
                set("armor_prop/armor", 3);
                
        }
        setup();
}

