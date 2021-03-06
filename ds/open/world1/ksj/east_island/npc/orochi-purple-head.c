#include <ansi.h>
inherit NPC;
void normal_ai();
void do_combat_attack();

mapping *combat_action = ({
        ([  "action":       "$N朝$n噴出一團濃濃的紫霧",
                "attact_type":  "bio",
                "damage_type":  "腐蝕",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"八岐大蛇"RED"．"MAG"紫首"NOR,({"orochi purple head","purple head","head","_PURPLE_HEAD_"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的八個頭之一，散發毒氣的紫色蛇首。
LONG
);
  set("race", "野獸");    
  set("unit","隻");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "額鱗","咽喉","眼睛","頭頂"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",10);
  set("Merits/bio",14);
  set("Merits/wit",7);
  set("Merits/tec",3);
  set("Merits/sou",6);
  add("addition_damage",30);
  add("addition_armor",150);
  add("addition_shield",200);
  set_temp("apply/hit",20);
  set("chat_chance", 40);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  set("chat_chance_combat",40);
  set("chat_msg_combat", ({
     (:do_combat_attack():),
     }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_PURPLE_HEAD_");
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

void do_combat_attack()
{
 object *inv,me;
 int i;
  me=this_object();
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  message_vision("\n【$N"MAG"散發出毒氣飄向四周！】\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      message_vision("$N"HIR"吸入毒氣後臉色一黑。\n"NOR,inv[i]);
      inv[i]->apply_condition("poison", inv[i]->query_condition("poison")+10);
    }
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int i,dur,damage;
  object *inv,weapon;
  inv = all_inventory(environment(me));
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;
  if( !me->query_temp("weapon") )

  if(!random(4))
  {
    me->start_busy(1);
    damage = random(150)+300-(target->query_shield())-(target->query_armor()/2);
    if(damage < 0) damage=0;
    message_vision("\n$N"HIW"突然朝$n吐出【"MAG"蝕骨強酸"HIW"】！！\n"
                  +HIR"造成("+damage+")點的腐蝕\n"NOR,me,target);
    target->receive_damage("hp", damage, me);
    target->add_busy(1);
    if( me->query_temp("weapon") )
    {
      weapon=target->query_temp("weapon");      
      dur=weapon->query_durable();
      tell_object(target,HIW"強酸沾到你所拿的"+weapon->query("name")+"造成一些毀損。\n"NOR);
      weapon->set_durable(dur-random(18));
    }
    return 1;
  }
  else if(!random(4))
  {
    me->start_busy(1);
    message_vision("\n$N"HIW"突然朝空中噴出大量【"MAG"蝕骨強酸"HIW"】！！\n\n"NOR,me);
    for(i=0;i<sizeof(inv);i++)
    {
      if(inv[i] == me) continue;
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query("orochi") ) continue;
      if(living(inv[i]) )
      {
        if( random(inv[i]->query_dex()) < 20 )
        {
          message_vision("$N"HIR"閃躲不及，被酸液沾中了身體！\n"NOR,inv[i]);
          new(__DIR__"eq/orochi-acid")->move(inv[i]);
        }
      }
    }
    return 1;
  }
  return 0;
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
    new(__DIR__"obj/obj/purple-head")->move(this_object());
new(__DIR__"eq/orochi-cloak")->move(this_object());
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);

  message("world:world1:vision",
	HIC"\n\t【東方島】："+HIR" 出雲山頂傳來震耳欲聾的慘嚎，"HIY+ob->name(1)
  	 +HIR"斬下了"+name()+HIR"的首級了。\n\n"NOR,users());
  

	if(random(1000)==978)
          new(__DIR__"eq/orochi-cloak-save")->move(this_object());
  ::die();
  return;
}
