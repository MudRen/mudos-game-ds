#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("�j���K�@�L",({"adv-iron leggings","leggings"}) );
	set("long",@LONG
�o�@�����K��y�����}���@�L�g�L�F�j�ƳB�z�C
LONG
);
	set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "��");
	}
        set("armor_prop/armor",8);
        setup();
        set("value",1420);
        set("volume", 4);
}

int query_autoload() { return 1; }
