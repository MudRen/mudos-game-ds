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
  "morral":"/u/m/morral/workroom",
  "wiz":"/d/wiz/hall1",]));
  set("light",1);
  set("objects",([
  ]));
  setup();
call_other("/u/m/morral/morral_b","???");
}
int valid_leave(object me, string dir)
{
  if( dir=="west" && !wizardp(me) )
      return notify_fail("���̥u���Ův�~��i�h�C\n");
  return ::valid_leave(me, dir);
}  
