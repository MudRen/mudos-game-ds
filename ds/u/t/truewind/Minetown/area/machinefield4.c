// Room: /u/t/truewind/Minetown/area/machinefield4.c

inherit ROOM;

void create()
{
	set("short", "�}�B�����׼t");
	set("long", @LONG
�o�̬O�U���}�B�����ת��u�t�A�񲴱�h�A�U���U�˪��}�B����
����s�@�˰��A�X�G�n�B���F�A�����u�C�o�̦��\�h�¦�����˫��}
�B���A���O1996�~���i�֮R�٦����h�A�u�O�ª��i�H�F�C�����٦��@
�ǥO�A�D�`��������˨��C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"machinefield5",
  "east" : __DIR__"machinefield1",
]));

	setup();
	replace_program(ROOM);
}
