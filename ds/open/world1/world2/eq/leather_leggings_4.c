#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("�ֻs�j�L",({"leather leggings","leggings"}) );
	set("long",@LONG
�o�O�@���ֻs���j�L�C
LONG
);
	set_weight(1100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
        set("armor_prop/armor",4);
        setup();
        set("value",480);
        set("volume", 3);
}

int query_autoload() { return 1; }
