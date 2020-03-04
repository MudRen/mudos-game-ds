#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ��W");
 set("long",@LONG
�A��F�@�ɤ�Ϊ��γ��W, ��M�ݨ����@����F���˪��H
���b����, �ݦa�W�����, �o�]�\�֤���F, �A�i�H���U�γ�
�h�y����.
LONG
    );
 
 set("objects",([__DIR__"npc/purpler" : 1,
               ]));
 set("outdoors","land");
 set("no_fight",1);
 set("no_clean_up", 0);
 setup();
}        

void init()
{
   add_action("do_jump","jump");
} 
int do_jump(string arg)
{        
        object me,ob; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n������H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "down" ) return 0;
        message_vision(HIR"$N���n�R�����U����K�������L�v�L�ܤF..\n"NOR ,me);
        me->move(__DIR__"village15.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"�q�ѤW���F�U�ӡE\n",me);
        return 1;
}          

