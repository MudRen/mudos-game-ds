inherit ROOM;

void create()
{
	set("short", "���Y�汵�B");
	set("long", @LONG
�A���b�@�Ө��Y�q���t�@�Ө��Y���a��A�b�o����G���ǳ��˴˪�
�Pı�A�j���O�]����t�@�䪺���Y���P���O�A�o�̪��O���ä���򪺩�
�G�A�]�����`�}�A�ҥH�H�N��o�֤F�\�h�A���L�]���]������R�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry28.c",
  "east" : __DIR__"flurry30.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
