#include <armor.h>
inherit LEGGING;
void create()
{
	set_name("�ȵ��@�L", ({ "steel leggings","leggings" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@���]���h�h�ȵ����@�L, �i�H���Ѥ@�w�����m�O�C\n");
		set("unit", "��");
		set("value",1500);
		set("material", "steel");
		set("limit_con",15);
	}
	set("armor_prop/armor",4);
	set("armor_prop/shield",2);
	set("armor_prop/dex",1);
	setup();
}
