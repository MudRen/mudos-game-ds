inherit ROOM;
void create()
{
        set("short", "山道");
        set("long",@LONG
這裡已經是直通山上的道路了，感覺似乎還要走一段時間，可是沿路
風景皆不錯，讓你心情還算愉悅，因此走來頗為順暢，看來要到山上該可
節省不少時間，北邊有一條路往山上，南邊則是下山。
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu8",
  "southdown" : __DIR__"mu6",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





