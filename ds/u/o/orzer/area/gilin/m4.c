inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你走在小徑上面，看著周圍的山壁聳直不已，感覺此地也別有一番
風味，頗有一種自得其樂的味道，往前方看去小徑已經慢慢往下，感覺
似乎有個小坡，可能要小心一點。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"m5",
  "southeast" : __DIR__"m3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}



