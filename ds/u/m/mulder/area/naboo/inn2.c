// Room: /u/s/sonicct/area/shop4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"����"NOR);
	set("long", @LONG
�o�̬O�@���Ѥ��P�Ū����]���z���\�U�A�O�η�M�O������Q�A�{
�A�ȥͪ��A�רӬݡA�O�����L���Ū��Ш|�C�ӥB�o�̪������]�ܦn�n��
�C
LONG
	);
		set("light",1);
	set("no_clean_up", 0);
	set("room_type","hotel"); 
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"inn",
   ]));
	set("objects", ([ /* sizeof() == 1 */
 	 __DIR__"npc/keeper" : 1,
 	]));

	setup();
	replace_program(ROOM);
}
