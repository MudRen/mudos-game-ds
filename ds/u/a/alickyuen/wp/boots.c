#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIR"�i�f�i��-�u"NOR, ({ "CocaCola","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���c�l�ܻ�, ��_�ӷ|�������ƵM���Pı�C\n");
		set("unit", "��");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",15000);
		set("armor_prop/dex",2);
		set("armor_prop/dodge",3);
		set("armor_prop/armor", 3);
	}
	setup();
}

int query_autoload() { return 1; }