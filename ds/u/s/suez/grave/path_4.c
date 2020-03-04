// Room: /u/s/suez/grave/path_4.c

inherit ROOM;

void create()
{
	set("short", "斌山小道");
	set("long", @LONG
一條石板小道由此蜿蜒而上，在旁邊一株大樹底擺了個奉茶，不少村
夫獵戶坐在那裡談天，這條小徑本是村民為了樵獵而開的，後來才被一些
風雅之人取清山之石鋪成小道，以便登山遊覽。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_5",
  "eastup" : __DIR__"path_3",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
