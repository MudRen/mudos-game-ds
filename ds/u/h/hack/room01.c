#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"�b��"HIW"�����"NOR);
  set ("long", @LONG
�@��o�ӱ���ߡA�o�̥|�q�K�F�A�i�H�q���\�h�a��A�u
�������ߦ��ۤ@�x�j�����q���A�Q���o�N�O�c�F�b�Ȫ��ǧ@
�a�A�o�x�q�����̬Y�د��_���\�ĳ�A�q�o�̩��_��O�ɪ�
�G�D�A�F�O�c�F�u�@�ǡA���ثe���b���ؤ��E
LONG);

  set("exits", ([ 
  "north" : "/u/h/hack/room02.c",
  "east" : "/u/h/hack/workroom2.c",
 "south" : "/u/h/hack/workroom.c",

]));
  
  set("light",1);
  setup(); 
call_other( "/obj/board/hack_b", "�b�ȯd���O" );


  replace_program(ROOM);
}
