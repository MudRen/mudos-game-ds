#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "食肉獸" , ({"predator monster","monster"}) );
  set("long",@LONG
這是一隻長著豬頭、牛身及鼠尾的食肉獸，兩個犬牙異常的發達，
似乎很輕鬆就可以把你撕成兩半。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",45);
  set("gender", "雄性" );
  set("attitude", "aggressive");
  set("level", 25 + random(5));
  set("title", "魂獸" );
  set("limbs", ({ "豬頭","牛身","鼠尾","前腳","後腳" }) );
  set("verbs", ({ "bite" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}
