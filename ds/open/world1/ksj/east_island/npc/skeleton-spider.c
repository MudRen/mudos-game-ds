#include <ansi.h>
inherit NPC;

void create()
{
        set_name("骷髏\蜘蛛",({"skeleton spider","spider"}) );
        set("long",@LONG
一隻巨大的黑色蜘蛛，體形有木板車那麼大，可怕的是牠的腹部竟然
是由帶有些餘血肉的骷髏頭所組成。由於怨靈無法超渡升天而附身在
蜘蛛上，才形成這種怪物。
LONG
);
        set("race", "野獸");    
        set("unit","隻");
        set("age",94);
        set("attitude", "aggressive");
        set("level",27+random(4));
        set("limbs", ({ "頭胸部","複眼","腹部","足部"}) ); 
        set("verbs", ({ "bite","claw" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "骷髏\蜘蛛腹部的骷髏\頭漸漸滴下屍水，使得空氣中充滿腐臭。\n",
        }));                                
        setup();
        add_money("coin",500);
}

int special_attack(object me, object target, int hitchance)
 {
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7) )
  {
    message_vision("\n$N張嘴吐出一團蜘蛛絲，纏住了$n的手腳，$n一時間無法動彈。\n\n", me, target);
    target->add_busy(3);
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
        switch( random(100) ) {
        case  0..4: new(__DIR__"eq/bogle-bead")->move(this_object());
        break;
        case  5..9: new(__DIR__"eq/hands-design-page")->move(this_object());
        break;}
        ::die();
        return;
 }
