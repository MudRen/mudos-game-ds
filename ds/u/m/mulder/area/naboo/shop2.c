// Room: /u/s/sonicct/area/shop2.c

inherit ROOM;

void create()
{
	set("short", "�Z����");
	set("long", @LONG
�o�O�@�����C�ܻ��ت��Z�����A�u���o�̪����u�C�ѳ��c���a�u�@�A
�i���L�̪��A�ȺA�פQ���{�u�C����ONaboo������D�C
LONG
	);
	set("light",1);
	set("no_clean_up", 0);
	set("no_kill",1);
	set("room_type","sell");        
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road4",
]));
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
