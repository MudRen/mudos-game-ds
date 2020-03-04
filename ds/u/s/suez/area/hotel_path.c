// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "長廊");
	set("long",@LONG 
典雅的長廊，山木的地板散發出沉穩的氣息，精妙的設計讓沒有窗戶
的此地仍然清新明亮，聽著走在地板上的腳步聲，似乎地板還是特別架空
，或許這樣就不會有山裡的濕氣破壞這美麗的地板。再往東就是通往樓上
客房的階梯，以及客棧的後門了。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "eastup" : __DIR__"hotel_step",
               "east": __DIR__"hotel_back",
            "west": __DIR__"hotel_hall",

              ]));

        set("objects",([
              __DIR__"npc/drooler_man" : 1,
              ]) );

	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
     
      if(me->query("class1")!="摘星門") return notify_fail("你在地板上東摸摸西摸摸，別人還以為你是在擦地板呢！\n");

        if (arg != "地板"  )
                return 0;
              else 
        {
            message_vision("$N按了按地板，突然地板旋轉起來，$N竟掉入地板之下！\n",me);
        me->move(__DIR__"base_1");
      tell_room(environment(me),me->query("name")+"由密道機關中跳了下來。\n",me);
        return 1;
        }
}
