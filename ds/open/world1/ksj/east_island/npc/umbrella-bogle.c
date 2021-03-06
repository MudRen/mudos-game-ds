#include <ansi.h>
inherit NPC;

void create()
{
  set_name("雨傘妖怪",({"umbrella bogle","bogle"}) );
  set("long",@LONG
外形像一把紙傘的妖怪，傘面上有一顆大大的眼睛跟長長的舌頭，握
把的部份是一隻右腳，一蹦一蹦地四處跳動。
LONG
);
  set("race", "野獸");    
  set("unit","隻");
  set("age",68);
  set("attitude", "aggressive");
  set("level",28+random(4));
  set("limbs", ({ "傘面", "眼睛","舌頭","右腳"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 10);
  set("chat_msg", ({
      "雨傘妖怪一邊甩著舌頭，一邊用右腳跳來跳去。\n",
     }));                                
  setup();
  add_money("coin",500);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") < 26 && userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4) && (target->query_int() < 50) )
  {
    message_vision("\n$N旋轉傘面的螺旋花紋，$n漸漸地覺得頭暈目眩$n，天旋地轉。\n\n", me, target);
    target->add_busy(2);
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
  switch( random(200) )
  {
    case  0: 
          new(__DIR__"eq/hundred-bogle-necklace")->move(this_object());
          break;
    case  1..30: 
          new(__DIR__"eq/bogle-bead")->move(this_object());
          break;
  }
  ::die();
  return;
}
