// Room: /u/t/tmr/area/street3.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�_�䦳�����K���A�����f���۵P�g�ۡu���K�������v�A���F�h�O�@��
�u�ۤp�˪��D���A�����B���y�˪L�A��a���������F�@�ӦW�r�A�N�s�u��
�_�˪L�v�A���n�h�O���˪e������C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wbridge",
  "west" : __DIR__"street2",
  "north" : __DIR__"smithy.c",
  "east" : __DIR__"river_road",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

set("light",1);
	setup();
	replace_program(ROOM);
}
