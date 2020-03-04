// Room: /u/s/slency/area/ugelan/road7.c

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�o�̬O�@���H�鬤�骺��D�A���䦳�@�a��Q�A�M���ȫȭ̤��n��
�b�ȵ{�W�Ҧ������_�ò��~�A���p�A���W���\�h�_���A���p�h���̽�, 
�����w�]���@���i�[�����J�A�A�]�i�H�H�����������b���̦��ʤ@����
�o���_���A���F�K�O������Q�A���_�i�H�ݨ��@���а�C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sell",
  "north" : __DIR__"road16",
  "south" : __DIR__"road17",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
