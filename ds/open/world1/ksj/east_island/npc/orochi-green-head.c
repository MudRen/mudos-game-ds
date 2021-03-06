#include <ansi2.h>
inherit NPC;
void normal_ai();

mapping *combat_action = ({
        ([  "action":       "$N噴出一道如刀的氣流，夾帶破空風聲砍向$n",
                "attact_type":  "tec",
                "damage_type":  "斬傷",
        ]),
        ([  "action":       "$N召來一陣冰雹，再以強烈氣流將無數銳利冰塊擊向$n",
                "attact_type":  "tec",
                "damage_type":  "撞擊傷",
        ]),
        ([  "action":       "$N噴出一團壓縮空氣，如無形的砲彈般擊向$n",
                "attact_type":  "bio",
                "damage_type":  "內傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"八岐大蛇"RED"．"HIG"綠首"NOR,({"orochi green head","green head","head","_GREEN_HEAD_"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的八個頭之一，呼風喚雨的綠色蛇首。
LONG
);
    set("attack_merits","tec");
        set("race","beast");
  set("unit","隻");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "額鱗","咽喉","眼睛","頭頂"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("str",160);
  set("con",143);
  set("int",60);
  set("dex",90);
  set("Merits/bar",9);
  set("Merits/bio",12);
  set("Merits/wit",4);
  set("Merits/tec",13);
  set("Merits/sou",4);
  add("addition_damage",70);
  add("addition_armor",220);
  add("addition_shield",50);
  set_temp("apply/hit",40);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_GREEN_HEAD_");
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
  object ob;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  ob=find_living("_NPC_TORNADO_");
  if( objectp(ob) )
  {
    if(!environment(ob) )
    {
      destruct(ob);
    }
  }
  else
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"昂首向天，在蛇首周圍逐漸形成一股"HIG"旋風"HIW"！\n"NOR,me);
    new(__DIR__"mini-tornado")->move(environment(me));
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
    new(__DIR__"obj/obj/green-head")->move(this_object());
new(__DIR__"eq/orochi-leggings")->move(this_object());
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);

  message("world:world1:vision",
  	HIC"\n\t【東方島】："+HIR" 出雲山頂傳來震耳欲聾的慘嚎，"HIY+ob->name(1)
  	 +HIR"斬下了"+name()+HIR"的首級了。\n\n"NOR,users());
  
	if(random(1000)==978)
		new(__DIR__"eq/orochi-leggings-save")->move(this_object());
  ::die();
  return;
}
