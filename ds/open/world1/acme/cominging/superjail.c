// This is a room made by roommaker.
#include <path.h>
inherit ROOM;

void create()
{
    set("short", "���K�c");
        set("long", @LONG
�o�̬O�@�Ӥj�¨c�A�c�г��O�ζ¿����y���KŢ�A�ݨӤQ����T
�A�b�¨c�~���@�i�Ȥl�W���ۤ@�ӸT�x�j�`�ޡA�u���L½�ۤ⤤���j
�U�l�A�}�l�լd�A���a�@�I���A�A�u���@�ߪ����Ԥ@�q�ɶ��F�C
LONG
        );
set("no_recall",1);
	setup();
}
int room_effect(object me)
{
int i;
   me=this_player();
i=me->query_temp("superjail");
   if(me->query_temp("superjail") > 10) 
   {
     message_vision("�T�x�o�{�~��F$N�A�E�N$N�ѩ�F�C\n",me);
         me->delete_temp("superjail");
       me->move(TMR_PAST+"area/hotel");
   }
   else {
    message_vision("�T�x�`��½�}�F�⤤���j�U�l�A�}�l�լd$N�����@�I���C\n",me);
         me->set_temp("superjail",i+1);
   }
}
void init()
{
  add_action("do_run","run");
}

int do_run()
{
  write("�o�̷t�L�Ѥ�A�L�k��ʡI\n");
  return 1;
}
