// Room: /u/s/sevil/workroom.c

inherit ROOM;

void create()
{
	set("short", "���J���u�@��");
	set("long", @LONG
    ��A��i�o�̡A�A���T���@�سQ���Ϊ����M��Ʊ��S���Pı�A�A���T
�P�İ_���J���V�O�A���M�q�@���󤤫_�X�@�ӤH�v�A�A�w���@�ݡA��ӬO
���J���p�d��--�u����v�]�F�X�ӡE�E�E�A���T�h�ë禳�H�b�i�o���d����
�A�u�O�ǤH�E�E�E
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "thief" : "/open/world2/shengsan/aovandis/room100",
  "shop" : __DIR__"1f/11.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"box/box.c" : 1,
  __DIR__"npc/guard.c" : 3,
  __DIR__"npc/toad.c" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

        setup();
     call_other("/obj/board/sevil_b.c", "???");
	replace_program(ROOM);
}
