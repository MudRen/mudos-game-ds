inherit ROOM;

void create()
{
        set("short", "木橋");
        set("long", @LONG
你身處在一座木橋之上，此木橋是用上好的杉木建造而成，從木橋往
下望去，是一條不甚寬的小溪流，若失足跌落應不會有生命危險。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wewd1",
  "northwest" : __DIR__"wewd",
]));
  set("item_desc", ([ /* sizeof() == 1 */
   "小溪" : "這小溪不是很深，或許\能往下跳(jump down)。\n",
  ]));
        set("no_clean_up", 0);
     set("outdoors","land");

        setup();
}
void init()
{ 
         add_action("do_jump","jump");
}
int do_jump(string arg)
{
          object me;
          me=this_player();
          if(arg != "down")
            return 0;
          else {
            message_vision("$N往小溪裡跳了下去。\n",me);
            me->move(__DIR__"l4");
            return 1;
          }
}
