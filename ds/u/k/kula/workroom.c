#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", "�ìP�Բ���a���������");
  set("long", @LONG

    �o�̬O�����νìPCHU-52����������ǡA����W���q�F���j�M�ۨC�@
�Ӯy�СC�q�o�̥i�H�q��ìP��a���U�Ӧa��C�i��o�ӡA�N���i��F�j
�����B�w�@��A�ū��J��C�и̩Ҧ����F�賣�Q���W�F�@�h�����A�a�W��
�O���F�p�p���@�h�B�C

LONG
);
  set("exits", ([
  "wiz" : "/d/wiz/hall1",
]));
  set("objects",([
  __DIR__"candy" : 1,
]) );

  set("no_clean_up", 1);
  set("light",1);
  setup();
  call_other("/obj/board/kula_b.c","???");
}


