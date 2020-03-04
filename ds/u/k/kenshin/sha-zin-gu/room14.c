// Room: /u/k/kenshin/sha-zin-gu/room14.c

inherit ROOM;

void create()
{
	set("short", "道具店");
	set("long", @LONG
來到了道具店，看到滿步生活用品，往前一望，看到一櫃排滿的
道具，努力一看，都是武林少有的珍貴東西，心裡想想不知那些東西
有多少價值呀?
LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/itemboss" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
