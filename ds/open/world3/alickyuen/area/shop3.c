//updated 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�DEqShop�IAutomatic"NOR);
	set("long", @LONG
�o�̸�Z�����@�ˡA�o�̬O�@����橱�A���檺���O�Z���ӬO����C
�P�˦a�A�Q�R�F���n��(list)�ӬݬݡA����H�|���A�짴���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dst9",
]));
set("light",1);
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/seller3.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
