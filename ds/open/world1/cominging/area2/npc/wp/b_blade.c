#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("�j�M", ({ "big blade","blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��j�M�A���W���ۨ��K�áC\n");
		set("value", 3100);
		set("weapon_prop/damage",4);
	}
	init_blade(26);
	setup();
}
