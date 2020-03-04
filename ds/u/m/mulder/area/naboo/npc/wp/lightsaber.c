// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
string *sabername = ({
	HIR+"���C"+NOR,
	HIW+"���C"+NOR,
	HIG+"���C"+NOR,
	HIC+"���C"+NOR,
	HIY+"���C"+NOR,
	HIM+"���C"+NOR,
	});
void create()
{
	set_name(sabername[random(sizeof(sabername))],({"lightsaber","saber"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O"HIW"�yJedi Knight�z"NOR"���аO�C\n");
		set("value", -1000);
		set("no_sac",1);
		set("limit_str",20);
		set("no_drop",1);
		set("no_steal",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",1000);
		set("material", "blacksteel");
		set("wield_msg", "$N�q�y�W���X�@��$n,$N���U���s,��M$n���X�@�D"HIG"�E��"NOR"�C\n");
		set("unwield_msg", "$N�N��W��$n��^�y���C\n");
	}
     init_sword(60,TWO_HANDED);
	setup();
}
int query_autoload() { return 1; }
