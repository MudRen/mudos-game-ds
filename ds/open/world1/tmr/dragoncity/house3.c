// Room: /open/world1/tmr/dragoncity/house3.c

inherit ROOM;

void create()
{
	set("short", "少帥府－客廳");
	set("long", @LONG
這裡是少帥府的客廳。廳雖不大，卻佈置的挺雅致。東壁懸掛著四幅
屏條，繪的是梅蘭竹菊四種花卉；西壁懸掛的是春夏秋冬。內廳居中的是
一張八仙桌。桌上端放著一套茶具，兩旁擺放著四張檀香椅，顯得極為古
樸。廳角各擺放著一盆牡丹花，似乎給這裡帶來一絲暖意。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kou-zhong" : 1,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"house2",
  "north" : __DIR__"house4",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
