inherit ROOM;
void create()
{
        set("short", "小徑");
        set("long",@LONG
你走在一條小徑中，西面是山壁垂直的懸崖，看來格外令人驚心動魄，
小徑的路面很崎嶇不寬，讓你要邊注意腳下邊前進，而西北有一個空地，看
來可以前去休憩一下，往東南方可看到一條小路。
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"zk4",
  "southeast" : __DIR__"zk2",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 

