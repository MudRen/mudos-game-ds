// Room: /open/world1/dragoncity/northgate2.c

inherit ROOM;

void create()
{
	set("short", "�ȪZ�~��");
	set("long", @LONG
�o�̬O�Y�s�����_�������~�����A�u�������W��O�T�Ӥj�r�C

[1;36m                      �ȪZ��
[0m
��~�Ӫ�H�ڹ𦸫I�ǽY�s���A�G�o���u�۷��Y�K�A�@�Ǥ֫�
�x���x�L�̥��b�L�d�n���}�Y�s�����H�C���䩹�_�����O�@��L
�ڪ��j���C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"caodi4",
  "west" : __DIR__"caodi5",
  "south" : __DIR__"northgate1",
  "north" : __DIR__"caodi1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
