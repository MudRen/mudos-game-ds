#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("破爛的盾",({"broken shield","shield"}));
        set_weight(4000);
        if( clonep() )
		set_default_object(__FILE__);
        else 
	{
        set("unit", "面");
        set("volume",5);
        set("long", @LONG
這是一面破破爛爛的盾牌。
LONG
	);
       	set("value",100);
        set("material","wood");
        }
        set("armor_prop/armor",1);
        setup();
}