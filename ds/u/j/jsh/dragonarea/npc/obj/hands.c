#include <ansi.h> 
#include <armor.h>
inherit WRISTS;

void create() 
{
        set_name(HIY"�s"HIW"���@��"NOR,({ "dragon hands","hands" }) );
        set("long","�@���s�����@�áC\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",2000);
set("armor_prop/armor", 7); 
set("armor_prop/dodge", -2);
                
        }
        setup();
}

