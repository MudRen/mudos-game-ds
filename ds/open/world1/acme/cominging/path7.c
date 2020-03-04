inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
漫長的走道，令人感覺乏味，道上不時有些從屋中交談聲傳出來，
還會不小心給你聽了進去，這裡有一根根的樑柱，又粗又大，是用大理
石和花崗石混合做成的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"house6",
  "west" : __DIR__"path3",
  "south" : __DIR__"path8",
]));
	set("item_desc",([
  "粱柱" : "粗粗的粱柱，上面還有些雕刻。\n",
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}
