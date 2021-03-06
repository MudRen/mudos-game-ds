#include <ansi.h>
inherit NPC;

void create()
{
  set_name("烏鴉天狗", ({"karasu tengu","tengu"}) );
  set("long",@LONG
天狗的手下，有著像烏鴉般的嘴巴，穿著衣服手拿武器，也有雙翅膀
，經常會襲擊人類。
LONG
);
  set("race", "人類");
  set("unit","隻");
  set("age",40);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",35+random(6));
  set_skill("fork",40+random(15));
  set_skill("dodge",40+random(10));
  set_skill("parry",30+random(10));
  add("addition_armor",30+random(10));
  set("tengu",1);
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  carry_object(__DIR__"eq/fork")->wield();
  carry_object(__DIR__"eq/tengu-cloth")->wear();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
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

  switch( random(100) )
  {
    case  0..4: new(__DIR__"eq/iron-cut-dagger")->move(this_object());
          break;
  }
  ::die();
  return;
}
