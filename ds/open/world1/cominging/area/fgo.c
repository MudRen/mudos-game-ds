inherit ROOM;

void create()
{
	set("short", "�B�F����");
	set("long", @LONG
�o�̬O�B�F�����@���e����A�b�o�̦��\�h�������A�]���\�h
�������M���ΡA�ӳ���̫h�b��K�B�𸭤W���s�s��媺�s�T�A�ᦳ��
�\���ն��P�A�b�F��O���B�F���̭��e�i�A�ө�����o�u���@���p�|�i
�H�樫�A���G�Ŷ����j���ˤl�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fgo1.c",
  "east" : __DIR__"river6.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}