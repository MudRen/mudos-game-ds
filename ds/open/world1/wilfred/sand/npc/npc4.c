inherit NPC;

void create()
{
  set_name("青蛙", ({"frog"}) );
  set("long",@LONG
一般在靠近水邊都會見到的動物，身為綠色，下肢發達，可跳得相當遠。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1);
  set("level",2);
  set("con",1);
  set("limbs", ({ "頭部", "腹部","胸部" }) );
  set("verbs", ({ "bite" }) );
  setup();
  add_money("coin",20);
}

