inherit ROOM;

void create()
{
	set("short", "�����a");
	set("long", @LONG
�o�̴N�O��J�����������y���Фl�A�o���Фl���M���O�ܻ��ءA
���O��P�򪺩Фl�@��A�N��o�������j�A�ӥB�S�O���O�٦��ӱ�i
�H�q���G�ӡC
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  		"up" : __DIR__"house1f2",
  		"south" : __DIR__"burg2",
	]));
	set("objects",([
		__DIR__"npc/haydn.c":1,
	]));

	setup();
	replace_program(ROOM);
}
