#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
	set_name(HIM"�����j"NOR, ({ "purple golden pike","pike" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��j����`�����O�ν�a�̰�ꪺ�H����Һc��,\n"
                            "�ӥB�j�b�H�}�����������y�Ӧ�, �Q���öQ�C\n");
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