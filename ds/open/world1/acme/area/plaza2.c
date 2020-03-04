inherit ROOM;

void create()
{
        set("short", "廣場");
        set("long", @LONG
這裡是天城的南邊廣場，北邊可通往中央廣場，東邊傳來陣陣的打鐵聲
顯然是一家打鐵鋪，往南可出城。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"plaza1",
  "south" : __DIR__"street",
  "east" : __DIR__"weapon",
]));
        set("no_clean_up", 0);
        set("outdoors","land");

        setup();
        replace_program(ROOM);
}
