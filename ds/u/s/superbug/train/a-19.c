// Room: /u/s/superbug/train/a-19.c

inherit ROOM;

void create()
{
	set("short", "�S��s��");
	set("long", @LONG
�o�̬O�@���}�ª��s�a�A�a�x�u���@�Ӧ��ª������H�b�A�ȵۡA 
�㶡���]�u���}�}�������X�Ӱs�Ȧb�ܰs�A�R�x�W���ۤ@�s�����ֶ����b
�t���ۡA�]�\�A�i�H�I�X���q��ť�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-3.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
