// Room: /u/a/acme/area/tnb.c

inherit ROOM;

void create()
{
	set("short", "棺木內");
     set("light",1);
	set("long", @LONG
你身處在偌大的棺木內，此具棺木竟容得下二人的寬度，四周佈滿了
灰塵，左邊的棺材板似乎有些怪異，異常的乾淨，四周散落著給過世之人
的冥紙和一些事物。往上可跳出這個大棺材。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"h1",
]));
	set("no_clean_up", 0);
      set("item_desc", ([
"棺材板" : "你輕輕敲了棺材板，似乎裡頭是空的，說不定可以推(push)開它。\n",
"冥紙"  : "呃……這是給死人用的，難不成你要用？\n",
"事物"  : "呃……這些事物是給死人用的，難不成你要用？\n",
      ]));

	setup();
}
void init()
{
        add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "棺材板") return 0;
        message_vision(
         "$N輕輕推開了棺材板，棺材板轉了半個兒圈，西邊出現了一個出口。\n"
         ,me);
         set("exits", ([
          "west" : __DIR__"secret",
          "up" : __DIR__"h1",
]));
        return 1;
} 

