#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", YEL"�ʽ���"NOR);
  set ("long","�����A�N�h�Ĥ��G�����u�@�����t�Ҧa�A�b�Ǧ���ӥ��J�A���O
�N��y���ۡz�P�y�d���z�A�Q���L�̪��N��]�O��`�o��غ믫�Ӻ�
���L�N�⪺�a��a�C\n"NOR);
  set("exits", ([
  "east" : __DIR__"w14", 
  ])); 
     set("item_desc",([
     "�}�O": HIW"\n���}�O���G�ܤ[�S���I�U(fire)�F�H\n"NOR,
        ]));
  set("no_clean_up", 0);
  
  setup();
 } 
void init()
{
        add_action("do_fire","fire");
}

int do_fire(string str)
{

object me;
me=this_player();
     if(this_object()->query_temp("fired") != 0) return 0;
             if( str !="�}�O" && me->query("class1") != "���Z��" )
       return notify_fail("what?\n"NOR);
 message_vision("�A����X�Q�A���ۻy�D�G�u"HIG"�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC"NOR"�v
\t��M�A��W�P�K�Ĥ�,���_�@�D�y"HIR"���Z�u��"NOR"�z���N�V�}�O�I�I\n\t( "HIR"�}�O�N���U�N�_�ӤF�I�I"NOR" )\n
\t\t"HIW"��M�e��X�{�F�@�����G�����I�I
\n"NOR,me);
         set("exits",([
        "east": __DIR__"w14",
        "climb":__DIR__"d1", 
 ]));
         set("long","           
�����A�N�h�Ĥ��G�����u�@�����t�Ҧa�A�b�Ǧ���ӥ��J�A���O
�N��y���ۡz�P�y�d���z�A�Q���L�̪��N��]�O��`�o��غ믫�Ӻ�
���L�N�⪺�a��a�C\n\t"HIY"�e��H�G�_�F�@�B���u�I�I\n"NOR);            
        set("item_desc",([
        "�}�O":"���O�w�Q�I�ۡC\n",
        ]));
                  
        set_temp("fired",1); 
                       return 1;
        }
void reset()
{
   set ("long","
�����A�N�h�Ĥ��G�����u�@�����t�Ҧa�A�b�Ǧ���ӥ��J�A���O
�N��y���ۡz�P�y�d���z�A�Q���L�̪��N��]�O��`�o��غ믫�Ӻ�
���L�N�⪺�a��a�C\n"NOR);
        set("item_desc",([
       "�}�O": HIW"\n���}�O���G�ܤ[�S���I�U(fire)�F�H\n"NOR,
   
        ]));

        set("exits", ([
        "east": __DIR__"w14",
             ]));
        delete_temp("fired");
        ::reset(); 
}int room_effect(object me)
{
        switch(random(2))
        {


         case 0:
         write(HIC"�}�}����ŧ���A����....\n"NOR);
         tell_object(me, HIC"�A�Pı�����w�F��..�C\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIB"�����ʷ�ŧ���A... \n"NOR);
         tell_object(me, HIB "�A�Q������F��...�C\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;
        }
}

