#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
	set_name(HIM"�����j"NOR, ({ "purple golden pike","pike" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��j����`�����O�ν�a�̰�ꪺ�H����Һc��,\n"
                            "�ӥB�j�b�H�}�����������y�Ӧ�, �Q���öQ, �ӥB�j��\n"
                            "���u, ��n�i�H��ⴧ�R, �������������j�סC\n");
		set("needaward",30);
	set("value",1);
		set("material", "gold");
	}
    set("weapon_prop/str",2);
    set("weapon_prop/bar",1);
    set("weapon_prop/sou",-1);
    init_fork(58);
    setup();
}

int query_autoload() { return 1; }
