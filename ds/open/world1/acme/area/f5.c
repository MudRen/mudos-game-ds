// Room: /open/world1/acme/area/f5.c

inherit ROOM;

void create()
{
	set("short", "�s�}");
	set("long", @LONG
�o�s�}�Q���U�p�A���ݸG���~��i�ӡA�b�s�}�`�B�A�����\�h��
�\���e���A�J�Ӥ@�ݫo�O�ʪ������e�A�}�~����񩵦��ܦ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"f4",
]));
set("objects", ([ 
  __DIR__"npc/tan" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
