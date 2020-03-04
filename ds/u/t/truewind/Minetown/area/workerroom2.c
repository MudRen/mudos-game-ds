// Room: /u/t/truewind/Minetown/area/workerroom2.c

inherit ROOM;

void create()
{
	set("short", "�u�d��");
	set("long", @LONG
�u�d������W���ۤ@�ǩ_�Ǫ��p�ΡA�u������W������|�B����
�C�Ѫ�O��a�O�P���ٹM�G�ۤ@�Ƕ콦���ޡA�ݨӬO�u�d���Ѥ��t��
�C��ӪŶ��A�uť����w�q�Ѫ�O���޺|�X�ӡA�w��a�O���n���C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"workerroom1",
  "east" : __DIR__"workerroom3",
]));

	setup();
	replace_program(ROOM);
}
