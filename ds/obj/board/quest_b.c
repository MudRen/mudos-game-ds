// quest_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ȯd���O", ({ "board" }) );
	set("location", "/d/wiz/hall_quest");
	set("board_id", "quest_b");
	set("long",
		"�o�O�@�ӧŮv�̰Q�ץ��ȻP���D���d���O�C\n" );
	setup();
	set("capacity", 90);

}
