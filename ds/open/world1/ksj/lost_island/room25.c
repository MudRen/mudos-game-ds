#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIG"�~��"NOR);
  set("long", @LONG
�o�̬O�@��L�ڪ��j���A�����ν����C�A����A�٦��\�h����
�W�����Ӫ��A���W���R�ۤC�m�����M�_�������ΡA�����i�H�ݨ�
�øV���~�b��줤�b�]�V���A�񲴱�h���L�H�ϡA�k�M�O�ʪ����@�~
�緽�C
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room24",
      "west" : __DIR__"room26",
      "south" : __DIR__"room18",
     ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  set("no_auc", 1);
  set("objects",([
      __DIR__"npc/eq/stone1":1,
      ]));
  set("treasure_room2",1);
  setup();
}

void init()
{
  object me,z;
  me=this_player();

  if( objectp(z=present("_TREASURE_PAPER_2_",me) ) )
  add_action("do_dig","dig");
}

int do_dig()
{
  object me,ob;
  me=this_player();
 
  if( objectp(ob=present("_TREASURE_PAPER_2_",me) ) )
  {
    if( me->is_busy() )
      return notify_fail("�A�٦b���A�S�ɶ��i������C\n");
    message_vision(HIW"\n$N��ӵ۹ϤW����m�A�ʤ�}�l�����C\n"NOR,me);
    destruct(ob);
    me->start_busy(3);
    call_out("digging",3,1,me);
    if( !random(6) )
    {
      call_out("again",5,1,me);
      me->start_busy(7);
      call_out("digging",7,2,me);
      if( !random(6) )
      {
        call_out("again",9,2,me);
        me->start_busy(11);
        call_out("digging",11,3,me);
      }
    }
    return 1;
  }
}

void digging(int c,object me)
{
  switch(c)
  {
    case 1:
         message_vision(HIY"\n�@�}���W������A$N���X�F�@�ǰ]�_�C\n"NOR,me);
                new(__DIR__"npc/eq/gold")->move(environment(me));
                if(random(3)==1)
                        new(__DIR__"npc/eq/gold")->move(environment(me));

         break;

    case 2:
         message_vision(HIY"\n$N���캡��������d�g�A�S����F�@���_���C\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold-earring")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold-necklace")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold-finger")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/gold-mask")->move(environment(me));
                break;
         }
         break;

    case 3:
         message_vision(HIY"\n$N��P�򤭤ث����F�Ӥj�}�A�ש���X�F�@���_���C\n"NOR,me);
         switch( random(5) )
         {
           case 0:
                new(__DIR__"npc/eq/gold-waist")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold-wrists")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold-shield")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/gold-leggings")->move(environment(me));
                break;
           case 4:
                new(__DIR__"npc/eq/soul-finger")->move(environment(me));
                break;
         }
         break;
  }
}

void again(int c,object me)
{
  switch(c)
  {
    case 1:
         message_vision(HIW"\n$Nı�o�٦��_���A��O�~������U�h�C\n"NOR,me);
         break;

    case 2:
         message_vision(HIW"\n$N�ݨ�|�P���g�⦳���A��O�~������U�h�C\n"NOR,me);
         break;
  }
}
