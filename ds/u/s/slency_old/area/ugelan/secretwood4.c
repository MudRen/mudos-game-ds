// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
