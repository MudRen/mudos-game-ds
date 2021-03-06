#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name(HIW"武士怨靈"NOR,({"orochi ghost","ghost"}) );
  set("long",@LONG
被八岐大蛇吞噬囚禁的武士鬼魂，受到邪力影響而成為嗜殺的厲鬼。
LONG);
  set("race", "human");    
  set("unit","隻");
  set("attitude", "killer");
  set("level",30+random(20));
  add("addition_armor",50+random(50));
  add("addition_damage",50+random(50));
  set("orochi",1);
  set("orochi_beast_3",1);
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  call_out("dest_ghost", 250);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return; 
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(15))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void dest_ghost()
{
  message_vision("\n$N化為輕煙消失無蹤了。\n",this_object());
  destruct(this_object());
}

void die()
{
  message_vision("\n$N化為輕煙消失無蹤了。\n",this_object());
  destruct(this_object());
//    ::die();
  return;
}
