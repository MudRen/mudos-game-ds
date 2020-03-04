// Room: /tmr/garea/forest9.c

inherit ROOM;

void create()
{
	set("short", "�����p��");
	set("long", @LONG
�u���|�P�����@�}���h�A�A�o�{�A�����b�L�����@���p���A���e���M
���X�F�|���p���A�U�۳q���˪L�`�B�A�ݤ��S�����ت��Ч@�ޡA���ڦ���
���H�A���Ȥw�y��o�C�A�����ӿ�ܦ���e��A�ƩΧ�Ӧ^�V�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	  "southwest" : __DIR__"forest8",
	  "southeast" : __DIR__"forest7",
	  "northwest" : __DIR__"forest10",
	  "northeast" : __DIR__"forest11",
	]));

	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
