// Room: /u/s/suez/grave/path_2.c

inherit ROOM;

void create()
{
	set("short", "斌山小道");
	set("long", @LONG
蜿蜒的斌山小道悄悄的在這裡停住了，抬頭望去，斌山山頂仍高高在
上，雖然欲登頂一小天下，但惜乎無路可行。由此望去，斌山之壁，陡落
如劍，飛猿難攀，和由山下至此的一片綠樹如蔭，芳草依依是大異其趣，
往西可至知天崖，其風景瑰麗豪壯堪稱一絕。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_3",
  "west" : __DIR__"path_1",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
