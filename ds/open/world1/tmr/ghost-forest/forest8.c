// Room: /open/world1/tmr/ghost-forest/forest8.c

inherit ROOM;

void create()
{
	set("short", "�p�|");
	set("long", @LONG
�o�O�@���ᤣ�������p�|�A����U�i���L�ƨB�A�樫�䶡�A�ˤ��p��
�O�b��P�𤧶����Żئ樫�A���n�褣���B�i�ݨ�B�Ŧa�A�p�G���֤F
�A�ˤ����쨺���ƥ𮧡A�A�滰���C
LONG
	);
	set("world", "past");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"forest9",
  "southwest" : __DIR__"forest6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
