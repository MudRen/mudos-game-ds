// Room: /u/s/sub/area/village/vi04.c

inherit ROOM;

void create()
{
	set("short", "�H�ۤp��");
	set("long", @LONG
�o�O�@���e��p�������n�_�V�D���C������Ǧ����֪��۵P�A��ܥX
�o�����M�P�@�j���A���O���M���W�c���ӷ~���ʡC�n��O�o�̰ߤ@���@��
���J�A�F��O�@�����СC
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"house01.c",
  "north" : __DIR__"vi05",
  "south" : __DIR__"inn",
  "west" : __DIR__"vi03",
]));

	setup();
	replace_program(ROOM);
}
