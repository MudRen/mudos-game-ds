inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("小江", ({ "jang sha","jang","sha" }) );
  set("gender", "男性" );
  set("age", 22);
  set("long","一個專門賣特產的店員。\n");
  set("level",1);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
"小江大聲吆喝著: 本店的特產是最有名的，各位來看看呀。\n",
"小江努力的打掃店面，露出認真的酷樣。\n",
}) );

  set("sell_list",([
__DIR__"item/fresh-soup" : 5,
__DIR__"item/red-laver" : 5,
__DIR__"item/sea-rice" : 5,
__DIR__"item/tedder-fish" : 5,
]));
set("no_kill",1);
set("no_cast",1);
set("no_fight",1);
  setup();
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}


