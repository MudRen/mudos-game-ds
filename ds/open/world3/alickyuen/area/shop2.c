// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�DWpShop�IAutomatic"NOR);
	set("long", "�o�OSaint�@���Z����橱�A�]�������i��ު����Y�A�b�o�R��w�g��
�ΤH��ӧאּ�H�����ӧ����C�A�i�H��(list)�ӬݬݷQ�檺�Z���ιD��C\n");
	set("exits", ([ /* sizeof() == 1 */
 "north":__DIR__"dst16",
]));
            set("objects", ([ /* sizeof() == 4 */
__DIR__"obj/seller2.c" : 1,
]));
set("light",1);
	setup();
	replace_program(ROOM);
}
