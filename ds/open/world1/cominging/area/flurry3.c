inherit ROOM;

void create()
{
	set("short", "�e����");
	set("long", @LONG
�o�̬O�e�������J�f�i�h�̥���F���a��A���F�w����ȡA�p����
�H�A�ҥH�o��]���@�ǽçL�b�Ӧ^���޺ʵ��A�b�F��O�@���p���Y�A��
���]�O�@���p���Y�A�o�̪��a�ܼs�j�A�O�H���T�٩_�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"flurry9.c",
  "south" : __DIR__"flurry2.c",
  "north" : __DIR__"flurry10.c",
  "east" : __DIR__"flurry4.c",
]));
	set("objects",([
  __DIR__"npc/fguard.c" : 3,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	call_other("/obj/board/flurry_b.c","???");
}
