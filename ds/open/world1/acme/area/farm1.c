inherit ROOM;

void create()
{
        set("short", "農田");
        set("long", @LONG
你正走在田間小路，環顧四方，盡是正正方方的農地，田中央還插著
一個稻草人，阡陌之間竟生長著奇異的花朵，白裡透藍，十分顯眼。在你
的東邊可看見一間小茅屋。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farm",
  "west" : __DIR__"farm2",
  "east" : __DIR__"cottage",
// 有bug "southeast" : __DIR__"gosenwu",
  "southeast" : __DIR__"pass10",
]));
       set("objects",([
          __DIR__"npc/sparrow" : 4,
       ]));
     set("item_desc", ([
            "花朵" : "這朵花叫「龍鬚碧藍花」，或許\你可能摘(pick)下它。\n",
     ]) );      
      set("no_clean_up", 0);
      set("outdoors","land");
      setup();
}
void init()
{
   add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object herb;
        object me;
        me=this_player();
        if(query_temp("herb3")) return notify_fail("什麼？\n");
        if(arg != "龍鬚碧藍花")
        {
            notify_fail("你要摘下什麼？\n");
            return 0;
        }
        else {
        message_vision("$N小心翼翼的將龍鬚碧藍花摘了下了。\n",me);
        herb=new(__DIR__"obj/herb3.c");
        herb->move(me);
        set("item_desc", ([
            "雜草" : "這雜草快枯\死了，應沒什麼用處。\n",
        ]) );      
        set("long", @LONG
你正走在田間小路，環顧四方，盡是正正方方的農地，田中央還插著
一個稻草人，阡陌之間生長著許多雜草。在你的東邊可看見一間小茅屋。
LONG
        );
        set_temp("herb3",1);
        call_out("delay",600,this_object());
        return 1;
             }
}
void delay(object room)
{
     delete_temp("herb3");
     set("item_desc", ([
            "花朵" : "這朵花叫「龍鬚碧藍花」，或許\你可能摘(pick)下它。\n",
     ]) );      
}
