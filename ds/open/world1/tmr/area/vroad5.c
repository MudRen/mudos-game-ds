// Room: /u/t/tmr/area/vroad5.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�A���b�@������������D�A���W�����H�M�|�P���Ъٵ}�}�����A����
�N�����O�����a�y�λA���L�A�ˬO�Ӥ������k���Ҧb�A���_�q���@����
�D�A����n��L�@�����O�����B�i�ݨ�@�j���Ŧa�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"vroad4",
  "southwest" : __DIR__"glade",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
