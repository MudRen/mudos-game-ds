#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", CYN"�V�j"HIC"�C�F"NOR);
  set ("long", @LONG
�ܥ��Z���@�ӲD�F�A������F�o�̷Pı�N�򤧫e�Ҩ��L���a�褣
�P�A�e�観��Ѫ̦b���̥�͡A�γ\�i�H�V����Ѫ̥�ť�@�U�A���
�����o��C
LONG
);
  set("exits", ([
  "east" : __DIR__"4f_3",
    ])); 
   set("objects", ([ /* sizeof() == 1 */
   __DIR__"oldman":1, 
]));

  set("no_clean_up", 0);
  set("light",1);
  setup();
 }


