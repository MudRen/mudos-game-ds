// parasite.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

int weapon_damage(string material,int weight);

void setup()
{
	::setup();
	
	if( clonep(this_object()) ) return;
	if( !query("skill_type")) set("skill_type", "parasite");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "parasite1", "parasite2", "parasite3" }) );
	}
}

varargs void init_parasite(int damage, int flag)
{
	if(!this_object()->query("material"))
		this_object()->set("material","plant");
	damage += weapon_damage(query("material"),weight());
	set("zerg_weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	if(!query("limit_str"))	set("limit_str",weight()/1500);
	if(!query("energy")) set("energy",1000);
	if(!query("wield_msg")) set("wield_msg","$N�N$n�]�J�����i��ͤƿĦX�A���A�v�����ܤF�C\n");
	if(!query("unwield_msg")) set("unwield_msg", "$N���f�F�@�U�A�N������$n�V���H�G�R�F�X�ӡA�����ܦ^��l�����A�C\n");
}


int weapon_damage(string material,int weight)
{
	return 0;

}

int is_weapon() { return 1; }
