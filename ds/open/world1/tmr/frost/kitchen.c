// Room: /open/world1/tmr/freezetaoism/kitchen.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-廚房");
	set("long", @LONG
這裡是道觀內掌管伙食的廚房，牆角堆了高高的柴火，房內的一個大
木桌上也堆滿各式鮮蔬鮮果，二個伙食道人正為切菜煮飯忙得不可開交，
二個大火爐也正熱氣滾滾地在烹煮食物。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"temple5",
]));
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/cook-taoist":1,
                __DIR__"npc/obj/water":3,
        ]) );


	setup();
	replace_program(ROOM);
}
