#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);
 set("long",@LONG 
�A�S���W���F�@�q�Z��, �o�{�A�����ǥX�{����, �A�S�ݤF
��, ����! �O�ն�! ��ӧA�w�g��F���h���F, �A���W�ݤF��, 
�٬O�ݤ��쳻�b����, �A���T�`�Ȱ_��, ���O�A�߷Q�J�M�w�g��
�o�򰪤F, �����٭n�U�h? ��O�A�M�w�w���Y���~�򩹤W��, �b
�A���񦳭Ӥp�}�C 
LONG);
 set("outdoors","land");
 set("no_clean_up", 0);
 set("item_desc",([
        "�p�}":"�@�ӯQ�����ª��p�}�A�ݨӷQ���D�̭��õۤ���u��i�h�ݤF�E\n",     
                ]));
 setup();
}           
void init()
{
  add_action("do_jump","jump"); 
  add_action("do_enter","enter");
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
        if (random(me->query_skill("dodge")) >= 30){
        message_vision(WHT"�u��$N�I�i�W�m�\\�[�����\\�A�V�W�@�D�K�������L�v�L�ܤF..\n"NOR ,me);
        me->move(__DIR__"bird5.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
        return 1;
        }
          if ( me->query("level") <= 5 ) {
                message_vision( "�u��$N�¤�¸}�a���k�������h�C\n"NOR ,me);
                me->move(__DIR__"bird5.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
                return 1;
        }

        message_vision(HIW"$N�b������è�@�˪����Ӹ��h�A�ݨӬO�\\�O�����A�L�k�D�L�o���k���E\n"NOR ,me);
        me->start_busy(3);
        return 1;
}
 
int do_enter(string arg)
{        
         object me;
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n�i�h���H\n");  
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n"); 
        if (arg != "�p�}") return 0; 
        message_vision("$N���l�@�Y���}���p�F�i�h�E\n"NOR ,me);
        me->move(__DIR__"hole.c");
        tell_room(environment(me),me->query("name")+"�p�F�i�ӡA���쥻�N�U�p���Ŷ��ܪ��󯶤F\n",me);
        return 1;
} 
               
 

