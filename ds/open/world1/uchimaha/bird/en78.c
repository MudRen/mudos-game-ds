#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","�F�_�A�L");
set("long", @LONG
�A���F���F�L��, �Ө�F���O��, �b�o�̦��@�ӤH��
�۹�, �q�o�۹��ݨ�, �o�۹��誺�H���G�������O�ª�, 
�A�J�Ӥ@��, �o�{�����������`�Q�H��������, �o������
�F�����ܦ�.

LONG
        );
        set("exits",(["west":__DIR__"en76",
                      ]));
        
        set("item_desc",([
        "�۹�":"�@�ӯQ���ܶª��۹��A�۹������n���i�H��ʪ��ˤl(push)�C\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
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
        if (arg != "�۹�����") return 0;
        
        message_vision("�u��$N���۹��������@���A�y��$N�����v���������F�C\n" ,me);
        me->move(__DIR__"en79.c");
        tell_room(environment(me),me->query("name")+"��M�q�W�豼�F�U�ӡCn",me);
        return 1;
}          


