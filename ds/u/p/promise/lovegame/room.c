#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIC"�C�i���t"NOR);
  set ("long", @LONG
�@�}�����������A�l�ި�o�S�O�������e�A���������ۤ@�Ӻ}�G���P
�k�A����A���������ۡA�A���U�|�P�A�o�{�l�ާA�Ӫ������A�O�P�k�ˤⰵ
�����J�O�A�����H�������A���A�뤣�o���W�R�U�ӹ����C
LONG);

  set("no_clean_up", 1);
  set("exits", ([ /* sizeof() == 1 */
"down" : "/open/world1/tmr/area/inn_3f", 
]));
 set("objects", ([ /* sizeof() == 1 */
 __DIR__"seller" : 1,
]));
  setup();
  
}

