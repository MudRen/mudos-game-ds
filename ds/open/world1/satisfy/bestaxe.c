#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIC"���ũ�"NOR, ({ "best blue axe","axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�⥨��Q���ӽo, �򭱧e���Ŧ�, ��b����W�Q,\n"
                            "�O�@�⤣�i�h�o���n���Y�C\n");
		set("value", 20000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "steel");
	}
    set("weapon_prop/con",2);
    set("weapon_prop/bar",1);
    init_axe(30);
    setup();
}

int query_autoload() { return 1; }