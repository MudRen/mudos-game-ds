
inherit ROOM;

void create()
{
	set("short", "�e�U");
	set("long", @LONG
�o�ӫe�U�����C�ܦ��_�j�����D�A�A�Ҭݨ쪺�a�㳣�O�ΤW�������
�[�W��諸��u�Ұ������A��ȳ��Ʃ�o����A�a�W�󦳤j���⪺�a��Q
�ۡC�A�ݨ�e�観������A��W���F�\�h�W�a���r�e�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room23",
	    "west" : __DIR__"room27",
	    "south": __DIR__"room10",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
