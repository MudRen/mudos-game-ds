// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( GRN "���M���O" NOR, ({ "houndbane blade", "houndbane", "blade" }) );
	set_weight(17000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��t��⪺���Y�M�M���b�⤤�H�l�l�a�C\n");
		set("value", 42000);
		set("material", "crimsonsteel");
		set("wield_msg", "$N�u�B�v�a�@�n��X�@��I�p�b����$n���b�⤤�C\n");
		set("unequip_msg", "$N�N�⤤��$n���J�y�����M�T�C\n");
	}

	init_blade(96);
	set("weapon_prop/courage", 10);
	setup();
}
