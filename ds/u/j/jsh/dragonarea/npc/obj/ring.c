#include <ansi.h> 
#include <armor.h>
inherit FINGER;

void create() 
{
        set_name(HIG"��"HIW"��"HIY"�s"NOR,({ "finger dragon","finger","dragon" }) );
        set("long","�@���s���Ϯת��٫��A���G���S�O���\\�ġC\n");
        set_weight(8000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","gem");
                set("unit", "��" );
       set("value",2000);
set("armor_prop/armor", 4); 
set("armor_prop/dodge", 2);
set("armor_prop/ap", 100);
                
        }
        setup();
}

