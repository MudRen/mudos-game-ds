// Room: /open/world1/tmr/ghost-forest/forest13.c

inherit ROOM;

void create()
{
	set("short", "�ۤl��");
	set("long", @LONG
�A���b�@���ѤH�u�Q�����ۤl���W�A�D����Ǻغ��F��ƨu�����յ�
�A���F��L���`�B��h�i�@�����y�p���A���n�����B�A�j���F�}�}�կ��
������A�V�O�L�h�A���G����V���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shrine.c",
  "northwest" : __DIR__"forest15",
  "southwest" : __DIR__"forest11",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
