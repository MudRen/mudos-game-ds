// Room: /u/s/sonicct/area/road17.c

inherit ROOM;

void create()
{
	set("short", "�����J�f");
	set("long", @LONG
�o�ONaboo���������A�o�̪��p�c���_�V�A��L�̪����~�A��
�O�ѩ�o�̤Ӧh�H�A�A����M���ݨ��L�̽椰��F��C�A�u�n�C�C
�V�e���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shop7",
  "west" : __DIR__"road5",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
