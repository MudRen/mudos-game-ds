#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("生鏽的盔甲",({"rusty armor","armor"}));
        set_weight(25000);            
        if( clonep() )
   	        set_default_object(__FILE__);
        else 
	{
     	set("unit", "件");
        set("material","steel");
       	set("long",@LONG 
這只是一件生鏽的盔甲。
LONG
	);
  	set("value",100);
        set("volume",5);
        set("armor_prop/armor",1);  
        }
        setup();
}