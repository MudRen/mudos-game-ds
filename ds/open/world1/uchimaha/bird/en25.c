#include <room.h>
inherit ROOM;
void create()
{
     set("short","�F�_�A�L");
     set("long",@LONG
�A�{�b�Ө�F�_�A�L���h�A����, �o�̪��h����R
��, �O�H���H�Ԩ�, �Aı�o�A�Y������, ��V�P����, �b
�o�d�׳o�h�A��, �A�u��̪�ı���X�F�C
LONG
);
     set("outdoors","land");
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
          if( me->query("wound/foot") > 10 )
                return notify_fail("�A���}�˶չL���A�L�k���ϤF�C\n");
          if(arg!="e" && arg!="n" && arg!="s")
          {
            notify_fail("���̪��d�h�ܲ`�A���i�ਫ���L�h���C\n");
            return 0;
          }
          else {
            if(arg == "e")
            {
              message_vision("$N�ΤO����}�q�d�h���ޥX�A�w�w�����F��L�h�C\n",me);
              me->move(__DIR__"en26");
            }
            if(arg == "n")
            {
              message_vision("$N�ΤO����}�q�d�h���ޥX�A�w�w�����_��L�h�C\n",me);
              me->move(__DIR__"en33");
            }
            if(arg == "s")
            {
              message_vision("$N�ΤO����}�q�d�h���ޥX�A�w�w�����n��L�h�C\n",me);
              me->move(__DIR__"en24");
            }
            return 1;
          }
}
