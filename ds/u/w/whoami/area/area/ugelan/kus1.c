#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","�w�q��");

 set("long",@LONG
�A�{�b�Ө�F�w�q�䪺�y��B, ���䰱�۴X���p��, �o��
�������j���X�_, �A���p�y�L���`�N�N�|�Q�����j�h��T�B, 
�o�̤]�O�X�����a��E
LONG
    );
 set("item_desc",([
     "�p��":"�A�i�H�i�h(enter)�ݬݡE\n",
     ]));
 set("exits",(["east":__DIR__"kus2",
       ]));
 set("outdoors","land");
 setup();
} 
void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me=this_player();
        if (arg != "�p��") return 0;
        
        message_vision("�u��$N���i�F�p��C\n" ,me);
        me->move(__DIR__"boat.c");
        tell_room(environment(me),me->query("name")+"���F�i�ӡCn",me);
        return 1;
}          
int room_effect(object me)
{
          switch(random(10))
        {
         case 0:
         
                message_vision("�j�P���������A���W�j�ӡC\n",me);
                if(me->query_skill("dodge")< 30 || random(10)<3 )
                {
                        tell_object(me,HIC"�A�Q�����j�o�˰h�F��T�B\n" NOR ); 
                        me->add_busy(1);
                }
                return 1;
        

         default:       return 1;
        }
}

