#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�o�̪�������}��, �A�|�P�ݬ�, �������G���S��
��, ���L���@�O���O���ǥi��, ���G�᭱���ǪF��, �A��
�n�_���X�ϧA�h�ݤ@��.

LONG
    );
 set("item_desc",([
        "���O":"�o���O�n���i�H��L�h���ˤl�C\n",
     ]));
 set("exits",(["southeast":__DIR__"en40",
               "northwest":__DIR__"en46",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me;
        me=this_player();
        if (arg != "���O") return 0;
        
        message_vision("�u��$N�����C�C�������b���O���C\n" ,me);
        me->move(__DIR__"en42.c");
        tell_room(environment(me),me->query("name")+"�q���O���t�@�ݬ�F�L�ӡCn",me);
        return 1;
}          
