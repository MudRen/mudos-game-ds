#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�j�ƫ��|���K�c",({"s-fc iron boots","boots"}) );
	set("long",@LONG
�o�@���|�겣�~�s�y���K�־c�g�L�F����B�z�A�H�����ơC
LONG
);
	set_weight(5500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("value",1840);
	set("armor_prop/armor", 10);
	setup();
	set("volume", 4);
}

//int query_autoload() { return 1; }
