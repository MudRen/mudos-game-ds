inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你來到了森林的東側，這裡的花草樹木都毫無活力，感覺就像是死
亡的樣子，四周都死氣沉沉的，似乎說明著此地並不是什麼好地方，儘
管如此你也還是不願意放棄，東邊和北邊可以繼續前進。
LONG
        );
        set("exits", ([
  "north" : __DIR__"t20",
  "southeast" : __DIR__"t13",
  "southwest" : __DIR__"t1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








