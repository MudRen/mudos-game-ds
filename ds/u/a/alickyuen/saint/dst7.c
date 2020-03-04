// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠West[2;37;0m");
	set("long", @LONG
你抬頭望上天上，看到很多車在縱橫交錯的車道上駛過，就知道他們
很趕時間了。而你自己就在這裡閒逛著，你用自己靈敏的嗅覺聞了一聞，
聞到一陣很微弱的香味，看來是由很遠傳來的，你開始向著這目標進發。
LONG
	);
	set("world", "future");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst14.c",
  "east" : __DIR__"dmid.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
