#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
	set_name(HIR"�i�f�i��-�j"NOR, ({ "CocaCola","pike" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��j����`�����O�ν�a�̰�ꪺ�H����Һc��,\n"
                            "�O�i�f�i�ֱM�Ϊ��j, �Q���öQ�C\n");
		set("value", 20000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "gold");
	}
    set("weapon_prop/str",2);
    set("weapon_prop/bar",1);
    set("weapon_prop/hit",5);
    init_fork(20);
    setup();
}

int query_autoload() { return 1; }