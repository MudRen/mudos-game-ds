
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ĵ�ò���",({"patrol armor","patrol","armor"}) );
	set("long","�o�O�@��ĵ�åΪ����ҡC\n");
	set_weight(8300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
		set("value",8300);
        	set("armor_prop/armor",3);
        }
        setup();
}

int query_autoload() { return 1; }
