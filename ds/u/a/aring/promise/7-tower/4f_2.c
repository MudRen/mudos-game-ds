#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", RED"�C���� "HIB"�i"HIW"�ȪŶ�"HIB"�j"NOR);
  set ("long", @LONG
�@����F�賣�S���A�·t���a��A������F�F�L�����A�A�e��]
����������u�A�u�����D�ӫ�򨫤U�h�C
LONG
);
  set("exits", ([
  "east" : __DIR__"4f_3",
    ])); 
   
  set("no_clean_up", 0);
  
  setup();
 }



