#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D�J�f");

 set("long",@LONG
�p�G�q�o�̦A���_��N�|�i�J�ϸz�D����, �ǻ��ϸz�D���D
���۷��j, �N��O���۷�Ȧ�g�窺�ȤH, �]����������J�o
��, �ݨӧA�ӬO���n�^������p�a.
LONG
    );
 set("exits",([ "eastup":__DIR__"ten9",
                "westdown":__DIR__"ten7",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

