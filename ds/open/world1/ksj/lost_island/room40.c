#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIW"�d�j�۪L"NOR);
  set("long", @LONG
�o�̬O�@�B���a�A��B���O���j���ƥ۾��A����b���t���۪L
�����A���خ��߷P�A�����D�|������Ǫ��]�X�ӡA�a���O�p�p���ۦ�
�A�L�k���X����Ӫ��A���r�r����o�I��C
LONG
);
  set("exits", ([ 
      "southeast" : __DIR__"room37",
      "southwest" : __DIR__"room39",
      "northwest" : __DIR__"room43",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  set("treasure_room3",1);
  setup();
}

void init()
{
  object me,z;
  me=this_player();

  if( objectp(z=present("_TREASURE_PAPER_3_",me) ) )
    add_action("do_dig","dig");
}

int do_dig()
{
  object me,ob;
  me=this_player();
  if( objectp(ob=present("_TREASURE_PAPER_3_",me) ) )
  {
    if( me->is_busy() )
      return notify_fail("�A�٦b���A�S�ɶ��i������C\n");
    message_vision(HIW"\n$N��ӵ۹ϤW����m�A�ʤ�}�l�����C\n"NOR,me);
    destruct(ob);
    me->start_busy(3);
    call_out("digging",3,1,me);
    if( !random(8) )
    {
      call_out("again",5,1,me);
      me->start_busy(7);
      call_out("digging",7,2,me);
      if( !random(8) )
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
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
         }
         break;

    case 2:
         message_vision(HIY"\n$N���캡��������d�g�A�S����F�@���_���C\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold-armor")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/diamond-ring")->move(environment(me));
                break;
         }
         break;

    case 3:
         message_vision(HIY"\n$N��P�򤭤ث����F�Ӥj�}�A�ש���X�F�@���_���C\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/diamond-necklace")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/diamond-earring")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/crystal-corslet")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/crystal-shield")->move(environment(me));
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
