#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", RED"�c�F"HIW"�u�@��"NOR);
  set ("long", @LONG
�@��o�Ӥu�@�ǡA�N�ݨ�o�̦��ۤ@�i�j��l�A�P�@���d
�K���F�n�w�骺�����A�᭱���ۤ@�x�����T�A������q
�q�����֡A�@��o�̴N�Pı��L���D�H�@�w�~��������.^^

LONG);

  set("exits", ([ 
  "west" : "/u/h/hack/room01.c",
 
]));
 
  set("light",1);
  setup(); 


  replace_program(ROOM);
}
