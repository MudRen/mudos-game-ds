#include <armor.h>
inherit LEGGING;
void create()
{
	set_name("�@�L", ({ "leggings" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@�����q�Z�̽m�Z�ɮM�b�L�����F��, �O�@���`�λL�����ˡC\n");
		set("unit", "��");
		set("value",500);
		set("material", "linen");
		set("limit_int",5);
	}
	set("armor_prop/armor",2);
	set("armor_prop/shield",1);
	set("armor_prop/dex",1);
	setup();
}
