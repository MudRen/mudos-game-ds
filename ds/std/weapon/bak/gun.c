// gun.c

#include <weapon.h>
#include <ansi.h>
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
	set("skill_type", "gun");
	set("can_shoot",1);
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush" }) );
	}
}

varargs void init_gun(int damage, int flag)
{
	if(!this_object()->query("material"))
		this_object()->set("material","plant");
	damage += weapon_damage(query("material"),weight());
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED );
	if(!query("limit_str"))	set("limit_str",weight()/1500);
	if(!query("max_load")) set("max_load",2);
}

int weapon_damage(string material,int weight)
{
	return 0;

}

int do_shoot(object me,object target)
{
	string msg;
	int damage;
	
	  if(!me || !target) return 0;
	  this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
	  msg=HIW+"$N"+HIW+"�Ψ��p���α��ժ��t��, ��M��"+this_object()->name()+HIW+"���$n"+HIW+"�g�X�F�@";
	  if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
		else msg+="�o";
	  if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"�T\n"+NOR;
		else msg+="�l�u�T\n"+NOR;
	   if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(msg,me,target);
	  me->start_busy(1);
	  me->improve_skill(this_object()->query("skill_type"),1+random(me->query_int()/6));
	  //check if target can dodge
	  if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 200 )
	  {
	   message_vision("$N���t��������½�F��ӭo��, �}�G���{�L�F$n���g���C\n"+NOR,target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	
	  damage=this_object()->query_temp("bullet/damage")+this_object()->query("weapon_prop/damage");
	  damage= damage*2/3+random(damage/2);
	  damage-=target->query_armor()/3-random(target->query_armor()/2);
	  if(damage<5) damage=random(10);
	  if(damage<1)
	  {
	   message_vision(HIW+"$N"+HIW+"��"+this_object()->query_temp("bullet/name")+HIW+"���u�}�F�C\n"+NOR,target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	  message_vision("$N���F�@��, ���Q�{�׮ɫo�w�g�Q"HIW"�g��"NOR", "HIR"���ˤ���"NOR"�C\n",target,me);
	  target->receive_damage("hp",damage,me);
	  if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
	  COMBAT_D->report_status(target);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  return 1;

}

int is_weapon() { return 1; }
