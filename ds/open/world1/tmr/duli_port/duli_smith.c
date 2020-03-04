// File: /d/duli_port/duli_smith.c
// Updated by tmr (Thu Feb 28 03:30:14 2002)

inherit ROOM;

void create()
{
	  set("short", "杜尼港-武器專賣店");
	  set("long", @LONG
這兒是一間木造的房屋，角落排放著一堆打鐵用剩的廢鐵，屋子中間
放著一個大火爐，裡頭的炭火正燒著十分火旺，一股炎燥的熱氣直撲向你
而來。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_2_16",
]));
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/yakasi" : 1,
]));

	setup();
	  replace_program(ROOM);
}
