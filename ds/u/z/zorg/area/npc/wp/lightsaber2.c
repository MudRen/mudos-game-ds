// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIR"���C"NOR, ({ "lightsaber","saber" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O"BLK"�y�ªZ�h�z"NOR"�`�Ϊ��Z���C\n");
		set("value", 150000);
		set("no_sac",1);
		set("limit_int",20);
		set("limit_str",15);
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",500);
		set("material", "laser");
		set("wield_msg", "$N�q�y�W���X�@��$n,��M�g�X�@�D"HIR"�E��"NOR"�C\n");
		set("unwield_msg", "$N�N��W��$n��^�y���C\n");
	}
    init_sword(50);
	setup();
}
int query_autoload() { return 1; }
