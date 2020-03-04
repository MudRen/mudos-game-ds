// Room: /open/world1/tmr/area/street5.c

inherit ROOM;

void create()
{
	set("short", "�j��");
	set("long", @LONG
�A�����b�@���s�j���x����D�A��W��H�t�y�����A�j�h�O�����n��
�������Ҧb�A���񦳦W���¤ѼӴN�y����_�䪺�j��ǡA�b���䦳���p��
�l�A�b�c�����L���H�s����h�A�ˤ����o�{��C
LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("outdoors", "land");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aya" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street4",
  "east" : "/open/world1/cominging/area/dragon/dragon_door.c",
  "west" : __DIR__"wynd",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
