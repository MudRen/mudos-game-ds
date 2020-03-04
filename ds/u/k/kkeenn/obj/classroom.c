#include <room.h>
#include <ansi.h>
inherit ROOM;                                                                                
void create()
{
  set("short",HIR"�ݢ����ʷR�Ы�"NOR);
  set("long",@LONG
�o�N�O�ݢ����M�����@�ǯ¼䪺�֨k�֤k�����Ѩk�k�����̯�����
�p�ƩҥΪ��ЫǡA�]���]�����C���s�b�������Ш|�A�ҥH���������C�Q
�������R�C

        �б¡G �ݢ����  [�{���Ѧa�|�`��D]
        ���O�G start  + [�W��]              �ŧG�}�l�W��
               kickout+ [�H�W]              �𰣤�ť�Ҫ��ǥ�
               over                         �����ҵ{
                    
LONG
  );
  set("exits",([
	"west" : "/open/world1/wilfred/newbie/eq_bank",
]) );
  set("light",1);
set("valid_startroom", 1);
  setup();
  call_other("/obj/board/sex_board.c",???);
}
void init()
{
	if(getuid(this_player()) != "opek" ) return 0;
add_action("do_start", "start");
add_action("do_over", "over");
add_action("do_kick", "kickout");
}
int do_start(string arg)
{
        object me,obj;
        me = this_player();
	obj = environment(me);
        if( !arg )
        return notify_fail("�o�����ҵ{�W�٬O...\n");
        if(obj->query("start") ) return notify_fail("Sorry..�ثe�w���ҵ{..\n"); 
        message_vision(HIC"$N�ŧG���Ѫ��ҵ{�W�٬O"+HIW+arg+HIC+"\n"NOR,me);
         tell_object(users(),HIW"\n��ݢ����ʷR�ЫǶ}�ҡ�\n"BEEP+NOR);
        obj->set("start",1);
        return 1;
}
int do_kick(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("�A�Q�n��� �S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
         return notify_fail("�o�̨S���o�ӤH�C\n");
         if(obj==me)
         return notify_fail("What are you think about?\n");
         message_vision(HIC"$N��$n��X�ЫǤF�C\n"NOR,me,obj);
         obj->move("/open/world1/tmr/area/hotel");
         return 1;
}
int do_over(object obj)
{
        object me;
        me = this_player();
        obj = environment(me);
        if(!obj->query("start")) return notify_fail("�ثe�èS���ҵ{�b�i�椤...\n");
        message_vision(HIC"$N�����F���Ѫ��ҵ{��\n"NOR,me);
        tell_object(users(),HIR"\n��ݢ����ʷR�ЫǤ��Ѩ즹������\n"NOR);
        obj->delete("start");
        return 1;
}
