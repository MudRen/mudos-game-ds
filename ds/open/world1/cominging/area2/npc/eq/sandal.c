#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("��c", ({ "sandal", "��c" }) );
	set("long","�o�O�b�@��a�賣�����쪺�@�ظ}������C\n");
	set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value" , 220);
		set("armor_prop/armor", 2);
		set("armor_prop/shield", 1);
	}
	setup();
}
