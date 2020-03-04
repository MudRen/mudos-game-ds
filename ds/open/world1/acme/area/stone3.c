inherit ROOM;
void create()
{
        set("short", "石崖上");
        set("long", @LONG
這裡是「流波潼」底不為人知的石崖上，這裡的石壁長滿了青苔
所以相當的滑，在旁邊長了一些十分特別的植物，此地的環境相當的
特殊才會生長這種特別的植物吧！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
]));
       set("objects",([
          __DIR__"npc/bonze" : 1,
       ]) );
     set("item_desc", ([
"植物" : "你仔細的瞧了瞧這株植物，發覺有些果實，這此果實俗稱『清心石綠果』，你可以摘(pick)下它。\n",
  "石崖" : "這是一個相當陡峭的石崖，要爬(climb)下去得小心一點。\n",
     ]) );
        setup();
}
void init()
{ 
         add_action("do_climb","climb");
         add_action("do_pick","pick");
}
int do_climb(string arg)
{
          object me;
          me=this_player();
          if(arg != "石崖")
            return notify_fail("你要攀爬什麼？\n");
          else {
            message_vision("$N小心異異的爬下石崖。\n",me);
            me->move(__DIR__"way6");
            return 1;
          }
}
int do_pick(string arg)
{
          object me;
           object pill;
          me = this_player();
          if(arg != "清心石綠果")
            return notify_fail("你要摘下什麼東西？\n");

            if( query_temp("pick") )
                return notify_fail("你發覺剩下的果實都是不成熟的，所以還是不要摘好了。\n");
            message_vision("$N小心翼翼的摘下了一顆果實。\n",me);
            pill=new(__DIR__"obj/herb4");
            pill->move(me);
            set_temp("pick", 1);
            call_out("delay",600,this_object());
            return 1;
}
void delay(object room)
{
     delete_temp("pick");
     return;
}

