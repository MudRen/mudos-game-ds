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
              me->move(__DIR__"village1");
            }
            if(arg == "n" || arg == "north")
            {
              message_vision("$N�ΤO����}�q�d�h���ޥX�A�w�w�����_��L�h�C\n",me);
              me->move(__DIR__"en31");
            }
            return 1;
          }
}




