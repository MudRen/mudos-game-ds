// updated
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIC"ST�DCakeShop�IKitchen"NOR);
	set("long", @LONG
�o�̬O�J�|�������p�СA�����~����[�@�A�|�B�ݬݡA�A�o�{�F��
�سJ�|�A�ѥ]���A���~�C�A�ݵۤ]�P�즳�Ǿj�F�C���i���O����Y�A����
�ΦǤߡA����....�i��|���N�~����O.....
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"cakeshop",
]));
  set("objects",([
 __DIR__"npc/obj/chocolatecake":1,
__DIR__"npc/obj/berrycake":1,
__DIR__"npc/obj/mangocake":1,
 ]));
set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
