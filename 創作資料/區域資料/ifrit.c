#include <ansi.h>
#include <combat.h>
inherit NPC;

// 沒裝武器時的普攻
void do_combat_attack();
mapping *combat_action = ({
  ([  "action":       "$N揮動帶著熊熊烈燄的右手，以雷霆萬鈞之勢擊向$n",
      "attact_type":  "bio",
      "damage_type":  "內傷",
  ]),
  ([  "action":       "$N張開帶著熊熊烈燄的左手，如同大網一般罩向$n",
      "attact_type":  "bio",
      "damage_type":  "內傷",
  ]),
  ([  "action":       "$N踏著焦土裂地的步伐，宛如燃燒的小火山直直撞向$n",
      "attact_type":  "bio",
      "damage_type":  "內傷",
  ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void heal();
void create()
{
  set_name(HIR"伊佛利特"NOR, ({"ifrit","_IFRIT_"}) );
  set("long",@LONG
潛藏在地底深處的魔神，尤其常出現在活火山的地底熔岩處，沒人知
道是伊佛利特造成火山熔岩，還是火山熔岩吸引伊佛利特出現，它的
身高約四十呎，由於全身都被極高熱的火燄包圍，只能看到巨大的人
形及黝黑的雙翼。
LONG
);
  set("gender", "雄性");  
  set("race", "beast");
  set("unit","隻");
  set("age",3260);
  set("level",80);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",RED"炎魔神"NOR); 
  set("limbs", ({ "頭部","腹部","胸部","尾巴","右手","左手","雙翼","右腳","左腳"}) );
  set("verbs", ({ "bite","crash","claw" }) );
  set("Merits/bar",14);
  set("Merits/bio",14);
  set("Merits/wit",11);
  set("Merits/sou",8);
  set("Merits/tec",11);
  add("addition_damage",100);
  add("addition_armor",230);
  add("addition_shield",100);
  set_temp("apply/hit",30);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: heal :),
     }));
  set("chat_chance_combat",30);
  set("chat_msg_combat", ({
     (:do_combat_attack():),
     }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_IFRIT_");
}

// auto kill 及對上次攻擊的敵人提前防備
void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(已有防備)"NOR"$N將一團熊熊火燄揮向$n面前，$n一時慌了手腳！！\n"NOR,this_object(),this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

// 沒有戰鬥時恢復hp
void heal()
{
  if( query("hp")+500 < query("max_hp") )
  {
    message_vision(HIR"$N腳下的熔岩漸漸聚集到$N的身上。\n"NOR,this_object());
    add("hp",300+random(300));
    return;
  }
  return;
}

//戰鬥時使同一格玩家燒傷
void do_combat_attack()
{
  object *inv,me,z;
  int i,damage;
  me=this_object();
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  if( !me->query_temp("weapon") && objectp(z=present("flame sword",me)) )
    command("wield sword");
  message_vision("\n$N"HIR"身上的火舌爆發，朝四周漫燒！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(50)+150-( inv[i]->query_shield() );
      if( damage > 0 )
      {
        message_vision(HIR"$N被高溫火燄燒個正著。\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        // 燒傷(burn)寫好時,將 blooding 換成 burn
        inv[i]->apply_condition("blooding", inv[i]->query_condition("blooding")+1);
      }
    }
  }
  return;
}

// 戰鬥時的特攻
int special_attack(object me, object target, int hitchance)
{
  object z;
  int ball,j;
  ball=random(4)+1; // 製造 1~4 顆烈燄彈
  if(!me) return 0;
  if( !me->query_temp("weapon") && objectp(z=present("flame sword",me)) )
    command("wield sword");
  if(me->is_busy()) return 0;

  if( !me->query_temp("weapon") ) //沒武器時製造炎之劍
  {
    me->start_busy(2);
    message_vision("\n$N右手凝聚"HIR"熔炎烈燄"NOR"，形成一把亮紅的"HIR"炎之劍"NOR"！\n"NOR,me);
    new(__DIR__"eq/flame-sword")->move(me);
    return 1;
  }
  else if(!random(5)) //使用火燄鞭攻擊所有生物
  {
    me->start_busy(2);
    message_vision("\n$N左手凝聚"HIR"熔炎烈燄"NOR"，形成一條約十碼長的"HIR"火燄鞭"NOR"！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(5)) //製造烈燄彈
  {
    me->start_busy(2);
    message_vision(HIR"\n$N狂吼一聲，張口吐出"+ball+"顆烈燄彈！\n"NOR,me);
    for(j=0;j<ball;j++)
    {
      new(__DIR__"fire-ball")->move(environment(me));
    }
    return 1;
  }
  return 0;
}

// 特攻--火燄鞭
void do_super(object me)
{
  object *inv;
  int i,damage,dex_r,block_r,parry_r;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision("\n$N"HIR"揮動手中的火燄鞭向四周狂掃！！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(200)+550-(inv[i]->query_shield())-(inv[i]->query_armor());
      if(damage < 0) damage=0;
      dex_r=random(inv[i]->query_dex());
      parry_r=random(inv[i]->query_skill("parry"));
      block_r=random(inv[i]->query_skill("block"));
      if( parry_r > 80 && inv[i]->query_temp("weapon") )
      {
        message_vision(HIG"$N用手中的武器將火燄鞭往旁邊一帶，險些被火燄燒到。"NOR,inv[i]);
      }
      else if( block_r > 80 && inv[i]->query_temp("armor/shield"))
      {
        message_vision(HIG"$N及時以盾牌硬是擋住火燄鞭的攻擊，火燄鞭與盾牌撞擊激出火星四濺。"NOR,inv[i]);
      }
      else if( dex_r > 50 )
      {
        message_vision(HIR"$N被火燄鞭稍微掃到，造成 ("+damage/2+") 點的鞭傷！"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage/2, me);
        COMBAT_D->report_status(inv[i]);
      }
      else
      {
        message_vision(HIR"$N被火燄鞭正面擊中，造成 ("+damage+") 點的鞭傷！"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        COMBAT_D->report_status(inv[i]);
      }
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

int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
    HIR"\n\t【火山礦坑】"HIW"傳來驚人消息："+RED"炎魔神  "HIR"伊佛利特"HIW"  竟被 "HIY""+ob->name(1)+HIW" 擊退了！\n\n"+NOR
    ,users());
  ob->add("popularity",10);      
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);
  ::die();
  return;
}