#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("��M", ({ "stab blade" }) );
	set_weight(2100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��ť���M�H����H�Ϊ��M�C\n");
		set("value", 1200);
	}
	init_blade(24);
	setup();
}
