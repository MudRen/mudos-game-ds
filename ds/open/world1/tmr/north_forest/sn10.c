// Room: /open/world1/tmr/north_forest/sn10.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L");
	set("long", @LONG
�@�����𸭦b�A�Y�W���R�ۡA�ǳ\�������ǵ۸��P�������_�ج�g�L��
�A�ϱo�a�W�¦⪺�𽮯B�{���I�I���ɡA�F�۩v�K�O���é�o���s�j���˪L
�����A�\�h���߾ǲߤ۳N���H�̡A���Q�����J�F�۩v�C
LONG
	);
	set("world", "undefine");
        set("objects", ([ 
                __DIR__"npc/troll": 2,
        ]));
	set("no_clean_up", 0);
	set("current_light", 5);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sn11",
  "west" : __DIR__"sn9w",
  "east" : __DIR__"sn9",
]));

	setup();
	replace_program(ROOM);
}
