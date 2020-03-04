// Room: /u/t/truewind/Minetown/area/minetown4.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�o�̬O�q�����@���Ŧa�A�Ŧa�W�a�n������W�ﺡ�F�������콦
�U�C�n�䪺�q�u�u�d��U�����˳U��b�o�̡A���M�������U���^��
���C���X�U�U���}�F�A���o�X�_�Ǫ�����A�l�ޤF�@�ǻG���Φb����
�V���C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("outdoors","land");
	set("objects", ([ 
        __DIR__"npc/meat-eat-worm.c" :2 ,
]));

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown5",
  "north" : __DIR__"minetown2",
  "east" : __DIR__"minetown3",
]));

	setup();
	replace_program(ROOM);
}
