// Room: /u/t/truewind/Minetown/area/machinefield6.c

inherit ROOM;

void create()
{
	set("short", "�}�B�����׼t");
	set("long", @LONG
�o�̬O�U���}�B�����ת��u�t�A�񲴱�h�A�U���U�˪��}�B����
����s�@�˰��A�X�G�n�B���F�A�����u�C�o���\�F�@�Ӥj�K�c�A����
�ﺡ�F����������٦��U���U�˪��s��A�A�J�Ӫ��|�B�i��A�~�M��
�����~���Ϊ����t�����A���L�j������ΤF�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"machinefield5",
  "east" : __DIR__"machinefield3",
]));

	setup();
	replace_program(ROOM);
}
