
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�A�o�{�o�̦��Ӱ��s�A���s�W�٦��ӲӪ��y���y�X�A�A�P��۷��S
�O�A�ᦷ�b��������ģ�U�A��o��~�����A�ʤH�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room33",
	    "south": __DIR__"room30",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
