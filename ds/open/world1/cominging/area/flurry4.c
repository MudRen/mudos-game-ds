inherit ROOM;

void create()
{
	set("short", "�訫�Y");
	set("long", @LONG
�o�̬O�e�������������A�b�o�̦��\�h���çL�Ӧ^���ʡA�b�n�観
���ж��A�̭��èS���O�������A���G�S���H���ˤl�A�F��O���Y�A��
��N�O�J�f�F�C
LONG
	);
	set("light",1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry3.c",
  "east" : __DIR__"flurry5.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
