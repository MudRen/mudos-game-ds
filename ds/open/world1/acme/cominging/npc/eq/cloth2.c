#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("�Ǧ�l��" ,({ "grey cloth","cloth" }) );
	set("long","�o�O��x�L�Τ@��۪���A�C\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
		set_weight(2500);
		set("material", "cloth");
		set("unit", "��" );
		set("value",1000);
	}
	set("armor_prop/armor", 10);
	setup();
}
