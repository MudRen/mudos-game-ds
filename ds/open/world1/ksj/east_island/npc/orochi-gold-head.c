#include <ansi.h>
inherit NPC;
void normal_ai();

mapping *combat_action = ({
        ([  "action":       "$N從金色的雙眼中發出一道光芒，射向$n的$l",
                "attact_type":  "wit",
                "damage_type":  "燒傷",
        ]),
        ([  "action":       "$N發中嘶嘶叫聲，從金色的雙眼中激射出光芒，直接取向$n的$l",
                "attact_type":  "wit",
                "damage_type":  "燒傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"八岐大蛇"RED"．"HIY"金首"NOR,({"orochi gold head","gold head","head","_GOLD_HEAD_"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的八個頭之一，眼發金光的金色蛇首。
LONG
);
        set("race","beast");
    set("attack_merits","wit");
  set("unit","隻");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "額鱗","咽喉","眼睛","頭頂"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",9);
  set("Merits/bio",7);
  set("Merits/wit",14);
  set("Merits/tec",8);
  set("Merits/sou",7);
  add("addition_damage",90);
  add("addition_armor",250);
  add("addition_shield",200);
  set_temp("apply/hit",40);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_GOLD_HEAD_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

void normal_ai()
{
  object me,target;
  me = this_object();
  target = this_player();
  if(me->is_busy()) return;
  if( me->query("hp") + 1000 < me->query("max_hp") )
  {
    message_vision("\n$N"HIG"兩眼微閉，靠在岩壁旁休息！\n\n"NOR,me);
    me->receive_heal("hp",1000);
    me->start_busy(1);
  }
  switch( random(30) )
  {
    case  0: message_vision("$N一雙巨大的蛇眼直盯著你瞧．．．\n",me);
          break;
    case  1: message_vision("$N吐出一道如雷響的氣息。\n",me);
          break;
    case  2: message_vision("$N一雙巨大的眼睛掃視四周，尋找獵物。\n",me);
          break;
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N"HIW"動作稍緩，從巨大的金色蛇眼綻射出強烈的【"HIY"八岐邪光"HIW"】！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIY"\n巨大強烈的金色光柱，向四周掃射！！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query("orochi") ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(300)+300-(inv[i]->query_shield());
      if(damage <0) damage=0;
      message_vision(HIR"$N被光柱擊中的部位瞬間著火焦爛.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIR"\n$N在一瞬間燒成灰燼 .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(2);
  return;
}

void die()
{
    object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",10);      
    new(__DIR__"obj/obj/gold-head")->move(this_object());
new(__DIR__"eq/kusanagi-sword")->move(this_object());
new(__DIR__"eq/orochi-armor2")->move(this_object());
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);

  message("world:world1:vision",
  HIC"\n\t【東方島】："+HIR" 出雲山頂傳來震耳欲聾的慘嚎，"HIY+ob->name(1)
  	 +HIR"斬下了"+name()+HIR"的首級了。\n\n"NOR,users());
  
	if(random(1000)==978)
		new(__DIR__"eq/orochi-armor2-save")->move(this_object());
	
  ::die();
  return;
}
