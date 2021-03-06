inherit ROOM;
int reborn = 1;
void create()
{
  set ("short", "山崗上");
  set ("long", @LONG
好不容易爬上這山，你從山上往下望，才發現這是由一堆堆大小
不等的石頭所堆起的山丘，令人納悶的是，顯然這是由人工堆成的，
但又有誰有這等能耐，在如此荒僻之地堆了這座山丘？從這裡可以看
到原來黃沙鎮在山的東邊直行十里處。
LONG
);

  set("exits", ([
  "east" : __DIR__"room32",
  "westdown" : __DIR__"room30",
]));
  set("item_desc", ([
  "石頭" : "一堆堆大小不等的石頭，其中有些外形酷似武器，也許\可以找找(search)有無合用的。\n",
]));
  set("outdoors", "land");
  setup();
}

void init()
{
  add_action("do_search","search");
}

int do_search(string str)
{
  object me = this_player();
  if(str == "石頭")
  {
    if(reborn)
    {
      message_vision("$N在亂石堆中翻翻找找.....\n",me);
      message_vision("突然發現其中一塊石頭外形似爪，也許\可以作為武器。\n",me);
      message_vision("\n$N發現一隻石爪。\n",this_player());
      new(__DIR__"npc/wp/wp2")->move(environment(me));
      reborn = 0;
    }
    else message_vision("$N在亂石堆中找了又找，結果沒發現什麼可用的東西。\n",me);
  }
  else return 0;
  return 1;
}
