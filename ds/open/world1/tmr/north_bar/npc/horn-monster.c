#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "黑角獸" , ({"horn monster","monster"}) );
  set("long",@LONG
這是一隻頭上長著兩隻黑角的不知名野獸，正惡狠狠的瞪著你。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",70);
  set("attitude", "aggressive");
  set("gender", "雄性" );
  set("level", 30+random(5));
  set("title", "魂獸" );
  set("limbs", ({ "頭部", "身體","尾巴","腹部","背部" }) );
  set("verbs", ({"bite","claw"}) );
        set("chat_chance",10);
        set("chat_msg",({
        (: random_move() :),
        }) );
  setup();
}