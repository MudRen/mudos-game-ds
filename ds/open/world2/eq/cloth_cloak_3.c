#include <armor.h>
inherit SURCOAT;

void create()
{
	set_name("�j�D�y",({"bath towel","towel"}) );
	set("long",@LONG
�o�O�@��̥զ⪺�j�D�y�C
LONG
);
	set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "��");
	}
	set("value",580);
	set("armor_prop/armor", 3);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
