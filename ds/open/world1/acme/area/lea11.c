// Room: /u/a/acme/area/lea11.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@��L�ڪ��j���A�|�P�����󲤬����j�A�樫�ɫKı�o��
�I�x���A�A�iť���K�ͦb�u���F�㪾�F��v���s�ۡA��o�ͮ�s�M�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lea10",
  "northwest" : __DIR__"lea12",
  "southwest" : __DIR__"lea13",
]));
	set("no_clean_up", 0);
     set("outdoors","land");
       set("objects", ([
           __DIR__"npc/nor" : 3,
        ]));

	setup();
	replace_program(ROOM);
}
