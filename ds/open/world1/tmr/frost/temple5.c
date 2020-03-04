// Room: /open/world1/tmr/freezetaoism/temple5.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�Ŧa");
	set("long", @LONG
�o�̬O�D�[�����Ŧa�A�Ŧa���C�ƨB�N���Ȥ�d�s�Ӧ����찲�H�A��
�[���D�H�m�k�I�N���a��A�Ŧa�F�������p�ΡA���D�[�����p�СC
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"kitchen",
  "south" : __DIR__"temple6",
  "west" : __DIR__"temple3",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
