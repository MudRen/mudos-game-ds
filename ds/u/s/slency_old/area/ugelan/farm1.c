// Room: /u/s/slency/area/ugelan/farm1.c

inherit ROOM;

void create()
{
	set("short", "�վB�����~������");
	set("long", @LONG
�A�Ө�F�վB�����~������A���b�г������A���ɥi�H�ݨ��ܦh��
���A���V�O�ѺصۡA�ݨ�o���s��ΨU���A�СA�۫H�վB�������O�۷�
�I�f���@�y�j���A�o�̦��@���q���_�䪺�۸��A�A�ݨ�ܦh�H�b�o����
�W����A�ѳo���~�򩹥_�����ӴN�O�վB�����F�C
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"farm8",
  "west" : __DIR__"farm3",
  "north" : __DIR__"farm5",
  "east" : __DIR__"farm2",
  "meetroom" : "/u/s/slency/meetroom",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
