#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name(HIG"�����C"NOR, ({ "shang in sword","sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��C�w�g���Q���[�������v, �ǻ��O�e�����}�s���v�d�U���_�C�C\n");
		set("value", 30000);
		set("material", "crimsonsteel");
		set("limit_skill",50);
		set("limit_int",25);
		set("limit_dex",25);
		set("weapon_prop/dex",2);
		set("weapon_prop/con",2);
		set("weapon_prop/parry",10);
		set("weapon_prop/hit",5);
		set("replica_ob",__DIR__"fakesword");
	}
    init_sword(65);
    setup();
}
