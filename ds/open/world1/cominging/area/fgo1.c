inherit ROOM;

void create()
{
	set("short", "�˪L�J�f");
	set("long", @LONG
�o�̬O�B�F����誺�˪L�J�f�A����W�����n��e�����ݸg�L�o�@
���ϸz�p�|�A���G�ä�²��A�b�o�̪���쩳�U�����@�ιΪ���Ĭ����
��A���L���G���٨S�}�᪺�ˤl�A������O�@���p���A���G�ä��j�A��
�F��h�O��^�B�F�������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fgo2.c",
  "east" : __DIR__"fgo.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" : random(4),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
