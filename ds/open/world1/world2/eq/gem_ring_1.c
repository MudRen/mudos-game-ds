#include <armor.h>
inherit FINGER;
void create()
{
	set_name("�]�_�٫�",({"gem ring","ring"}) );
	set("long",@LONG
�k�H�߷R���]�_�٫��A�٭��^�F�@�Ӭ��_�ۡC
LONG
	);
	set_weight(510);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "�T");
	}
        set("armor_prop/armor",1);
        setup();
        set("value",1500);
        set("volume", 1);
}
int query_autoload() { return 1; }

