// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "夕照");
	set("long",@LONG
這間客房叫做夕照，顧名思義，每當傍晚，可以由這間客房看到美麗
的夕陽。除此之外，精緻的小几小椅，檀木的床，加上一幅花鳥畫，使得
很多女客都指定要住這間房呢！
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "east" : __DIR__"hotel_two",
               ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}