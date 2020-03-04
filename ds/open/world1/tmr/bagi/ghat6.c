// Room: /open/world1/tmr/bagi/ghat6.c

inherit ROOM;

void create()
{
	set("short", "�B��e");
	set("long", @LONG
�b�A���e�O�y�j�B��A���s�W�H�N����Ԩϱo�򭱵��F�p�p�a���@�h
�B�A��ߤ������B�h���ɳz�X���ť�[�����~�A���G�ϱo�P�򪺮�ŤS��
�C�F�\�h�A�A�w������ı�o�Y�_���A�o�_�ݨӡC
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"ghat7",
  "southwest" : __DIR__"ghat4",
  "northwest" : __DIR__"ghat8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
