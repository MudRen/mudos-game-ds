#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
set("short",HIW"�F�_"NOR"�A�L��"YEL"�d�h��"NOR"�`�B");
set("long", @LONG
�A�Ө�d�h�Ϫ��`�B, �|�P�@�����I, �b�A�����e�観�@��
�j��, �b�j�۪��|�P�����F����, �L�k�~��e�i�F....
LONG
        );
        set("exits",(["north":__DIR__"en69",
                      "northwest":__DIR__"en68",
               ]));
        
        set("item_desc",([
        "�j��":"�A�J�ӬݤF�ݳo�����Y, �o�{���Y�������@���o������, �b�j�ۤW���@�Ӥ�L,
�A���@�ѽİʷQ�n�h�����ݡC\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land"); 
        set("reborn",3600);        setup();
}
int stone = 1;
void init()
{ 
         add_action("do_push","push");
}
int do_push(string arg)
{
          object ob,ob1,ob2,ob3;
          object me;
          me=this_player(); 
        if (!arg || arg =="")
        return notify_fail("�A�n������H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
          if (arg != "�j��") return 0;
          if(me->query_skill("force") >= 100 && me->query("ap") >=1200 )
          {
                message_vision("$N��M�ߦ�Ӽ�A�������麡�F���l�C\n",me); 
                message_vision("�u��$N�ΤO�������⩹�j�ۤWݴ�F�U�h�C\n",me);
          if(stone != 0){
                message_vision("�u���j�ۤ����o�������Q$N�����l�_�F�X�ӡC\n",me);
                me->receive_damage("ap",1000);
                stone = 0;
                switch( random(10) ){
                default:
                ob1=new(__DIR__"npc/obj/iron");
                ob1->move(this_player());
                message_vision(HIG"$N�o��F�@��"+ob1->query("name")+"�I�I\n\n"NOR ,me);
                break;
                case 1:
                ob=new(__DIR__"npc/obj/iron2");
                ob->move(this_player());
                message_vision(HIG"$N�o��F�@��"+ob->query("name")+"�I�I\n\n"NOR ,me);
                break; 
                case 2:
                ob3=new(__DIR__"npc/obj/sun-stone");
                ob3->move(this_player());
                message_vision(HIG"$N�o��F�@��"+ob3->query("name")+"�I�I\n\n"NOR ,me);
                break;
                case 3:
                ob2=new(__DIR__"npc/obj/moon-stone");
                ob2->move(this_player());
                message_vision(HIG"$N�o��F�@��"+ob2->query("name")+"�I�I\n\n"NOR ,me);
                break;
                } 
                call_out("can_push",120,this_object());
                        }          else{ 
                message_vision("���j�۫o�S�����@�����R�C\n",me);
              }
          }
          else{
                message_vision("$N��M�ߦ�Ӽ�A�������麡�F���l�C\n",me);
                message_vision("�u��$N�ΤO�������⩹�j�ۤWݴ�F�U�h�C\n",me);
                message_vision("�]�\\�O$N�����\\�����`�p�A�j�ۨèS�����󪺤����C\n",me);
             }                               
        return 1;
}

void can_push(object tob)
{ 
       int stone = 1;
       return;
} 

