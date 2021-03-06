// Room: /u/s/suez/grave/path_1.c

inherit ROOM;

void create()
{
	set("short", "野亭旁");
	set("long", @LONG
兩旁樹蔭扶疏，清風吹面，好一個清靜去處。不遠處似乎有個野亭，
亭子立於山崖邊，居高臨下，不知道是哪個高人逸士於何年何月所建，當
風起霧動，樹影婆娑時，這個野亭真如凌天而起，令人不知天上人間。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"path_0",
  "east" : __DIR__"path_2",
  "northup" : __DIR__"kiosk",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
