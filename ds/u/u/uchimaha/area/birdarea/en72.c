#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A�~�򩹥_��, ���G�Ө�F�_�A�L���`�B�F, �A��F
��|�P, �u�����䦳�@���d�h, ��L���O�@����, �o��
���������_����.

LONG
    );
 set("item_desc",([
        "�d�h":"�@���d�h�A�b�d�h�����ߦ��@�Ӥp�q�A�p�G�A�{
���A�����\\�����A�i�H�յ۶]�L�h�C\n",
     ]));
 set("exits",(["south":__DIR__"en46",
               "north":__DIR__"en74",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_run","run");
}

int do_run(string arg)
{
        object me;
        me=this_player();
        if (arg != "�d�h") return 0;
        
        message_vision("�u��$N�����{�ʡA�w�g�Ĩ�q�W�h�F�C\n" ,me);
        me->move(__DIR__"en73.c");
        tell_room(environment(me),me->query("name")+"��M�X�{�b�o�Cn",me);
        return 1;
}          
