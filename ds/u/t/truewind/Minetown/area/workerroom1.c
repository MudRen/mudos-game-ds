// Room: /u/t/truewind/Minetown/area/workerroom1.c

inherit ROOM;

void create()
{
	set("short", "�u�d��");
	set("long", @LONG
�}�ª�����A�|�����γ��A���㪺�Ů�C�o�̪��������A�����Q
���o�|�O�U�P�y���q�u�ҩ~���a��C�J�Ӥ��h�w���A�A�N���ۨ��Y
����V�~�򨫤U�h�A�Ʊ�h�F�ѳo�Ӧa�誺���ΡC
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"minetown5",
  "south" : __DIR__"workerroom2",
]));

	setup();
	replace_program(ROOM);
}
