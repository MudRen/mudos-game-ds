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
        set("outdoors","forest"); 
//        set("reborn",900);
        setup();
}
void init()
{ 
         add_action("do_push","push");
}
int do_push(string arg)
{
        object me=this_player();
        int stone = this_object()->query_temp("stone"); 
        if (!arg || arg =="")
        return notify_fail("�A�n������H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");

        if (arg != "�j��") return 0;
        if(me->query_skill("force") >= 100 && me->query("ap") >=1200 )
          {
                message_vision("$N��M�ߦ�Ӽ�A�������麡�F���l�A�u��$N�ΤO�������⩹�j�ۤWݴ�F�U�h�I�I\n",me); 
          if(stone != 1){
                message_vision("�u���j�ۤ����o�������Q$N�����l�_�F�X�ӡC\n",me);
                me->receive_damage("ap",1000);
                this_object()->set_temp("stone",1);
                switch( random(10) ){
                default:
                new(__DIR__"npc/obj/iron")->move(this_player());
                message_vision(HIG"$N�o��F�@���K�ۡI�I\n\n"NOR ,me);
                break;
                case 1:
                new(__DIR__"npc/obj/iron2")->move(this_player());
                message_vision(HIG"$N�o��F�@�����K�ۡI�I\n\n"NOR ,me);
                break; 
                case 2:
                new(__DIR__"npc/obj/sun-stone")->move(this_player());
                message_vision(HIG"$N�o��F�@�����ۡI�I\n\n"NOR ,me);
                break;
                case 3:
                new(__DIR__"npc/obj/moon-stone")->move(this_player());
                message_vision(HIG"$N�o��F�@�����ۡI�I\n\n"NOR ,me);
                break;
                } 
                call_out("can_push",7200,this_object());
              } else { 
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

void can_push()
{ 
        this_object()->set_temp("stone",0);
       return;
} 

