// bow.c

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
	set("skill_type", "bow");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "clush", "hit" }) );
	}
}

varargs void init_bow(int damage, int flag)
{
	if(!this_object()->query("material"))
		this_object()->set("material","plant");
	damage += weapon_damage(query("material"),weight());
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | TWO_HANDED);
	if(!query("limit_str"))	set("limit_str",weight()/1500);
}

int weapon_damage(string material,int weight)
{
	return 0;

}

int do_shoot(object me,object target)
{
	  object arrow;
	  int damage;
	
	  if(!me || !target) return 0;
	  if( !arrow=present("arrow", me ) ) return notify_fail(" 你沒有箭, 不能射擊。\n");
	  if(arrow->shoot_attack(me,target)) return 1;	//弓箭可以另外設計攻擊敘述和動作
	  if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(HIW"$N"HIW"舉起"+this_object()->name()+HIW"對準$n"HIW"的方向射出一支"+arrow->name()+HIW"﹗\n"NOR,me,target);
	  me->start_busy(2);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  //check if target can dodge
	  if(random(COMBAT_D->attack_factor(me,"bow")+me->query_skill("bow")*2) < random(-COMBAT_D->dodge_factor(target,"dodge")) )
	  {
	   message_vision("$N側身迴避, 毫髮無傷的避開了$n的"+arrow->name()+"。\n"+NOR,target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   me->improve_skill("bow",random(1+me->query_int()/8));
	   destruct(arrow);
	   return 1;
	  }
	  damage=arrow->query("arrow/damage")+this_object()->query("weapon_prop/damage");
	  damage+=random(me->query_str());
	  damage= damage/2+random(damage);
	  damage-=target->query_armor();
	  if(damage<5) damage=random(10);
	  if(damage<1)
	  {
	    message_vision(HIW+"$N"+HIW+"輕輕一撥, 輕鬆的把"+arrow->name()+HIW+"給格開了。\n"+NOR,target);
	    destruct(arrow);
	    return 1;
	  }
	  message_vision("$N楞了一楞, 想閃避時卻已經被箭"HIW"射中"NOR","HIR" 血流不止"NOR"。\n",target,me);
	  target->receive_damage("hp",damage,me);
	  me->improve_skill("bow",1+random(me->query_int()/6));
	  if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
	  COMBAT_D->report_status(target);
	  arrow->hit(target,me);
	  destruct(arrow);
	  return 1;
}

void attack(object me,object victim)
{
  int index, durable;
  string material;


  if( !stringp(material = this_object()->query("material")) )
  {
    error("ITEM : material 資料型態錯誤.\n");
    return;
  }

  switch(material)
  {
    case "gold"   : index = 3;
                    break;
    case "silver" : index = 4;
                    break;
    case "iron"   : index = 5;
                    break;
    case "gem"    : index = 6;
                    break;
    case "stone"  : index = 7;
                    break;
    case "wood"   : index = 8;
                    break;
    default       : index = 9;
                    break;

  }

  if( !intp(durable = this_object()->query_temp("durable_index")) )
  {
    this_object()->set_temp("durable_index",0);
    return;
  }
  this_object()->add_temp("durable_index", index);

  if(durable > 100)
  {
    this_object()->set_temp("durable_index",0);
    set_durable(this_object()->query_durable() - 1);
  }
}

int is_weapon() { return 1; }
