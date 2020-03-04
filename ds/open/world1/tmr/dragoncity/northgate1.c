// Room: /open/world1/dragoncity/northgate1.c

inherit ROOM;

void create()
{
	set("short", "�ȪZ����");
	set("long", @LONG
�o�̬O�Y�s�����_�������������A�u�������W��O�T�Ӥj�r�C

[1;36m                      �ȪZ��
[0m
��~�Ӫ�H�ڹ𦸫I�ǽY�s���A�G�o���u�۷��Y�K�A�@�Ǥ֫�
�x���x�L�̥��b�L�d�n���}�Y�s�����H�C����O�W���Y���۶��A
�V�n�i�J���ϡC
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"north1",
  "north" : __DIR__"northgate2",
  "northup" : __DIR__"walln1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
