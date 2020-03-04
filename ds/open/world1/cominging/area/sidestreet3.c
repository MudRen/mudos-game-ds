inherit ROOM;
void create()
{
        set("short", "側街中");
        set("long",@LONG
你慢步的走到了這裡，在北邊有一陣陣的朗書聲傳了過來，你不禁
搖頭一聽，原來是一家私塾在上課中，往東方是南大街，而往西方則是
往側街的轉角的地方，北邊的讀書聲令你不由得跟著朗朗上口念了下去
了。
LONG
        );
        set("exits", ([
  "west" : __DIR__"sidestreet2.c",
  "east" : __DIR__"sidestreet4.c",
  "north" : __DIR__"seminary.c",
]));

        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

int valid_leave(object me, string dir)
{
  ::valid_leave();
  if( dir=="north" && !userp(me))
  return notify_fail("那裡只有玩家才能進去。\n");
  return ::valid_leave(me, dir);
}


