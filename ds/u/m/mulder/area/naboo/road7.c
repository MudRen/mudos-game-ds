inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
你聽到這裡傳出一陣陣柔和的歌聲，你仔細一望之下，發覺
有一位年輕的歌女正在這裡表演。你不禁走近她身邊，留心聆聽
她的美麗歌聲。往南可以通往酒吧。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road8",
  "west" : __DIR__"middle",
  "south" : __DIR__"bar",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
