#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("����",({"wood round shield","shield"}) );
	set("long",@LONG
�o�O�@���j��ޡC
LONG);
	set_weight(870);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","wood");
		set("unit", "��");
	}
        set("armor_prop/armor",3);
        setup();
        set("value",210);
        set("volume", 4);
}
int query_autoload() { return 1; }
