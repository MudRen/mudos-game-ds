#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"�L���O"HIW"��ި��Y"NOR);
  set ("long", @LONG
�@��o�Ӥu�@�ǫe�U�A�N�ݨ�F�_�観�@������ު��G�D�A
���ײ`�������A�G�D���G���F�\�h��K�������A�����D����
��γ~�A���䪺�p�ù���ܵ۩��_�i�H�q��u�@�Ǫ����ߦa
�a
LONG);

  set("exits", ([ 
  "north" : "/u/h/hack/room01.c",
 
]));
  set("valid_startroom", 1);
  set("light",1);
  setup(); 


  replace_program(ROOM);
}
