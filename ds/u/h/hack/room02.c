#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"�b��"HIW"�ɪ��G�D"NOR);
  set ("long", @LONG
�@��ɪ��G�D�A�A�ݨ�o�̦��x�j�ù��A�o�N�O�c�F�Ҭ�o
���ɪſù��A�ثe�u�O�b���ն��q�A�ҥH�u���X�Ӧa����
�q��A�F��O�@���{�۶������G�D�A�O�q���j�N���A�Ӧ��
�{���ť����h�O�q�D�{�N���E
LONG);

 set("exits", ([ 
  "west" : "/open/world2/lichi_town_2/map_5_26",
  "east" : "/open/world1/tmr/area/hotel",
  "south" : "/u/h/hack/room01.c",
"wiz" : "/d/wiz/hall1",


]));
  set("objects", ([
        "/u/h/hack/item.c" : 1,
        ]) );  

  set("light",1);
  setup(); 

  replace_program(ROOM);
}
