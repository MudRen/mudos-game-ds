// Room: /u/s/slency/area/ugelan/church2.c

inherit ROOM;

void create()
{
	set("short", "�����s��");
	set("long", @LONG
�o�̬O�@�y�۷�j���s���A�s���W�����H�ä��ܦh�A�ˬO�F�l���B
�E���b�@�_�A�֭��ۮȫȭ������������A�Ѧ�����i�H�^�쫰���ߡA��
�F�����B���y���q���а�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church1",
  "east" : __DIR__"church3",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
