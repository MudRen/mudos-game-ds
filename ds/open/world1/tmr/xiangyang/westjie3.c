// Room: /open/world1/tmr/xiangyang/westjie3.c

inherit ROOM;

void create()
{
	set("short", "��j��");
	set("long", @LONG
�o�O�@���e�諸�C�۵�D�A�V�F����Y�����C�譱�O�ժ�
�����A�F��O�@�Ӥj�Q�r��f�A�u���H�ӤH���A��ö�����C�n
��O�j�ճ��C�_���O����������L��A������ť���̭��ǨӪ�
���L���޽m�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westgate1",
  "south" : __DIR__"dajiaochang",
  "east" : __DIR__"westjie2_w1.c",
  "north" : __DIR__"bingying4",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -500,
  "x" : -540,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
