#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit __DIR__"way00.c";

void create()
{
  set("short",HIG"�s�V�j�D"NOR);
  set("long",(: print_mountain_msg :),);
  set("exits", ([ 
  "northup" : __DIR__"way10",  
  "southdown" : __DIR__"way08",  
]));
        set("outdoors","land");
        set("objects", ([ 
          __DIR__"npc/man" : 1,
        ]));


        setup();
}

void init()
{
  object me,ob; 
  me=this_player();      
  if(interactive(ob =this_player())) {
  }
   if (random(me->query_skill("dodge",1)) < 60)
     {
          message_vision(CYN"$N�Τ��¼������\\�b�̹D�W�樫�A���gı�o�S�j�S�֡C\n"NOR,this_player());
          this_player()->add("ap",-5);
     }
     else
     {
           message_vision(CYN"$N�H��H�����\\�A�ֳt���Ĳv���q�L�̹D�C\n"NOR,this_player());
     }
}