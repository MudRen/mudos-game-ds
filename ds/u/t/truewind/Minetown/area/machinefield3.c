// Room: /u/t/truewind/Minetown/area/machinefield3.c

inherit ROOM;

void create()
{
	set("short", "�}�B�����׼t");
	set("long", @LONG
�o�̬O�U���}�B�����ת��u�t�A�񲴱�h�A�U���U�˪��}�B����
����s�@�˰��A�X�G�n�B���F�A�����u�C�o���\�F�ܦh�z�����j��l
�A��l���������X�X���޽u���_��s���L�h�A���G�򭫤O���Y�����I
���Y�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"machinefield6",
  "north" : __DIR__"machinefield2",
]));

	setup();
	replace_program(ROOM);
}
