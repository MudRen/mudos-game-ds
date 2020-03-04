#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�Ө�@�B�k�����U, �A���Y���ѤW��, �p�����F���]���W
, �A��b�L�k�β����X�o�Ӯk���쩳���h��, ���p�A�ۻ{���ۤv
���\����, �A�N�W�h�ݬݧa, �b�o���䦳�@�ӥ���, �W�����G��
�ۤ@�Ǧr....
LONG
    );
 set("item_desc",([
        "����":"�A�³o�����ݤF��, �o�{�W�����|�Ӧ�����j�r,\n
          "HIR"��  �@  �k  ��"NOR"\n
     �A���T�Q���Ѭݬݼg�o�Ӧr���D�H.\n",
        "���@�k��":"�@���Q���~�k���k��, �ݨӨS���@�w���\\�O�O�W���h��\n",     ]));
 set("exits",(["south":__DIR__"en45",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
  add_action("do_jump","jump"); 
  write(MAG"���M�Ať��k�����W���H�b���S, ���s�n���O�]���d��@��, �Q�����޲�..\n"NOR);
}

int do_jump(string arg)
{        
          object me;
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n���L����H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "���@�k��") return 0;
        
        if ( me->query("class1") == "�ѱ���") {
                message_vision( "�u��$N��ۮk�����ۤF�X�n�f�O�A���[�N��U�@��÷�l�A$N�N����÷�l�����k�������h�C\n"NOR ,me);
                me->move(__DIR__"bird7.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
                return 1;
        }

        if (random(me->query_skill("dodge")) >= 50){
                message_vision(WHT"�u��$N�I�i�W�m�\\�[�����\\�A�V�W�@�D�K�������L�v�L�ܤF..\n"NOR ,me);
                me->move(__DIR__"bird2.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
                return 1;
        }

         if ( me->query("level") <= 5) {
                message_vision( "�u��$N�¤�¸}�a���k�������h�C\n"NOR ,me);
                me->move(__DIR__"bird2.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
                return 1;
        }

        message_vision(HIW"$N�b������è�@�˪����Ӹ��h�A�ݨӬO�\\�O�����A�L�k�D�L�o���k���E\n"NOR ,me);
        me->start_busy(3);
        return 1;
}          

