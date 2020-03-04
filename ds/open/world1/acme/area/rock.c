// Room: /u/a/acme/area/rock.c

inherit ROOM;

void create()
{
	set("short", "大石上");
     set("light",1);
	set("long", @LONG
這裡是瀑布上的大石，水流往你身上沖去，你搖來晃去，便將掉了下
去，四周霧茫茫的看不清，隱約看見瀑布後有片石壁。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"pool",
]));
     set("objects",([
          __DIR__"npc/oldman" : 1,
       ]));
	set("no_clean_up", 0);
     set("item_desc", ([
"石壁" : "這是瀑布後方的石壁，上面長滿了青苔，石壁又堅又厚，似乎是敲打不開，或許\能推(push)開。\n",
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
        if(arg != "石壁") return 0;
        message_vision("$N使勁的推動著石壁，不多時石壁便出現了出口。\n\n",me);
         set("exits", ([
          "west" : __DIR__"stone",
          "down" : __DIR__"pool",
        ]));
        return 1;
}
