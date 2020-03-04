// Room: /open/world1/tmr/dragoncity/north1.c

inherit ROOM;

void create()
{
	set("short", "�_�j��");
	set("long", @LONG
�o�O�@���e�諸�C�۵�D�A�V�n�_���Y�����C�_���O�ȪZ
�����A�n����o���c���C����O�@�����]�A�@���ۼn�W�Φ���
�ѵۯ��r�A���b���������a�n���ۡA�@�Ѫѯ��������ӨӡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"north_din",
  "north" : __DIR__"northgate1",
  "west" : __DIR__"hotel",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
