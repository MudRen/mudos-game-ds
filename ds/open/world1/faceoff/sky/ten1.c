#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short",HIG"�Q�U�j�s-�s�f"NOR);

  set("long",@LONG
�q�o�̦A���_���N�O���٤ѤU�_�p�Ҿک󦹪��Q�U�j�s
�F�A�A�q�o�̥u��ݨ체�e�h�h���|���C�r�A�����I��X�y
���P�C�⪺�s�p,�����A��.... �uı�����ŵM�@��A�L��M
�n !
LONG
    );
  set("exits",([ "north":__DIR__"ten2",
        "southdown" : "/open/world1/acme/area/pool",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  setup();
}

int valid_leave(object me, string dir)
{
  if( me->query("ten_mob") )
  {
    if( dir == "southdown")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
