// Room: /u/t/truewind/Minetown/area/foodshop.c

inherit ROOM;

void create()
{
	set("short", "���~�ө�");
	set("long", @LONG
�o�O�@�a�p�p�����~�ө��A�M���c��U�P�y�����~�C�ѩ��H�O
�Ӧۤ��P�P�t���q�u�A�o�̩Ҵ��Ѫ������D�`����K���A�A�i�H�q��
���G�G�����C�o���ݥX�ӡA����b�����q�u���G�f�譱�u�O�U�F���p
���W�ߡC�Ѫ�O���@�j���L�ͪ����O���L�L���o���ť��C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("objects", ([ 
        __DIR__"npc/foodman.c" :1 ,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minetown3",
]));

	setup();
}
