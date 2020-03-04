#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name("�Ѥb�E���W", ({ "sky cloud blade","blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���M�_���ӻ�, ���o�Q����w, �����O��ت��ݩ�ű,\n"
                            "�Ǩ��O���v���ˤ⥴�y���M�C\n");
		set("value", 20000);
		set("material", "blacksteel");
		set("wield_msg",HIC"$N�w�w�q�M�T���ޥX$n�C\n"NOR);
		set("unwield_msg",CYN"$N�N�⤤��$n���^�M�T�����C\n"NOR);
		set("limit_skill",50);
		set("limit_int",15);
		set("limit_dex",25);
                set("replica_ob",__DIR__"c_fist");
	}
    set("weapon_prop/dex",2);
    set("weapon_prop/con",-2);
    set("weapon_prop/int",2);
    set("weapon_prop/str",-2);
    set("weapon_prop/hit",10);
    init_blade(65);
    setup();
}
