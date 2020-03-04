inherit ROOM;
void create()
{
        set("short","小道");
        set("long",@LONG
這裡是遺跡外圍的走道，已經可以很清楚看到遺跡的樣子，是用大石
所砌成，而且十分高大，在深山中竟有如此建築讓人納悶，四周仔細搜索
卻看不到入口，東北邊是屬於遺跡的一部份，西南是一座山崗。
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk13",
  "southwest" : __DIR__"zk1",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


