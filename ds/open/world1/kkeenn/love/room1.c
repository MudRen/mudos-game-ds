#include <ansi.h>;
inherit __DIR__"room";
void create()
{
        set("short", "���������D");
        set("long", @LONG
�o�̡A���������@�����Y�A�b�����k������O�������u�áA�}�}��
����q�L�̨��W���o�X�ӡA�u���\�O�ǻ������Z�L�T�a�A���M�A�A�w���@
�ݡA�j�M�o�{��ӳs�o�̪��u�ó��O�k���A�M���񪺱���ۤ��MŨ�U�A�O
�A�P��@�ѯ����P�E
LONG
        );
   set("no_recall",1);
        set("exits", ([ 
 "north" : __DIR__"room2",
  ]));
        set("objects", ([
 __DIR__"npc/guard" : 4,
]));
        set("light",1);
        setup();
}
void init()
{
  write(HIG"�q�Q���}�Х�out�A���¦X�@�C�r\n"NOR);
	add_action("do_exit", ({ "out"}) ); // "go"
 add_action("do_flee","flee");
}
int do_exit(string dir,object me)
{
 me = this_player();
//        if( dir == "out" ) 
	{
// if(!me->query_temp("kill_love") > 0)
   if(!me->query_temp("kill_love") )
   {
  message_vision(HIW+me->query("name")+"�ܦ����Y���j�ܤ@�n�G�{�}�I�ڭn�X���I\n"NOR,me);
  me->move("/open/world1/wilfred/sand/room26");   message_vision(HIG+me->query("name")+"�w�w���q���������X�ӤF�I\n"NOR,me);  
 return 1;
   }
 else
   {
 return notify_fail(HIW"�q�{�}��k(flee)�H�A�{�b�٤������}�o�̡C�r\n"NOR);
   }
	}
}
int do_flee(object me)
{
   int sk;
   object npc1,npc2,file1,file2;
        file1=load_object(__DIR__"room8");
        file2=load_object(__DIR__"room9");
me = this_player();
 if(me->query_temp("kill_love") > 0)
   {
  sk = me->query_skill("combat") - 1;
    if(objectp(npc1 = present("killer",file1)))
    {
        destruct(npc1);
    }
    if(objectp(npc2 = present("killer",file2)))
    {
        destruct(npc2);
    }
message("world:world1:vision",
HIM"\n\n�m�����j���n�G\n\t"HIW+me->name()+HIM"���ı�����������k�L�A�w�g���a�뭰�F�A�ЦU��^���n�~�j�n���J���a�I\n\n\n"NOR,users() );

message_vision(HIW+me->query("name")+"���a�D�ǡA�ܨS���𪺻��G�U��k�L�A�Щ�ڥX���a�I\n"NOR,me); 
  me->add("combat_exp",-500);  me->set_skill("combat",sk);
  me->add("exp",-2000);
  me->delete_temp("kill_love");
  message_vision(HIW"$N�]���D�ԥ��ѡA�ҥH�԰��ޯ�U���@��, �g��ȤU��2000, �Լ��U��500\n"NOR,me);
  me->move("/open/world1/wilfred/sand/room26");   message_vision(HIG+me->query("name")+"�Q�@�}��X�������F�I\n"NOR,me);  
  return 1;
   }
 else
   {
 return notify_fail(HIW"�q���}�Х�out, ���¡C�r\n"NOR);
   }
}

