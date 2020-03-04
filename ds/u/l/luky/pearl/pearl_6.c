// Room: /u/l/luky/room/pearl_6.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠南街"NOR);
set("long", HIW"\n
＿＿         "NOR"一走到這裡，你不禁想起小時候全家一起"HIW"      ＿＿
   :╲     "NOR"去逛街的那股興奮感，像個小孩子一樣的四"HIW"    ╱:   
   : :▏   "NOR"處張望。整齊的街道，來往的人群，讓你忘"HIW"  ▕: :   
=  : :▏   "NOR"了這個世界的血腥與暴力。往北走是珊瑚大"HIW"  ▕: :  =
=  :╱     "NOR"道，南方有間"HIM"飯店"NOR"。街道向東西方延伸。"HIW"      ╲:  =
￣￣                                                   ￣￣
	"NOR);
set("objects",([
__DIR__"npc/sightseer":2,
]));
set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"pearl_7",
  "north" : __DIR__"pearl_24",
  "south":__DIR__"pearl_36",
  "east" : __DIR__"pearl_5",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"temp/rest");
load_object(__DIR__"npc/guest");
}
