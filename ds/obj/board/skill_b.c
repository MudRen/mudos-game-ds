// skill_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("技能留言板", ({ "board" }) );
	set("location", "/d/wiz/hall_skill");
	set("board_id", "skill_b");
	set("long",
		"這是一個巫師們討論技能的留言板。\n" );
	setup();
	set("capacity", 90);

}
