inherit ROOM;

void create()
{
	set("short", "�e�����j���e");
	set("long", @LONG
�o�̴N�O�e�������A�A�@�Ө�o�̴N�Q�o�@���s�j���a���~�@���A
�]���T�o�X�᪺�@�n����n�A�b�������䳣���ܦh�çL�A���G�����H��
���Ӧn�i�J���ˤl�C
LONG
	);
	set("exits", ([
  "south" : __DIR__"fgo9.c",
  "northwest" : __DIR__"flurry2.c",
]));
	set("objects",([
  __DIR__"npc/fseller.c":1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
