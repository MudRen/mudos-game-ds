//updated 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST．EqShop＠Automatic"NOR);
	set("long", @LONG
這裡跟武器店一樣，這裡是一間售賣店，但賣的不是武器而是防具。
同樣地，想買東西亦要打(list)來看看，機械人會幫你辦妥的。
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
