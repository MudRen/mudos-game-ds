#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�q");
 set("long",@LONG
�A�Ө�d�h���ߪ��p�q�W, �|�P�@�����R, �S���b�I
�n�T, �S���λﳾ�s, �b�A�����Ǧ��@���q�۱M�a, ���V
�O�����q��, �L���G�S�ݨ�A, �p�G�A�Q�^�h, �i�H�յ�
�A�Ĥ@��.

LONG
    );
 
 set("objects",([__DIR__"npc/expert" : 1,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
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
        
        message_vision("�u��$N�����{�ʡA�w�g�Ĩ�賓�h�F�C\n" ,me);
        me->move(__DIR__"en72.c");
        tell_room(environment(me),me->query("name")+"��M�X�{�b�o�Cn",me);
        return 1;
}                  
