#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"�|�F��ù�C"NOR, ({ "four shura sword","sword" }) );
	set_weight(17500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o����C�۶ǬO�|�F�C����, �O�ѥ|�F�C���ˤ�һs, ĭ���F��C\n");
		set("value", 6000);
		set("material", "crimsonsteel");
		set("wield_msg",HIW"$N�u��v�a�@�n��X�@��$n���b�⤤, �y�ɩ����U�V!\n"NOR);
		set("unwield_msg",CYN"$N�N�⤤��$n���^�C�T����, �|�P���~�����t�H�C\n");
		set("limit_skill",75);
		set("limit_int",45);
		set("limit_dex",45);
		set("weapon_prop/dex",3);
		set("weapon_prop/con",3);
		set("weapon_prop/parry",10);
		set("weapon_prop/int",3);
		set("weapon_prop/str",3);
		set("weapon_prop/hit",10);
	}
    init_sword(125);
    setup();
}
