#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̬O�ѱ��w�b�@�����F�䳡��, �q�o�̲ש�i�H�ݨ�W
�l���I��, �A�o�{��ӬW�l���I���O�@�ӥW�}, �̭��O�ۤ@��
�j�j�������ѨӤH����, �A�~��M�j��, �ѱ����ӴN�O�@�ӱ�
��....
LONG
    );
 set("exits",([ "northwest":__DIR__"pill7",
                "south":__DIR__"pill13",
    ]));
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
      message_vision(HIY"$N�b�W�l�W���W���U...\n"NOR  ,me);
      tell_object(me,HIY"�A�ש����W���F!\n"NOR);
      me->move(__DIR__ "floor1");   
      return 1;
      }
