// Room: /u/m/mulder/area/road6.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �s���j�D");
	set("long", @LONG
�o�إi�H�q��ĵ��άO��o�س̤j���V�m���A�ӧA�i�H��
�^�ө���R�^�@�Ǳj�l���Z���A�άO����A�άO��ۤv�m�j�@�I
�A�^�ӳo�اa�D ���n���i�H��o�ت�ĵ��D�_��O�o�����D
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shop2",
  "south" : __DIR__"shop1",
  "east" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
