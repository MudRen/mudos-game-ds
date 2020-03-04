// Room: /open/world1/moonhide/area/hotel.c

inherit ROOM;

void create()
{
	set("short", "�H�B�ȴ�");
	set("long", @LONG
�o�O�H�B�ȴ̡A�b�j���f�N�i�H�P����@�ѧN�B�B���Pı�A����
�O�դѩάO�j�Ӷ��A�o���H�B�ȴ��٬O�N�B�B���A���O�ߤ@���P���O
�A�o�̪����p�G���H���Pı���Z�ˤ����A�H�B�ȴ̪��S��A�Q�����p
�G�|�����Ať�a�C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"hotelwaiter" : 1,
]));
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"hoteloo",
  "east" : "/open/world1/cominging/purple_sun/psin5",
  "up" : __DIR__"hotel_up",
]));
	set("no_clean_up", 0);
	set("light", 1);

	setup();
	replace_program(ROOM);
}
