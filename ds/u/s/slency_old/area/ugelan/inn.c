// Room: /u/s/slency/area/ugelan/inn.c

inherit ROOM;

void create()
{
	set("short", "[1;37m�����ȩ�[2;37;0m");
	set("long", @LONG
�o�̬O�����̤j���@���ȩ��A�o�̪��H��ө����c�A�Q�����x�A��
�ɥi�Hť��@�ǥ��b�ζ����ȫȭ̡A�j����ץL�̮ȳ~���ҵo�ͪ��_�D
���ơA�o�̨��������Υͬ��Ϋ~�A�ݭn���򪺸ܦV�A�ȥ͸߰ݡA�L�|��
�ַN���A�ѨM�ͬ������D�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"innroom1",
  "south" : __DIR__"road1",
  "north" : __DIR__"road18",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/waiter" : 1,
  __DIR__"npc/obj/mapwood" : 1,
]));
        set("no_fight", 1);
	set("valid_startroom",1); 
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
