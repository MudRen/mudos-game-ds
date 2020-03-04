// Room: /u/d/darkfool/area1/5.c

inherit ROOM;

void create()
{
	set("short", "礦工頭酒吧");
	set("long", @LONG
這裡是一間酒吧，鎮民們閒暇時都喜歡到這裡喝酒談天，店主似
乎也是個有點傳奇性的人物，如果你跟他投緣的話或許他會講幾個精
采的故事給你聽也說不一定。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"3",
]));

	setup();
	replace_program(ROOM);
}
