#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIR"�i�f�i��-��"NOR, ({ "CocaCola","axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�⥨��Q���ӽo, �򭱧e���Ŧ�, ��b����W�Q,\n"
                            "�O�i�f�i�֪��M�Ω��Y�C\n");
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