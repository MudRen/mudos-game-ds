// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�Ův�d���O", ({ "board" }) );
	set("location", "/d/wiz/hall1");
	set("board_id", "wizard_b");
	set("long",
		"�o�O�@�ӨѤH�d���O�ƪ��d���O�C\n" );
	setup();
    set("capacity", 999); // alick
    set("master", ({ "cominging", "tmr", "acme", "wilfred" }));
}
