#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�ùD"NOR);

 set("long",@LONG
�o�̬O�@�ӤT�ø��f, ���F���@���p�p�����¥۪O��, ��
��h�O�@���ѩx���׽r���̹D, �ө��n���D�����G�w�����ܸ�
, �A�|�ؤ@��, �Q�U�j�s�ۦW���k���N���ު��q�ߦb�A�����e
, �A�ߤ���b�����w�D�N�n�����@��....
LONG
    );
 set("exits",([ 
                "eastdown":__DIR__"ten_mountain5", 
                "westdown":"/open/world1/faceoff/sky/ten50",
    ]));
 set("item_desc",([
  "�k��" : "�@���ݦ�����, ���o���\\�h���}�B���k��, �A���ӥi�H��(climb)�W�h.\n"
    ]));
 set("no_clean_up", 0);
 setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
      object me;
      me=this_player();
      if (arg != "�k��") return 0;

      message_vision("$N���}����֥Ϊ����W�F�k���E\n"  ,me);
      me->move(__DIR__"ten1");    
      tell_room(environment(me), me->name()+"���Y�j�������W�F�o�̡E\n", ({ me }));
      return 1;
      }

