inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
這裡再往前走就是小坡了，跟剛剛相比地勢比較傾斜，也讓人有種
路忽然陷下去的錯覺，因此很容易不小心踩空，看來應該快要走出小徑
外了，前方道路寬廣了點。
LONG
        );
        set("exits", ([
  "northdown" : __DIR__"m5-1",
  "southwest" : __DIR__"m4",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}




