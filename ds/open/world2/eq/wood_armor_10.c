#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("����@��",({"wood armor","armor"}) );
	set("long",@LONG
�o�O�@��Τ���ꦨ���W�b���@�ҡC
LONG
);
	set_weight(7150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "��");
        }
        set("armor_prop/armor",10);
        setup();
        set("value",1630);
        set("volume", 8);
}

int query_autoload() { return 1; }
