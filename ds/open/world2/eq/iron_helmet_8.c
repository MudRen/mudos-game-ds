#include <armor.h>
inherit HEAD;

void create()
{
	set_name("�K�s�Y��",({"iron helmet","helmet"}) );
	set("long",@LONG
�o�O�@���Q����T���K�s�Y���C
LONG);
	set_weight(2470);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "��");
	}
        set("armor_prop/armor",8);
        setup();
        set("value",910);
        set("volume", 4);
}
int query_autoload() { return 1; }