// equip_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�˳Ưd���O", ({ "board" }) );
	set("location", "/d/wiz/hall_equip");
	set("board_id", "equip_b");
	set("long",
		"�o�O�@�ӧŮv�̰Q�׸˳ƪ��d���O�C\n" );
	setup();
	set("capacity", 90);

}
