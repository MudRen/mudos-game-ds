// Room: /u/s/superbug/train/a-22.c

inherit ROOM;

void create()
{
	set("short", "�а�");
	set("long", @LONG
�A�����e���M�X�{�F�@�y���ת��а�A�|�B���O�@�۪��Ю{�A�x�W��
���@����Y���������b���D�A�A���T�h�óo�O�_�O�u���A�A������Ĳ�N��
�䪺�H�A�A���⳺�M��V�F�L�h�A�J�Ӥ@�@�A��ӳ��O���䪺��v������
���ۼv�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-6.c",
]));
set("objects", ([
__DIR__"npc/god-father.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
