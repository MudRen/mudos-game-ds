#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","�F�_�A�L");
set("long", @LONG
�A�Ө�d�h�Ϫ��`�B, �|�P�@�����I, �b�A�����e
�観�@���j��, �b�j�۪��|�P�����F����, �L�k�~��e
�i�F....
LONG
        );
        set("exits",(["north":__DIR__"en69",
                      "northwest":__DIR__"en68",
               ]));
        
        set("item_desc",([
        "�j��":"�A�J�ӬݤF�ݳo�����Y, �o�{���Y�������@���o������, �b�j�ۤW���@�Ӥ�L,
���G�i�H����i�h(push)�C\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
int stone = 1;
void init()
{ 
         add_action("do_push","push");
}
int do_push(string arg)
{
          object ob;
          object me;
          me=this_player();
          if (arg != "�j��") return 0;
          message_vision("$N��M�ߦ�Ӽ�A�������麡�F���l�C\n",me);
          message_vision("�u��$N�ΤO�������⩹�j�ۤWݴ�F�U�h�C\n",me);
          message_vision("�u���j�ۤ����o�������Q$N�����l�_�F�X�ӡC\n",me);
          if(stone != 0){
                     message_vision(HIG"$N�o��F�@���K�ۡI�I\n\n"NOR ,me);
                     stone = 0;

                     ob=new(__DIR__"npc/obj/iron2");
                     ob->move(this_player());
                         } 
         else{
                message_vision("���O�]��$N�����l����ΡA���o���餣�����V��B�C\n",me);
             }                               
        return 1;
}


