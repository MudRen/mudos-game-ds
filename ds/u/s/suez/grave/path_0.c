// Room: /u/s/suez/grave/path_0.c

inherit ROOM;

void create()
{
	set("short", "知天崖");
	set("long", @LONG
崖名知天，果然有如孤懸天中，飛鳥為伴，仙猿為鄰，下可一覽紅塵
，上可逍遙青天，俗世種種有如過往雲煙，名利之心在此已不復存，獨立
於崖際，凜凜乎於萬丈黃泉，皓皓乎於千里狂風，天之大至此方知，真所
謂知天知命也。
LONG
	);
        set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path_1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
