// Room: /open/world1/tmr/xiangyang/guangchang.c

inherit ROOM;

void create()
{
	set("short", "�����s��");
	set("long", @LONG
�o�̬O�����������s���A�Q�۫C�ۦa���C�F���q�V�C�s���A
�譱�q�V�ժ���A�n�����F�������A�����a�A�i�ݨ�_���O��
���w���ϸŪ��C��~�ӻX�j�j�x�𦸧������A�x��������X
�j�l�ӲV���i�ӡA�w�g�����\�H�̦b���E���C�u���@���x�L�b
�����Ө��ޡA�A�٬O�����}�a�C
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/pian" : 1,
  __DIR__"npc/bing" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westjie1_e2",
  "east" : __DIR__"eastjie1_w1",
  "south" : __DIR__"southjie1",
  "north" : __DIR__"anfupailou",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "
",
]));

	setup();
	replace_program(ROOM);
}
