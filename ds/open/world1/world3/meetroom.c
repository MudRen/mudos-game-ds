#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIY"���Ӱϰ�B���g�|ĳ�U"NOR);
  set("long",@LONG
�o�ӤQ���s�j�ӵ��R���|ĳ�U�A�N�O�ѭt�d���ӥ@��
��wiz�}�|���a��A�ѩ�O���Ӫ����Y�A�ҥH�]�Ƭ�
�����i�A�O�H�Ĭ��[��C
LONG
  );
  set("exits",([
  "wiz":"/d/wiz/hall1",]));
  set("light",1);
  set("objects",([
  ]));
  setup();
call_other("/obj/board/future_b","???");
}

