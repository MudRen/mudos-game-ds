#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW"���[��"NOR,({"chan-kuan seal","seal"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�y�Ǥw�[���ũG�C�n�h���w���a��A�Х�pray number�A�䴩�a�観:(1)�¤Ѽ�(2)�ѫ�����(3)���������f(4)�e����(5)���Z��(6)�K����(7)�B�F������(8)�L����");
    set("value",50);
  }
  setup();
}

void init()
{
    add_action("do_move","pray");
}
int do_move(string arg)
{  
   object me = this_player();
   if(arg =="1" ) 
      {
 message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/tmr/area/hotel"); 
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
           return 1;
         } if (arg == "2"){ 
          message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/acme/area/hotel");
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
           return 1; 
         } if (arg == "3"){ 
           message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/kkeenn/love/enter"); 
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
          return 1; 
         } if (arg == "4"){
         message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
         me->move("open/world1/cominging/area/flurry49");
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
           return 1;
         }   if (arg == "5"){ 
          message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/acme/area/portal");
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me); 
          return 1;
         }   if (arg == "6"){ 
          message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/tmr/area/s_house");
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
          return 1;
          }   if (arg == "7"){ 
          message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/cominging/area/boo-lin");
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
          return 1;
          }   if (arg == "8"){ 
          message_vision(HIB"$N�j�n�۵�"NOR":"HIC"���Ū��ѡA������������O�I�I\n"NOR,me);
          me->move("/open/world1/wu_sha_town/seacoun4");
          message_vision(HIW"�@�}�g���A$N�ﭷ�ӥX�C\n"NOR,me);
          return 1;

         }else{
          write("�Э��s��J!!.....^^\n");
      return 1;
      }                   return 1;
}


