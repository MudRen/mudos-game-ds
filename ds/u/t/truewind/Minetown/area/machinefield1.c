// Room: /u/t/truewind/Minetown/area/machinefield1.c

inherit ROOM;

void create()
{
	set("short", "�}�B�����׼t");
	set("long", @LONG
�o�̬O�U���}�B�����ת��u�t�A�񲴱�h�A�U���U�˪��}�B����
����s�@�˰��A�X�G�n�B���F�A�����u�C�o�̪��޲z�̰��F���ץH�~
�]���Ѻ}�B���ΦU���G��R�檺�A�ȡA�p�G�A���ݭn�汼���F��]�i
�H�ӳo�̧�R�D�C
LONG
	);
	set("objects", ([ 
        __DIR__"npc/machinedealer.c" :1 ,
]));
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"machinefield4",
  "south" : __DIR__"machinefield2",
  "east" : __DIR__"minetown8",
]));

	setup();
}
