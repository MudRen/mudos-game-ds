// Modify with AreaMaker1.0
// Room70.c

inherit ROOM;

void create()
{
	set("short","�j���");
	set("long", @LONG
�o�̬O�@���j���A�|�B���O��o�o���گ�C�C�󪺨��D���H��
�ѲH���W�Q���Pı�A�H�ͳ̩��֤��Ʋ��L���ª��ͬ��F�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room60",
		"south": __DIR__"room80",
		"west": __DIR__"room69",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider0" : 2,
		__DIR__"npc/pig0" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","land");	
	setup();
	replace_program(ROOM);
}

