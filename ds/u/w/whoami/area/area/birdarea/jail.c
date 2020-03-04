#include <ansi.h>

#include <path.h>

#include <room.h>

inherit ROOM;

void create()
{
    set("short", "�ʨc");
        set("long", @LONG
�o�̬O�@�Ӻʨc�A�|�P����W�����F�U���U�˪��D��A�o��
�٥R���ۤ@�Ѵc�ߪ��ͯ���A�ݨӦ��G�����֤H�Q�D�D�Ӧ��A��
�e�٦���Ӯ����@�l������A�ݨ��ܦ�����Ͱ����ɶ��]�����F
LONG);
 set("item_desc",([
        "�Ͱ�":"�@�Ӧ��w���\\���Ͱ��A�L���W���ӨS����ȿ��f�E\n",     ]));
set("no_recall",1); 
        setup();
}
int x = 1;
int room_effect(object me)
{
   int i;
   me=this_player();
   i=me->query_temp("superjail");
   if(me->query_temp("rich_jail") > random(10)) 
   {
      message_vision(HIB"$N�X���򮳰_�@�l��V$N�A$N��Ǯɾ��X���򭫤ߤ�í�P�ɡA�q���f�ȤF�X�h�E\n"NOR,me);
         me->delete_temp("rich_jail");
       me->move(__DIR__"rich1");
   }
   else {
    message_vision(HIR"���򮳰_�@�l��$N���W��h�A���o$N�ֶ}�׺�I\n"NOR,me);
     me->receive_damage("hp",random(50));  
     me->set_temp("rich_jail",i+1);
   }
}
void init()
{
  add_action("do_run","run"); 
  add_action("do_fly","fly"); 
  add_action("do_search","search");
  add_action("do_send","send");
}

int do_search(string arg)
{
        object me,item;
        me=this_player();
        if(arg != "�Ͱ�") return 0;
        if( me->is_busy() ) return notify_fail("�A���ʧ@�٨S�������M���వ�ʧ@�C\n");
        message_vision("$N���H������F��Ͱ��A�ݬݦ��S�������_���E�E�E\n",me);
        if(x != 0){
        item=new(__DIR__"npc/obj/seal");
           message_vision("��F�S��A$N�ש�b�Ͱ��̧��"+item->query("name")+"�E\n" ,me);
           x=0;
        item->move(this_player());
        } else
        {
                message_vision("$N��F�S��A�٬O����]½���X��..\n",me);
        }                               
        return 1;
}

int do_run()
{
  write("�o�̬O�ʨc�I\n");
  return 1;
}
int do_fly()
{
  write("�o�̬O�ʨc�I\n");
  return 1;
}
int do_send()
{
  write("�o�̬O�ʨc�I\n");
  return 1;
}


