#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("��F�x�x�A" ,({ "ossifer's cloth","cloth" }) );
	set("long","�o��O��F�x���`�Ҭ�۪��@�M��A�C\n");
	set_weight(1200);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",2);
		set("material", "cloth");
		set("unit", "��" );
		set("value", 700);
	}
	set("armor_prop/armor", 6);
	setup();
}
