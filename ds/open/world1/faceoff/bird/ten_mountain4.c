#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�ùD"NOR);

 set("long",@LONG
�o�̬O�@�ӤT�ø��f, ���F���@���p�p�����¥۪O��, ��
��h�O�@���ѩx���׽r���̹D, �ө��n�h�q���A�ҨӪ��D��,
�A�|�ؤ@��, �Q�U�j�s�ۦW���k���N���ު��q�ߦb�A�����e, 
�A�ߤ���b�����w�D�N�n�����@��....
LONG
    );
 set("exits",([ "south":__DIR__"ten_mountain3",
                "east":__DIR__"ten_mountain5", 
                "west":__DIR__"ten_mountain8",
    ]));
 set("item_desc",([
        "�k��":"�@���ݦ�����, ���o��\�\\�h\��\�}\�B\��\�k\��\, �A���ӥi�H��(climb)�W�h.\n"
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

      message_vision("$N���W�F�k��.\n"  ,me);
      me->move(__DIR__ "ten1");   
      return 1;
      }
