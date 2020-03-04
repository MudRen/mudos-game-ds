inherit ROOM;

void create()
{
	set("short", "神木前空地");
	set("long", @LONG
這裡是樹林裡的一塊小空地，空地的中央有一棵非常高大的神木
聳立在這裡，樹皮上斑駁的痕跡刻劃著歲月的留言，使你不禁肅然起
敬。這棵神木不但老，而且還非常巨大，樹幹看來有數十個人合抱的
寬度。再仔細看看眼前，還有個一人高的樹洞，不知道裡面有什麼。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
		"enter" : __DIR__"tree1f",
	]));
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
