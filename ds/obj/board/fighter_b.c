// fighter_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�Z�̯d���O", ({ "board" }) );
	set("location", CLASS_D("fighter") + "/guildhall");
	set("board_id", "fighter_b");
	set("long",	"�o�O�ѪZ�L���H�d���O�ƪ��d���O�C\n" );
	setup();
	set("capacity", 80);

}
