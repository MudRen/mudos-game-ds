// Room: /u/s/slency/area/ugelan/god4.c

inherit ROOM;

void create()
{
	set("short", "�Ӷ�J�f");
	set("long", @LONG
�o�̬O�@�y�Ӷ骺�J�f, ���s�C�W����, �@����C���a�W�G���F��
�O, �o���񪺩~���h�@�᳣�|�I���b�o���t�g��, ���M���O�Ӷ�, �o�@
�I�]�P�����쮣�ƪ���^, �@���Զ��Ϧ����A��[���R�C

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"god7",
  "south" : __DIR__"god6",
  "west" : __DIR__"god3",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
