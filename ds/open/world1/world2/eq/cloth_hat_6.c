#include <armor.h>
inherit HEAD;

void create()
{
	set_name("���h�u�@�U",({"double cloth hat","hat"}) );
	set("long",@LONG
�o�O�@���զ⪺���h��´�u�@�U�C
LONG);
	set_weight(1270);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "��");
	}
        set("armor_prop/armor",6);
        setup();
        set("value",610);
        set("volume", 2);
}
int query_autoload() { return 1; }