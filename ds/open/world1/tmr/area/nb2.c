inherit ROOM;

void create()
{
        set("short", "鶴子橋上");
        set("long", @LONG
你正走在一座石橋上，只見鳥語花香，湖清山翠，小船競渡，縱橫如
飛；柳下漁人，艤船灑網，有結網的、醉臥船頭的、泅水賭勝的，歡笑之
音不絕。奇的是橋上竟無遊客往走，往南下去就到了橋口，往北則更深入
湖心。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nb3",
  "southdown" : __DIR__"nb1",
]));
	set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
