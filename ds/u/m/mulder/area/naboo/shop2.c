// Room: /u/s/sonicct/area/shop2.c

inherit ROOM;

void create()
{
	set("short", "武器店");
	set("long", @LONG
這是一間裝潢很豪華的武器店，只見這裡的員工每天都繁忙地工作，
可見他們的服務態度十分認真。往西是Naboo城的街道。
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
