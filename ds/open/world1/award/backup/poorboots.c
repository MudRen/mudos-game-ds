#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("����c", ({ "water boots","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���c�l�ܻ�, ��_�ӷ|�������ƵM���Pı�C\n");
		set("unit", "��");
		set("material", "cloth");
	set("needaward",9);
	set("value",1);
	}
	set("armor_prop/dex",3);
	set("armor_prop/dodge",30);
	set("armor_prop/armor",6);
	setup();
}

int query_autoload() { return 1; }
