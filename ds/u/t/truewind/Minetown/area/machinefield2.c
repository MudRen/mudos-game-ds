// Room: /u/t/truewind/Minetown/area/machinefield2.c

inherit ROOM;

void create()
{
	set("short", "�}�B�����׼t");
	set("long", @LONG
�o�̬O�U���}�B�����ת��u�t�A�񲴱�h�A�U���U�˪��}�B����
����s�@�˰��A�X�G�n�B���F�A�����u�C���O���O���Y�����b���Y��
�ݭn���}�B���A�Q���Y�L�������|�ھڲզ����������Ѩ줣�P�����Y
���x�üѤ��C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"machinefield1",
  "west" : __DIR__"machinefield5",
  "south" : __DIR__"machinefield3",
]));

	setup();
	replace_program(ROOM);
}
