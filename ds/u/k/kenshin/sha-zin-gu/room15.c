// Room: /u/k/kenshin/sha-zin-gu/room15.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
離開了商店街，感覺也有不失商店街的熱鬧，看到前面一些由上
年紀的長青輩的老公公在那邊下象棋，你也聽到那些老公公為了一子
棋而吵架，令人想到，人生七十才開始。
LONG
        );
        set("outdoors", "land");
        set("current_light", 2);
        set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/npc/oldman3" : 1,
  __DIR__"obj/npc/oldman1" : 1,
  __DIR__"obj/npc/oldman2" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room9",
  "west" : __DIR__"room16",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

