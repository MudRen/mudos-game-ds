inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你好不容易往下坡前進，這裡的道路寬廣不少，左邊有著一座哨樓
，你的前方有著許多官兵把守著，看來戒備森嚴，這裡似乎不是普通人
可以靠近的，莫非有著什麼不尋常的事情發生。
LONG
        );
        set("exits", ([
  "south" : __DIR__"m5-1",
  "north" : __DIR__"m5-5",
  "west" : __DIR__"m5-3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








