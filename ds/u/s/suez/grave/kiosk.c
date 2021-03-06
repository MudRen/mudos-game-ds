// Room: /u/s/suez/grave/kiosk.c

inherit ROOM;

void create()
{
	set("short", "野亭");
	set("long", @LONG
一間被蔥鬱的樹木包圍的野亭，幾片枯葉飄落在地上，風吹過時發出
沙沙的聲響，中間一個石桌，桌上擺了個棋盤，旁邊兩個石凳以及地上放
了一疊疊的書，亭柱上的詩筆法蒼勁，猶似龍飛鳳舞，詩云：

【  飛筆衿如墨  仗劍面如霜  折筆絕劍處  正是清明時  】

LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "棋盤" : "棋盤上黑白兩子散落，看起來竟如一幅山水，而非劍拔弩張的死生之地。
",
  "書" : "看一看這些書，似乎諸子百家，詩書易禮樣樣都有，樣樣都缺。
",
]));
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 1,
]));
    set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"path_1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
