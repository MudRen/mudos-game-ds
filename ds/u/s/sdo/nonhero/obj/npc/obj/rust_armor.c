#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("���ê�����",({"rusty armor","armor"}));
        set_weight(25000);            
        if( clonep() )
   	        set_default_object(__FILE__);
        else 
	{
     	set("unit", "��");
        set("material","steel");
       	set("long",@LONG 
�o�u�O�@����ê����ҡC
LONG
	);
  	set("value",100);
        set("volume",5);
        set("armor_prop/armor",1);  
        }
        setup();
}