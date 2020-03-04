// Room: /u/k/kenshin/sha-zin-gu/room13.c

inherit ROOM;

void create()
{
	set("short", "���㩱");
	set("long", @LONG
�Ө�F���㩱�A�ݨ�F�@����R���k����Mħ�i�˪���ݨC�@��
�Ө즹�����H�Ať��a���~�����A�o��k���󥼱B�A���B���A�A�O�_
�|�ʤߩO.......?
LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/eqboss" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
