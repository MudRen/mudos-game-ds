#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY"�F���C"NOR, ({ "ling yan sword", "testing" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��C�O�e�����j�̤l�U�A�F���M�ΨؼC�A�]�p�D�`�S�O�A�e���ϥΡC\n");
		set("value", 10000);
		set("material", "steel");
}
	init_sword(80);
	set("weapon_prop/tec", 1);
	set("wield_msg", "$N�˳�$n��A��P��ޥ��W�ɡC\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_steal", 1);
	setup();
}
void init()
{
	object room;

	room = environment(this_object());

	if( !room) return;

	if( !objectp(room) ) return;

	if( room->is_room() ) destruct(this_object());
}
