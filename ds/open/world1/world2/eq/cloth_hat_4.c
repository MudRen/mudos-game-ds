#include <armor.h>
inherit HEAD;

void create()
{
	set_name("�Ŧ�u�@�U",({"blue cloth hat","hat"}) );
	set("long",@LONG
�o�O�@���Ŧ⪺�u�@�U�C
LONG);
	set_weight(970);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "��");
	}
        set("armor_prop/armor",4);
        setup();
        set("value",325);
        set("volume", 2);
}
int query_autoload() { return 1; }