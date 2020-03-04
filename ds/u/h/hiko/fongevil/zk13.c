inherit ROOM;
void create()
{
        set("short","石階");
        set("long",@LONG
你站在遺跡外的石階，你的眼前就是遺跡，遺跡外牆的圖騰栩栩如生
，想必是由精湛的雕刻師所製，而上面的古文卻甚為難辨，應該是已經失
傳，而遺跡入口卻甚為難找，西面有一個石台，東面則是一片山林，西北
和西南各有一條小道。
LONG
        );
  
set("exits", ([
  "east" : __DIR__"zk17",
  "west" : __DIR__"zk21",
  "northwest" : __DIR__"zk14",
  "southwest" : __DIR__"zk11",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




