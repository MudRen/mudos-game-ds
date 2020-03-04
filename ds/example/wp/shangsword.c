#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
	set_name(HIG"�����C"NOR, ({ "shang-ing sword", "sword", "shang-in" }));
	set("long", "�o��C�w�g���Q���[�������v, �ǻ��O�e�����}�s���v�d�U���_�C�C\n");
	set_weight(12500);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("volume",2);
		set("material", "crimsonsteel");
		set("limit_skill",50);
		set("limit_int",25);
		set("limit_dex",25);
       set("value",10000);
		set("limit_lv",        15);
	set("replica_ob",__DIR__"longsword");
	}
	set("weapon_prop/hit", 15);
	set("weapon_prop/con",  2);
	set("weapon_prop/dex",2);

	set("wield_msg","$N�q�y���W��X�@��"HIY"$n"NOR"�C\n");
	set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");

	init_sword(65);
	setup();
}
