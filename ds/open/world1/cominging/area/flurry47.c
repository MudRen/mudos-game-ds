inherit ROOM;

void create()
{
	set("short", "���Ϥ���");
	set("long", @LONG
�o�̬O�e�������Ϫ��M���ж��A�A�@�i��o�̴N�Pı�즳�ǧN��ŧ
�ӡA�j���O�]���o�̥|�P�����᳣�O���}���A�ӥB�ܤ����L�A���L���D
���Ȥp���ܡH�e���������ϴ���l�N�O��b�o�өж��A���G�{�b���ӧ�
�֪��ˤl�A�F��O�D�n�����D�A���D�W�������@�Ф��V�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry48.c",
]));
	set("light",1);
	set("objects",([
  __DIR__"npc/left-escort.c":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
