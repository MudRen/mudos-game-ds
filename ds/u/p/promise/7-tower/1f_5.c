#include <ansi.h>
inherit ROOM;

string *temp_msg = ({
HIC"\n�b�@�}���g�L��A�A���G�^��F�¤ѼӡC\n\n"NOR,});

void create()
{
  set ("short", YEL"�ʽ���"NOR);
  set ("long","�����A�N�h�Ĥ��G�����u�@�����t�Ҧa�A�b�Ǧ���ӥ��J�A���O
�N��y���ۡz�P�y�d���z�A�Q���L�̪��N��]�O��`�o��غ믫�Ӻ�
���L�N�⪺�a��a�C\n"NOR);
  set("exits", ([
  "northwest" : __DIR__"1f_4", 
  ])); 
  set("no_clean_up", 0);
  
  setup();
 } 
void init()
{
  object me;
  ::init();

  if( interactive(me = this_player()) )

  {
    remove_call_out("action1");
    call_out("action1",1,me);
    me->start_busy(2);
  }
}

int action1(object me)
{
  if(!me) return 1;
  if(!random(3) || wizardp(me))
  {
     message("world:world1:vision",
HIW"\n\n\t�^�i��"HIG+me->query("name")+HIW"���L�F"HIC"�i���R���}�j"HIW"�~�򪺫��򱵤U�Ӫ��D�ԡI�I\n\n"NOR,users());
    return 1;
  } 
  message("world:world3:vision",HIW"\n�i���򯺻D�j "HIR"�^�i��"+me->query("name")+HIR"�Q�۳N�Ұg�A�^�k��¤ѼӤF�I�I\n\n"NOR,users());
  message_vision(HIW"\n$N��J�F�ʽ��աA����M���Y�����w�t�I�I\n"NOR,me);
  message_vision(HIW"���G���F�ҿת��۳N�I\n"NOR,me);
  message_vision(HIW"�@�٨��A$N��ӳQ���}�_½�F�X�h�A�����L�ܼv�I�I\n"NOR,me);
  me->set_temp("block_msg/all",1);
  me->move("/open/world1/tmr/area/hotel");
  tell_room("/open/world1/tmr/area/hotel",HIY+me->query("name")+HIY"�q�ѤW���F�U�ӡA���p�_�t�I�I\n"NOR);
  me->set_temp("define_look",HIC"(���F�۳N���³J)"NOR);
  me->set("hp",(me->query("max_hp") / 5) );
  me->start_busy(10);
  call_out("action2",7,0,me);
  return 1;
}

int action2(int index, object me)
{
  string msg = temp_msg[index];
  if(!me) return 1;
  me->delete_temp("block_msg/all");
  write(msg);
  me->set_temp("block_msg/all",1);
  if(++index < sizeof(temp_msg)) call_out("action2",4,index,me);
    else
    {
      me->delete_temp("block_msg/all");
      me->delete_temp("define_look");
    }
  return 1;
}

