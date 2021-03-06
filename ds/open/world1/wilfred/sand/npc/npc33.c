inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("店小二", ({ "waiter" }) );
  set("gender", "男性" );
  set("age", 22);
  set("long","一個跑堂的店小二。\n");
  set("level",1);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
"店小二拿起了抹布，擦了擦臉上的冷汗。\n",
"店小二突然想起這抹布剛才擦過地板，不禁流了一滴冷汗。\n",
}) );

  set("sell_list",([
__DIR__"obj/obj12" : 5,
__DIR__"obj/obj13" : 5,
__DIR__"obj/obj14" : 5,
]));
set("no_kill",1);
set("no_cast",1);
set("no_fight",1);
  setup();
  carry_object(__DIR__"obj/obj26");
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}
