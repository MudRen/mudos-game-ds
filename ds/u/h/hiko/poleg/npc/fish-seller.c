inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("魚販", ({ "fish seller","fish","seller" }) );
  set("gender", "男性" );
  set("age", 37);
  set("long","一個販賣漁獲的人，在他這可以買到許\多新鮮海產。\n");
  set("level",1);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
"魚販大聲喊著: 本店的漁獲是最新鮮的，蒸炒煮燉樣樣宜呀。\n",
"魚販細心的處理著魚肉，把不合適的地方都去掉。\n",
}) );

  set("sell_list",([
__DIR__"item/flyfish-meat" : 5,
__DIR__"item/grig-meat" : 5,
__DIR__"item/shark-meat" : 5,
__DIR__"item/sifu-meat" : 5,
__DIR__"item/liuye-meat" : 5,
__DIR__"item/sandling-meat" : 5,
__DIR__"item/yue-meat" : 5,
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




