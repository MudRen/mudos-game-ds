#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���U"NOR);

set("long",@LONG
�o�̬O�ѱ��w�b�@�������U, �q�`�n�Q�ױа�, �δx���n��
�ݫȤH, ���O�b����I, �A�o�{�o�̨èS���c�ت��˹�, ����O
�ΫC�۬䦨, ���H�@�ؾ�ꪺ�Pı, �ӧA�����ᤴ�M�O���کǲ�
���W�l..
LONG
    );
 set("exits",([ "north":__DIR__"pill11",
                "south":__DIR__"pill2",
                "east":__DIR__"pill14",
    ]));
//set("objects", ([__DIR__"npc/master" : 1,
//                __DIR__"npc/birdguard" : 2,
//                __DIR__"npc/bird_waiter" : 2,
//    ]));
 set("item_desc",([
        "�W�l" : "�@�ڤj�j���W�l, �A�o�{���G�i�H��(jump)�W�h....\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me=this_player();
      if (arg != "�W�l") return 0;
      message_vision(HIY"$N�̦��, �a���D�W�W�l!\n"NOR  ,me);
      tell_object(me,HIY"�A�ש��D�W�W���F!\n"NOR);
      me->move(__DIR__ "floor1");   
      return 1;
      }
