inherit ROOM;

void create()
{
	set("short", "村長家二樓");
	set("long", @LONG
這裡的環境非常好，四周打掃的一塵不染。從窗戶望出去，映入
眼簾的全是一片翠綠，屋內的擺設也是非常樸素，幾乎都是木製器具
，從桌、椅，到你所能看到的任何家俱，全都是木造的，雖然說是在
森林邊，但是也太特殊了。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"house1",
	]));
	set("objects",([
		__DIR__"npc/selina.c":1,
	]));

	setup();
	replace_program(ROOM);
}
