#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�֭��D�c",({"leather sandals","sandals"}) );
	set("long",@LONG
�o�O�@���֭��s���D�c�C
LONG
);
	set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("value",380);
	set("armor_prop/armor", 3);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
