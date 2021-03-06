// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡是奧凡迪斯的郊區，離奧凡迪斯很近。往南走就可以看到通往奧
凡迪斯西邊側門的道路。而你可以聞到西方傳來的陣陣瀰漫著提神醒腦的
樟樹氣味。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out003",
	    "south": __DIR__"out005",
	    "north": __DIR__"out001",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}