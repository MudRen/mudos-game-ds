// Room: /open/world1/tmr/dragoncity/house2.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Фj�|");
	set("long", @LONG
�o�̬O�֫ө����j�|�A���@���e�諸�եɷӾ��A�W�ѡu
���߳���v�|�Ӥj�r�A�a�U�O�@�⪺�C�j�Q�a�A�|�P�ؤF�X��
�j��A���X�ӹ��Х��b�|���x���A�_���O�֫ө������U�C
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"house1",
  "north" : __DIR__"house3",
]));
	set("current_light", 2);

        set("objects", ([
                __DIR__"npc/du-qing" : 1,
        ]) );
	setup();
	replace_program(ROOM);
}
