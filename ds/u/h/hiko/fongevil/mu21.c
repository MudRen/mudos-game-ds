inherit ROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
這裡已經有點接近山下了，可是下方岩壁極為陡峭，讓你打消
往山下一覽景物的打算，這裡的樹木極為高大，是拿來做器具的好
材料，由於接近山下動物也漸漸變少了。
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu20", 
]) );
 set("item_desc", ([
  "堅木" : "十分堅固的木材，也許\可以砍(chop)下來製作東西。\n",
]));
set("objects",([__DIR__"animal/woodpecker" : 4,]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 
 void init()
{
  add_action("do_chop","chop");
}

int do_chop(string str)
{
  object ob = this_object(), me = this_player();
  object axe;

  if(me->is_busy()) return notify_fail("你正忙著，沒空作其他事。\n");
  if(!str) return notify_fail("你要砍什麼呀?\n");
  if(str != "堅木" || !str) return notify_fail("你要砍什麼東西?\n");
  if(!axe = present("axe",me)) return notify_fail("你需要一把斧頭來砍竹子。\n");
  if(ob->query("no_chop")) return notify_fail("這裡的木材似乎已經被砍過了。\n");
  
  message_vision("$N舉起手中的斧頭，使勁的朝著堅木攔腰砍去。\n",me);
  me->start_busy(2);
  ob->set("no_chop",1);
  call_out("loop",4);
  return 1;
}

int loop()
{
  object me = this_player();
  message_vision("啪啦！堅木被你從中斷成兩截。\n",me);
  new(__DIR__"../item/wood")->move(environment(me));
  new(__DIR__"../item/wood")->move(environment(me));
  return 1;
}
void reset()
{
  delete("no_chop");
  return ::reset();
}





