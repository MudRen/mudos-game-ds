// Room: /u/t/truewind/cave.c

inherit ROOM;

void create()
{
	set("short", "�s�}");
	set("long", @LONG
�o�O���M�����ɩ~��Ϩ����s�}�A�}�����F�X��²�檺�a��~�A
�i���O�Ūſ����A���򳣨S���C�����̽��۴X�󭷲M������A�A����
�٦��͹L�����l�u�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"workroom",
]));
	set("no_clean_up", 0);
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
