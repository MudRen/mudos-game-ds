// Room: /u/l/lestia/area/sn3.c

inherit ROOM;

void create()
{
 set("short", "�_��j�˪L");
	set("long", @LONG

���e�O�@���շ���˪L�A�˪L�j�C�۲H�H������A�K�[�F�X�\������
�A�ӪŮ������۴˪L���ڭ��A���o�⪺������ģ�j�a�A�@�}�M�n���L���j�F
�L�ӡA�A����@�ʴʿ@�K���j��n�����M���L�Ӧ����A�𸭵o�X�F�F���n�T
�A���O�Mħ�����̦b���A���֡C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("no_map",1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sn2",
  "south" : __DIR__"sn4",
  "north" : __DIR__"sn5",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
