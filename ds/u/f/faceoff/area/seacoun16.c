#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�I�u�B");
set("long",@LONG
�z! �o�̯��Ш�B��, �ѩ��z�X�U���H�ä��h, �ӥB���F
���]�~���ߨ�~, �]�����F���٨S������...
LONG
    );
 set("exits",(["east":__DIR__"seacoun9",
]));
 set("objects", ([__DIR__"npc/worker" : 4,
    ]));
 set("item_desc",([
        "���":"�A�o�{������U��P�a�����Ӥ�����, �j���T�����k�����_, �i��i�H�V���(push)�}.\n"
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
}             
int room_effect(object me)
{
          switch(random(8))
        {
         case 0:
	 case 1:
                message_vision(HIR"�A���Mť�����ǨӤ@�}�n��...?!\n"NOR,me);

                return 1;
        

         default:       return 1;
        }
}
void init()
{
       add_action("typepush","push");
}
     int typepush(string arg)
{
        object me,obj;
      obj=this_object();
        me=this_player();
        if(arg != "���") return 0;
     obj->set_temp("push_wall",1);
     call_out("push_wall",1,obj);
        return 1;
}

void push_wall()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("push_wall");
      switch( i ) {
          case 1:
            message_vision("$N���F�����, ���M�X�{�F�@�ө��誺�X�f!!\n\n",me);
         set("exits", ([
          "west" : __DIR__"seacoun17",
          "east" : __DIR__"seacoun9",
        ]));
            obj->set_temp("push_wall",i+1);
            call_out("push_wall",10,me);
            break;
          case 2:
            message_vision(YEL"���誺�X�f�L�n�L�������W�F�C\n"NOR,me);
         set("exits", ([
          "east" : __DIR__"seacoun9",
        ]));
            obj->delete_temp("push_wall");
            break;
            }
}