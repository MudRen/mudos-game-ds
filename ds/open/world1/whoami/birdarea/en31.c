
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIW"�F�_"NOR"�A�L");
     set("long",@LONG
�A�{�b�Ө�F�_�A�L���h�A�����A�o�̪��h����R�ѡA�O
�H�uı�o�Y������A���H�Ԩ��A��V�P�y�ɥ��h�@�ΡA�b�o�d��
�o�h�A�̡A�u��̪�ı�N���X�@���͸��F�C
LONG
);
     set("outdoors","forest");
     setup();
}
void init()
{
     add_action("do_move","move");
}
int do_move(string arg)
{
          object me;
          me=this_player();
          if( me->over_encumbranced() )
                return notify_fail("�A���t���L���M�ʼu���o�C\n");
          if( me->is_busy() )
                return notify_fail("�A���ʧ@�٨S�������M���ಾ�ʡC\n");
          if( me->query("wound/left_leg") > 10 && me->query("wound/right_leg") > 10  )
                return notify_fail("�A���}�˶չL���A�L�k�q�L�d�h�C\n");
          if(arg!="s" && arg!="n" && arg!="south" && arg!="north")
          {
            notify_fail("���̪��d�h�ܲ`�A���i�ਫ���L�h���C\n");
            return 0;
          }
          else {
            if(arg == "s" || arg == "south")
            {
              message_vision("$N�ΤO����}�q�d�h���ޥX�A�w�w�����n��L�h�C\n",me);
              me->move(__DIR__"en32");
            }
            if(arg == "n" || arg == "north")
            {
              message_vision("$N�ΤO����}�q�d�h���ޥX�A�w�w�����_��L�h�C\n",me);
              me->move(__DIR__"en30");
            }
            return 1;
          }
} 
int room_effect(object me)
{
          switch(random(10))
        {
         case 0:
         case 1:
         case 2:

                message_vision("�A�����}���C�C���J�d�h���D�D�D�C\n",me);
                if(me->query_skill("dodge")< 35 && random(10)<3 )
                {
                        tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
                        me->add_busy(5);
                }

                else if(me->query_skill("dodge")< 70 && random(10)<3 )
                {
                        tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
                        me->add_busy(3);
                }

                else if(me->query_skill("dodge")>69 && random(10)<3 )
                {
                        tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
                        me->add_busy(1);
                }
                return 1;
        

         default:       return 1;
        }
}


