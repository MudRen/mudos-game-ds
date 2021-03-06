// Room: /u/l/lestia/area/map_7_5.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-大殿入口");
	set("long", @LONG

『靈幻殿』••••剛剛看到的三個大字就是靈幻殿的牌匾，從外表看
起來很明顯的牌匾有在做維護，可是還是可以看出來歲月的刻痕，「靈幻殿
」三字看起來蒼勁有力，似乎是由名家所書寫，大門旁有二根需由二人才能
合抱的石柱，柱子上面刻著精美的雕飾，雕飾的內容好像是在訴說著靈幻教
的歷史。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_6",
  "north" : __DIR__"map_6_5",
  "west" : __DIR__"map_7_4",
  "south" : __DIR__"map_8_5",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
