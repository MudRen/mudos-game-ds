#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
�A���F���F�L��, �Ө�F���O��, ���@�ӤH���۹��ݥߦb��
�x�W, �ۥx�|�P����۳\�h�����W���O��, �ݼˤl�O�W�j�ɴ���
��d�U�Ӫ�, �o�������F�����ܦ�����.
LONG);
 
 set("exits",(["west":__DIR__"en76",
              ]));
 set("objects",([__DIR__"npc/statue" : 1,
     ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
        if (arg != "����" && arg != "�۹�����" && arg != "�۹�������" && arg != "��") return 0;
        
        message_vision("�u��$N��"HIW+BLK"�۹�"NOR"�������@���A�y��$N�����v���������F�C\n" ,me);
        me->move(__DIR__"en79.c");
        tell_room(environment(me),me->query("name")+"��M�q�W�豼�F�U�ӡCn",me);
        return 1;
}                 
