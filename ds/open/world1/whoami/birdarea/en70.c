#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR); 
 set("long",@LONG
�A�Ө�d�h�Ϫ��`�B, �b�A�����e�O�@�ʤj���n�Q�T�ӤH�~
�����d�~�j����, �b��W�ǨӤ@�}�_�S�����s�n, �e���S��
���e�i�F, �ݨӧA�u�੹�^��.
LONG);
 set("item_desc",([
        "����":"�o�O�@�ʾ֦��W�d�~������A�A�i�H���W�h�ݬ�\n",]));
 set("exits",(["north":__DIR__"en65",
               "northeast":__DIR__"en66",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me=this_player();
        int con = me->query_con(),str = me->query_str();
        if (!arg || arg =="") return notify_fail("�A�n������H\n"); 
        if( me->is_busy() ) return notify_fail("�A�٦b���I\n");
        if (arg != "����") return notify_fail("�A�n������H\n"); 
        if (random(str) > (con/2) ){
        message_vision("�u��$N��B���åΡA�C�C�a���W�F����C\n" ,me);
        me->move(__DIR__"en80.c"); 
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"��ݼN�N�a���F�W�ӡC\n",me);
        return 1;
        }
        tell_object(me,"�A���O�q�S�k�伵�A���魫..�A�O�����W�h��..\n");
        me->start_busy(2);
        return 1;
}                  


