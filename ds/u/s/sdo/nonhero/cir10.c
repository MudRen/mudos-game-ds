inherit ROOM;

void create()
{
	set("short", "���D�~");
	set("long", @LONG
�A���Y�ݨ��A���W�Y�������Y�X���۶��A�W���g�ۡG�y���D�~�A
���Ф��C�z�Ӧb�a�����䪺�a��A���@�i�ۮ�A�ۮ�W���ۤ@���Q�r
����S�A�䤤�����@�b�d�b�ۮ���A�ݨӭn�ޥX�ӬO���i�઺�F�C
���L�n���`�`���H���L�A�]����`�������G�������C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"cir11",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
