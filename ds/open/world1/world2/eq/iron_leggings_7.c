#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("�K�@�L",({"iron leggings","leggings"}) );
	set("long",@LONG
�o�O�@�����K��y�����}���@�L�C
LONG
);
	set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "��");
	}
        set("armor_prop/armor",7);
        setup();
        set("value",1180);
        set("volume", 4);
}

int query_autoload() { return 1; }
