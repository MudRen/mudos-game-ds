#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","���D");
 set("long",@LONG
�����D������M�o�̨ⰼ���}���W�èS���\�]�o�O�M���N�o
�O���O�Ƥ��M���p�OŢ�M�OŢ�̪�����U�N�ᴲ�o�X�@�ѲM���M
�A���T�P�즳�ǯh��.
LONG);
 set("exits",([ 
                "east":__DIR__"bandit9", 
                "northeast":__DIR__"bandit11", 
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
}
void init()
{
  object me=this_player();

  ::init();
  if( me->query_temp("invis") > 2 ) return;
  message_vision("$N�P������@�}�L�O�K�K\n",me);
  me->receive_damage("mp",random(100));
  me->start_busy(random(4));
  
}
