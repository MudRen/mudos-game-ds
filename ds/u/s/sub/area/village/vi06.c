// Room: /u/s/sub/area/village/vi06.c

inherit ROOM;

void create()
{
	set("short", "�H�ۤp��");
	set("long", @LONG
�o�O�@���e��p�������n�_�V�D���C�b�H�ӤH�������W�A�i�H�ݨ즳
���������Y�`��A�ݨӨC�ӤH�����ۤv���дo�C���䦳�X�ʪQ��A�b�L��
���ɭԾ�U�i�O�����F�Q�״����H�C����O�@�����СA�F��O�@���ө��C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"store",
  "north" : __DIR__"vi07",
  "west" : __DIR__"house02",
  "south" : __DIR__"vi05",
]));

	setup();
	replace_program(ROOM);
}
