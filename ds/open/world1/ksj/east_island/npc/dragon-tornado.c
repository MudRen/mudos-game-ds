#include <ansi.h> 
#include <path.h>
inherit NPC;    

mapping *combat_action = ({
        ([  "action":       "$N捲起的巨石帶著高速狠狠撞向$n",
                "attact_type":  "bar",
                "damage_type":  "撞擊傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIG"吞天龍卷"NOR, ({"dragon tornado","tornado"}) );
  set("long","八岐大蛇邪力所形成的龍卷風暴。\n");
  set("unit","團");
  set("level",50); 
  set("orochi",1);
  set("orochi_beast_3",1);
  set("age",0);
  set("limbs", ({"核心"}) ); 
  set("verbs", ({"crash"}) );  
  set("max_hp",30000);
  add("addition_damage",50);
  add("addition_armor",300);
  add("addition_shield",300);
  set_temp("apply/hit",30);
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));
  set("chat_chance_combat", 10);
  set("chat_msg_combat", ({
     (: random_move :),
     }) );
  setup(); 
  set_living_name("_NPC_TORNADO_");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  call_out("dest_tornado", 250);
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

int special_attack(object me,object target,int hitchance)
{
  object *inv;
  int i,damage;
  inv = all_inventory(environment(me));
  if(!me || !inv) return 0;
  if( me->query_temp("delay") ) return 0;
  message_vision("\n$N"HIW"風勢逐漸增強，強風中的沙石如刀刃般割膚生痛！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(living(inv[i]) )
    {
      if(inv[i] == me) continue;
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query("orochi") ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      if(living(inv[i]) )
      {
        if( random(inv[i]->query_dex()) < 7 )
        {
          if( inv[i]->query("orochi-enemy") ) continue;
          message_vision(HIR"\n【$N"HIR"被龍卷所吞噬，身形消失在半空的烏雲中！】\n"NOR,inv[i]);
          inv[i]->start_busy(5);
          switch( random(10) )
          {
            case 0:
                 inv[i]->move(__DIR__"../room86.c");
                 break;
            case 1:
                 inv[i]->move(__DIR__"../room37.c");
                 break;
            case 2:
                 inv[i]->move(__DIR__"../room32.c");
                 break;
            case 3:
                 inv[i]->move(__DIR__"../room61.c");
                 break;
            case 4:
                 inv[i]->move(__DIR__"../room58.c");
                 break;
            case 5:
                 inv[i]->move(__DIR__"../room40.c");
                 break;
            case 6:
                 inv[i]->move(__DIR__"../room4.c");
                 break;
            case 7:
                 inv[i]->move(__DIR__"../room36.c");
                 break;
            case 8:
                 inv[i]->move(__DIR__"../room12.c");
                 break;
            case 9:
                 inv[i]->move(__DIR__"../room29.c");
                 break;
          }
          tell_room(environment(inv[i]),inv[i]->query("name")+"從空中摔了下來，吐出大量鮮血。\n",target);
          inv[i]->receive_damage("hp",inv[i]->query("hp")*19/20);
        }
        else if( !random(4) )
        {
          damage=450-(inv[i]->query_armor());
          if(damage<0) damage=0;
          message_vision("$N"HIR"被捲入暴風中，遭受無數大小沙石無情的撞擊！("+damage+")\n"NOR,inv[i]);
          inv[i]->receive_damage("hp", damage, me);
          inv[i]->start_busy(2);
        }
      }
    }
  }
  me->set_temp("delay",1);
  call_out("wait",3,me);
  return 1; 
}    

void wait(object me)
{
  me->delete_temp("delay");
}

void dest_tornado()
{
  message_vision(HIW"\n\t【吞天龍卷風勢漸漸止息，天空也露出一瞥陽光】\n\n"NOR,this_object());
  destruct(this_object());
}

void die()
{
  message_vision("\n$N的結構瓦解，消失無蹤。\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
