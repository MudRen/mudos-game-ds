#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("�w�Ʀ窫", ({ "default cloth","cloth" }) );
	set("long", "�@��Ѻ�u��´�����窫�A���G���񥭱`�@���@��C\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",600);
	}
	setup();
}

