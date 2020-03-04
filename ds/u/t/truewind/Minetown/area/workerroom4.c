// Room: /u/t/truewind/Minetown/area/workerroom4.c

inherit ROOM;

void create()
{
	set("short", "�u�d��");
	set("long", @LONG
�u�d������W���ۤ@�ǩ_�Ǫ��p�ΡA�u������W������|�B����
�C�Ѫ�O��a�O�P���ٹM�G�ۤ@�Ƕ콦���ޡA�ݨӬO�u�d���Ѥ��t��
�C��ӪŶ��A�uť����w�q�Ѫ�O���޺|�X�ӡA�w��a�O���n���C�o
�̪����үu�O�O�H���H�Ԩ��C

LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("objects", ([ 
        __DIR__"npc/worker.c" :4 ,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"workerroom3",
]));

	setup();
	replace_program(ROOM);
}
