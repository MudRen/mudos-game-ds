inherit ROOM;

void create()
{
	set("short", "�訫�Y");
	set("long", @LONG
�o�̬O�e�������������A�b�o�̦��\�h���çL�Ӧ^���ʡA�b�n�観
���ж��A�̭��èS���O�������A���G�S���H���ˤl�A�F��O���Y�A��
��]�٬O���Y...�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry8.c",
]));
	set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
