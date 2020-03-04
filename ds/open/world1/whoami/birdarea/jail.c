#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;
inherit DOOR;

void create()
{
    set("short", "�ʨc");
        set("long", @LONG
�o�̬O�@�Ӻʨc�A�|�P����W�����F�U���U�˪��D��A�o��
�٥R���ۤ@�Ѵc�ߪ��ͯ���A�ݨӦ��G�����֤H�Q�D�D�Ӧ��A��
�e�٦���Ӯ����@�l������A�ݨ��ܦ�����Ͱ����ɶ��]�����F
LONG);
        set("exits", ([  "up" : __DIR__"rich6", ]));
        set("item_desc",([
            "�Ͱ�":"�@�Ӧ��w���\\���Ͱ��A�L���W���ӨS����ȿ��f�E\n",     ]));
        set("no_recall",1); 
        set("no_pick",1);
        setup();
        create_door("up","�K��","down",DOOR_LOCKED,"nokey"); 
}

int room_effect(object me)
{
   if(!me) return 1;
   message_vision(HIR"���򮳰_�@�l��$N���W��h�A���o$N�ֶ}�׺�I\n"NOR,me);
   me->receive_damage("hp",random(50), this_object());  
   return 1;
}

void init()
{
        ::init();
  add_action("do_run","run"); 
  add_action("do_fly","fly"); 
  add_action("do_search","search");
  add_action("do_send","send");
}

void clear_item() {
         set("item_desc",([
                "�Ͱ�":"�@�Ӧ��w���\\���Ͱ��A�L���W���ӨS����ȿ��f�E\n",     ]));
        delete_temp("search_item");
}

int do_search(string arg)
{
        object me,item;
        if(arg != "�Ͱ�") return 0;
        me = this_player();
        if( me->is_busy() ) return notify_fail("�A���ʧ@�٨S�������M���వ�ʧ@�C\n");
        message_vision("$N���H������F��Ͱ��A�ݬݦ��S�������_���E�E�E\n",me);

        if( !query_temp("search_item") && me->query_temp("can_search_seal") ){
                item=new(__DIR__"npc/obj/seal");
                message_vision("��F�S��A$N�ש�b�Ͱ��̧��"+item->query("name")+"�E\n" ,me);
                item->move(this_player());
                set_temp("search_item", 1);
                  me->delete_temp("can_search_seal");
                 set("item_desc",([
                        "�Ͱ�":"�@�Ӧ��w���\\���Ͱ��A�ݰ_�Ӧn���~��Q�j�L�C\n",     ]));
                call_out("clear_item", 600+random(300));
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

int valid_leave(object me, string dir)
{
  mapping doors;
  doors = environment(me)->query_doors();
  if( dir=="up" && doors[dir]["status"] == DOOR_OPENED )
  { 
    message_vision("\n�y�I�z���@�n�A$N���᪺�p���K����M�Q���W�F�E\n"NOR,me);
    lock_door(dir);
    return 1;
  }
  else if( dir=="up" && !doors[dir]["status"] == DOOR_OPENED ) 
    return notify_fail("���٨S�}��!\n");
  else return 0;
}


