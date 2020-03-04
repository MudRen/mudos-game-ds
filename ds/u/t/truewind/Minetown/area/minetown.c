// Room: /u/t/truewind/Minetown/area/minetown.c

inherit ROOM;

void create()
{
	set("short", "�q���j��");
	set("long", @LONG
�o�O�q�����j���A���f����ﺡ�F�s�~�M�@�Ǿ���C��D�p����
�զ�����ۤj���ѪF�詵���X�h�A¶���@�Ӷ�ΡA���ӧ��]��F�_
�ӡC���������٥i�Hť�����Y�ǨӦU�اn�����n���C
LONG
	);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/t/truewind/workroom1.c",
  "south" : __DIR__"minetown1",
 "out":"/u/k/kkeenn/secret-area/min1",
]));

	setup();
	replace_program(ROOM);
}
