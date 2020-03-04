// Room: /u/s/sub/area/village/vi08.c

inherit ROOM;

void create()
{
	set("short", "�H�ۤp��");
	set("long", @LONG
�_�䦳���p��A�]�����㪺���Y�a�W���O�����H�H���d�ڡA�@���V�_
�䩵���L�h�C�p�G�n�i�J�����O�ѤF��c�l�W���d�ڵ��M�����b��I���_
���i�H��@�Ӥp��A�n��O�@�Ӥp�����C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
    set("objects", ([
        __DIR__"npc/village_racer1_45" : 1,
        __DIR__"npc/village_racer2_45" : 1,
        __DIR__"npc/village_racer3_45" : 1,
        ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_9_7",
  "south" : __DIR__"vi07",
]));

	setup();
	replace_program(ROOM);
}
