inherit ROOM;

void create()
{
	set("short", "�p�٫e");
	set("long", @LONG
�A�@����o�̡A�N�Pı�즳�ǳ\���L��P�A�]���o�̨S������S��
�����~�A�]�S���S���ƥ�A�j���N�O�ܥ��Z���Pı�A�b�p�ٸ̭����\
�h���\�l�A���ӬO�s��F�誺�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"flurry40.c",
  "east" : __DIR__"flurry42.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
