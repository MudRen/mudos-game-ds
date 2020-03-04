#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "食人獸" , ({"anthropophagi monster","monster"}) );
  set("long",@LONG
一個渾身是血，嘴巴上還叼著一塊肉的怪物，看牠的樣子，好像
要把你吃了似的..
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",45);
  set("gender", "雄性" );
  set("attitude", "aggressive");
  set("level",20+random(5));
  set("title", "魂獸" );
  set("limbs", ({ "獅頭","身體","馬尾","前腳","後腳" }) );
  set("verbs", ({ "bite" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}
