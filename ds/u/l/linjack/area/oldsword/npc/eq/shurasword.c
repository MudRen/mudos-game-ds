#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name("��ù�]�C", ({ "shura sword","sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o����C�۶ǬO�|�j�F�C����, �O�ѥ��v���ˤ�һs, ĭ���F��C\n");
		set("value", 60000);
		set("material", "crimsonsteel");
		set("wield_msg",HIW"$N�u��v�a�@�n��X�@��$n���b�⤤, �y�ɩ����U�V!\n"NOR);
		set("unwield_msg",CYN"$N�N�⤤��$n���^�C�T����, �|�P���~�����t�H�C\n");
		set("limit_skill",60);
		set("limit_int",45);
		set("limit_dex",45);
                set("replica_ob",__DIR__"shurasword2");
	}
    set("weapon_prop/dex",2);
    set("weapon_prop/con",2);
    set("weapon_prop/parry",5); 
    set("weapon_prop/int",2);
    set("weapon_prop/str",2);
    set("weapon_prop/hit",5);
    init_sword(62);
    setup();
}
