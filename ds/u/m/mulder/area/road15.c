// Room: /u/m/mulder/area/road15.c

inherit ROOM;

void create()
{
	set("short", "�V�m��");
	set("long", @LONG
�o�O���s�⪺�V�m�ҡA�p�A�O�Ѫ��a���ܡD�ЦӥɨB�a�A��
�t�@��D�o���\�]²��H�K���A���ߡD
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road10",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
