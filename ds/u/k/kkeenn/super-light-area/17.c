inherit ROOM;
void create()
{
       set("short","終極之路『第四層』");
      set("long",@LONG
這裡就是傳說中的樓層了，能有本領到這裡的人都是經過G•H的考驗
及祝福，看起來這邊給人一股強大的壓迫感，但是四周飄來陣陣的仙樂，
在房間的正中間射出一到強橫的白光，從白光的中間飛出一位天使？
LONG);
set("exits",([
      "up":__DIR__"18.c",
      "down":__DIR__"16.c",
] ) );
set("objects",([
__DIR__"npc/lv5_king"        :1,
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
