// common.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�d���O", ({ "board" }) );
	set("location", "/u/t/tmr/room/bookroom.c");
	set("board_id", "common");
	set("long",
		"�o�O�@�ӨѤH�d���O�Ƶ��_���d���O�C\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
