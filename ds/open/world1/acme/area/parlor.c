// Room: /u/a/acme/area/parlor.c

inherit ROOM;

void create()
{
	set("short", "神武大廳");
     set("light",1);
	set("long", @LONG
這裡是神武教的大廳，旁邊的牆上掛著一幅山水畫，大廳前有張太師
椅，左側椅把上刻著龍頭，右側則刻著虎頭，太師椅上坐著一位中年男子
，但他卻陷入苦思中，並未發覺你的到來，在太師椅後的牆上貼著一幅對
子，上頭寫著「唯能極於心」，「故能極於劍」，十個黑金大字。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"corridor",
]));
    set("objects",([
       __DIR__"npc/liu" : 1,
//     __DIR__"npc/rankman" : 1,
    ]) );
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
