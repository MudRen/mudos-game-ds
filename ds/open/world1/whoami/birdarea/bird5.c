#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG 
�A�S���W���F���֤F�Z��, �A�ݤF�ݥ|�P, �A�o�{�A�w�g�b
���h���W�F, �ŷx������, ���A���W�����L��, �M�s���Ů�, ��
�A�Ҧ������O��o����, �A���T�r�}�_��b�o�k���W���H�C
LONG
    );
 
 set("no_clean_up", 0);
 set("outdoors","land"); 
 setup();
}           

void init()
{
  add_action("do_jump","jump"); 
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
        if (random(me->query_skill("dodge")) >= 20){
        message_vision(WHT"�u��$N�I�i�W�m�\\�[�����\\�A�V�W�@�D�K�������L�v�L�ܤF..\n"NOR ,me);
        me->move(__DIR__"bird6.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
        return 1;
        }
          if ( me->query("level") <= 5 ) {
                message_vision( "�u��$N�¤�¸}�a���k�������h�C\n"NOR ,me);
                me->move(__DIR__"bird6.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
                return 1;
        }

        message_vision(HIW"$N�b������è�@�˪����Ӹ��h�A�ݨӬO�\\�O�����A�L�k�D�L�o���k���E\n"NOR ,me);
        me->start_busy(3);
        return 1;
}          


