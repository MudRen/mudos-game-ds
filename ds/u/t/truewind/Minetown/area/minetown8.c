// Room: /u/t/truewind/Minetown/area/minetown8.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�o�O�q�������@���Ŧa�A�a�W���X�ګ_�X���޽u�A���L�ݰ_�ө�
�Ǫ��A�޽u�W���_�ۤ���C���訫�O����̤j���U���������׼t�A��
�n�h�O�޲z����q�����q����"�Ǥ�"�·G����B�C���F��h�i�H��o
�@�몫�ꪺ�ɥR�C
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","land");
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minetown7",
  "west" : __DIR__"machinefield1",
  "east" : __DIR__"minetown5",
  "south" : __DIR__"minetown9",
]));

	setup();
	replace_program(ROOM);
}
