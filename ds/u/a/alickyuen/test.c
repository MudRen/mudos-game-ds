  // Room: /u/t/tmr/room/square.c

  inherit ROOM;

  void create()
  {
          set("short", "測試廣場");
          set("long", @LONG
  這是一個奇(Tmr)用來做測試的廣場。
LONG
          );
          set("exits", ([ /* sizeof() == 3 */
            "out" : "/u/t/tmr/workroom",
          ]));
          set("no_clean_up", 0);
          setup();
  }

  void init()
  {
          add_action("do_test","test");
  }

  int do_test(string arg)
  {
            object room,env,me;
          mapping exit;

	me=this_player();
          if(!arg ) return notify_fail("請選擇你要測試的方向。\n");


          env = environment(me);
          if(!env) return notify_fail("你哪裡也去不了。\n");
          exit = env->query("exits");

          if(!mapp(exit))
                  return notify_fail("這個房間沒有可供測試的出口。\n");

          if( undefinedp(exit[arg]) )
                  return notify_fail("沒有這個方向可供測試。\n");
          if( !(room = find_object(exit[arg])) ) call_other(exit[arg], "???");
          if( !(room = find_object(exit[arg])) ) 
                  return notify_fail("無法移動。\n");

	tell_object(me,"\n"+exit[arg]+"的短敘述(short)：\n\n"+
                  room->query("short")+"\n" );

          return 1;       
  }

