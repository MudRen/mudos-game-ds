// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;

void create()
{
	set_name(HIR"���b���C"NOR, ({ "sith double lightsaber","pike" }) );
	set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O"HIR"�y���Z���z"NOR"���M�ΪZ���C\n");
		set("value", 150000);
		set("no_sac",1);
		set("limit_int",20);
		set("limit_str",15);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",500);
		set("material", "blacksteel");
		set("wield_msg", "$N�q�y�W���X�@��$n,��M�Y�����O�g�X��D"HIR"�E��"NOR"�C\n");
		set("unwield_msg", "$N�N��W��$n��^�y���C\n");
		set("replica_ob",__DIR__"lightsaber4");
	}
    init_fork(80);
	setup();
}
int query_autoload() { return 1; }
