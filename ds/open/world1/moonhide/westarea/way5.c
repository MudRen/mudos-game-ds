// Room: /open/world1/moonhide/westarea/way1.c

inherit ROOM;

void create()
{
	set("short", "���ݨ��D");
	set("long", @LONG
�A���b�����W�����D�A�}�U�򪺬O�ιΥժ�᪺�����A�A�]���M
���H���i�௸�b���W�A�o���T�O�Ӥ��Ѥ��g�C�o�����D�ᬰ�e�s�A
�Ʀܥi�H������j�����b���ӹL�C���D�d�d���驹�e���i�A�A�]����
�o���|�q�����C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"way4",
  "south" : __DIR__"way6",
]));
	set("no_clean_up", 0);
	set("outdoors","land");

	setup();
	replace_program(ROOM);
}
