// Room: /u/s/suez/grave/path_5.c

inherit ROOM;

void create()
{
	set("short", "雲天鞍部");
	set("long", @LONG
欲登斌山，先至雲天。這裡就是登斌山的起點了，車馬大道也僅此為
止，再上去就是登山小道了，幸好斌山鮮為人知，否則此處便非如此靜謐
，而成為市賈喧譁的紅塵地了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"path_6",
  "eastup" : __DIR__"path_4",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
