#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIY"�����"NOR, ({ "gold axe","axe" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�⥨��Q���ӽo, ��b�O�Ѷ����X���ҥ��y, ���Q��\n"
                            "���^���, �ϱo���򪺱��ˤO�Q����H�C\n");
		set("needaward",30);
		set("material", "gold");
	set("value",1);
	}
    set("weapon_prop/str",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/sou",-1);
    init_axe(77,TWO_HANDED);
    setup();
}

int query_autoload() { return 1; }
