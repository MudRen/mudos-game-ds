// Room: /u/s/slency/area/ugelan/church4.c

inherit ROOM;

void create()
{
	set("short", "�����s��");
	set("long", @LONG
�o�̬O�а�e�@�y���j���s���A�@�y�j�Ѫ��а�K�q�ߦb�s������
�A�A�i�H����\�h�H���b�а���f�i�i�X�X�A�o�y�а�i�H�ٱo�W����
�B���Ұꪺ���F���ߡA�X�G�Ҧ��������C���鳣�|�즹§���A�]�]��
�s���W�`���j�s�H���Өө����A�Ѧ����F�K�O�����а�A����O�@�Ӽs
���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church3",
  "east" : __DIR__"god1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
