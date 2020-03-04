// Room: /u/t/tmr/area/vroad6.c

inherit ROOM;

void create()
{
        set("short", "小巷子");
        set("long", @LONG
一條陰暗潮溼的小巷子，不時可聽見巷子底所傳出的幾聲狗叫，只覺
得四周殺氣重重，令人渾身發毛，不想久待。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"vroad4",
]));
	set("objects",([
 	  __DIR__"npc/vag" : 1,
	]) );
          set("light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
