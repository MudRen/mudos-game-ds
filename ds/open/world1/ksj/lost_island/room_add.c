#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","�n�L���y�f");
  set("long",@LONG
�o�̬O��f���n�ݡA�]�����L�F���@�뤣�|����a�A�������X
���p������b�L�y���A���ť�����ӥ~�a�H�b�o��c��_�S�����~�A
�٦��@����B�b�������ۦ�A�u�o�n�n�@�@�C
LONG
);
  set("exits", ([
      "north" : "/open/world1/wu_sha_town/seacoun42",
      "enter" : __DIR__"stone-boat",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/sailorman":1,
     ]) );
  setup();
}
