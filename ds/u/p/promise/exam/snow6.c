#include <ansi.h>
inherit ROOM;

void create()
{
      set ("short", HIM"�N�u��"NOR);
      set ("long", @LONG
�b�o���a�̩~�M�٦������B���p�ˡA�o�@�I�N�ҩ��F���a�ͺA��
�Ҫ��ǲ��C���䦳�@�p��A���G�i�H�Q�Φ���A���}���a�C
LONG);
      
  set("exits", ([ 
   "south" : __DIR__"snow5",  
   "enter" : __DIR__"boat", 
  ]));

  set("outdoors", "snow"); 
  set("no_clean_up", 0);

  setup();
}


