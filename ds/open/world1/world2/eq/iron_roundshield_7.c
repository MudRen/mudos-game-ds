#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("�K���",({"iron round shield","shield"}) );
	set("long",@LONG
�o�O�@���j��ޡC
LONG);
	set_weight(2370);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","wood");
		set("unit", "��");
	}
        set("armor_prop/armor",7);
        setup();
        set("value",1810);
        set("volume", 6);
}
int query_autoload() { return 1; }
