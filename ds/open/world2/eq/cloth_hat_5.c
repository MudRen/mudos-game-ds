#include <armor.h>
inherit HEAD;

void create()
{
	set_name("�p�v�U",({"cook hat","hat"}) );
	set("long",@LONG
�o�O�@���զ�������p�v�U�C
LONG);
	set_weight(1100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "��");
	}
        set("armor_prop/armor",5);
        setup();
        set("value",435);
        set("volume", 2);
}
int query_autoload() { return 1; }