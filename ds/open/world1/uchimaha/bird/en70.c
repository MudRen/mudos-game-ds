#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�d�h�Ϫ��`�B, �b�A�����e�O�@�ʤj���n�Q�T
�ӤH�~�����d�~�j����, �b��W�ǨӤ@�}�_�S�����s
�n, �e���S�����e�i�F, �ݨӧA�u�੹�^��.

LONG
    );
 set("item_desc",([
        "����":"�o�O�@�ʾ֦��W�d�~������A�A�i�H���W�h�ݬ�\n",]));
 set("exits",(["north":__DIR__"en65",
               "northeast":__DIR__"en66",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "����") return 0;
        
        message_vision("�u��$N��B���åΡA�C�C�a���W�F����C\n" ,me);
        me->move(__DIR__"en80.c");
        tell_room(environment(me),me->query("name")+"��ݼN�N�a���F�W�ӡCn",me);
        return 1;
}                  
