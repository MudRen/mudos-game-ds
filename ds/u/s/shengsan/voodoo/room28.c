
inherit ROOM;

void create()
{
	set("short", "�[��");
	set("long", @LONG
�o�̬O���ȤH�𮧹L�]���a��A���L�èS���Ӧh���H�b�o��L�A�]��
�Ŭr�ЬO���ӳ��w���쥴�Z���C�o�̪��\�]²��A���Z�Ⱞ�b���A��W��
�F�X�󪺦r�e�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room19",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
