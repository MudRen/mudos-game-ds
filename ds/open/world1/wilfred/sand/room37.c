// Room: /open/world1/wilfred/sand/room37.c

inherit ROOM;

void create()
{
	set("short", "[33m�s��[0m");
	set("long", @LONG
�u���b�e�褣���@�B�������q���F�a�W�A�f�F�@��]��A���f�B
���۴X�쨭������~�֦�A�Y������ִU���u�áA�b���]�椺�ɰ_
�F���F�����X���Сж¶��������Y�A���a�u�ô��Y�A�ݨӨëD�[�d��
�a�C
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/obj19" : 1,
    __DIR__"npc/npc20_0" : 4,
    __DIR__"npc/npc20_1" : 2,
    __DIR__"npc/npc20_2" : 2,

]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room36_3",
]));
	set("current_light", 1);
	set("outdoors", "land");
	set("no_recall", 1);

	setup();
	replace_program(ROOM);
}
