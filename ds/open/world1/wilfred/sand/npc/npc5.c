inherit NPC;

void create()
{
  set_name("蝴蝶", ({"butterfly"}) );
  set("long",@LONG
美麗的蝴蝶，身上有著花花綠綠的色彩。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1);
	set("level",9);
  set("con",1);
  set("limbs", ({ "頭部", "腹部","胸部" }) );
  set("verbs", ({ "bite" }) );
  setup();
  add_money("coin",10);
}
