// Room: /open/world1/tmr/dragoncity/house4e.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Ыȩ�");
	set("long", @LONG
�o�̬O�֫ө��ȤH�̪���B�A���������@�ƥ��СC�������k����U
�O�@�i�ɡA�ɤW���Q�ȳQ�|�o�������C���Y���諸�a���\�ۤ@�i��l�A
�����٩�ۤ@�i�Ȥl�C��W����a��ۤ�Х|�_�A�����٩�۴X���ѡC�a
�W�\�ۤ@�֨d����A�@���M����¶�Ф��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"house4",
]));
	set("current_light", 1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhixuan" : 1,
]));


	setup();
	replace_program(ROOM);
}
