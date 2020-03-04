#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short",HIW"�B�褧�}�]"NOR);
  set("long",HIW @LONG
�Ө�o�Ӥs�}�H��G�H�A�@�ݥ|�P���M���O�p�p���B���A�B����
�����G�L��A���O�ѵM����l�A�s�}�̦��@�y�B���Ӧ����קɡA�A��
���b�}�f�N�����o�ݡA�ڤ��o�������}�o�̡C
LONG NOR);
  set("exits",([ 
      "out":__DIR__"room105",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("light","1");
  set("objects",([
      __DIR__"npc/yukionna":1,
     ]));
  setup();
}            

int room_effect(object me)
{
  switch(random(5))
  {
    case 0:
    case 1:
    case 2:

    message_vision("�p�P�������H��A·¶�b�A���}��D�D�D�C\n",me);
    if(me->query_skill("dodge")< 35 && random(10)<3 )
    {
      tell_object(me,HIW"�A��M�a�ʼu���o�A������}�w��a�����F�@�h�p�p���B�I�I\n" NOR ); 
      me->add_busy(5);
    }
    else if(me->query_skill("dodge")< 70 && random(10)<3 )
    {
      tell_object(me,HIW"�A�r�M�o�{���}���h��ı�A��Ӥw���F�@�h���B�I�I\n" NOR ); 
      me->add_busy(3);
    }
    else if(me->query_skill("dodge")>69 && random(10)<3 )
    {
      tell_object(me,HIW"�A��M�P�����}���ê�A�ϱo�A�ʧ@�y�w�I�I\n" NOR ); 
      me->add_busy(1);
    }
    return 1;
    default:       return 1;
  }
}
