#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���g�p��");

 set("long",@LONG
�o�O�@���q���F�誺���g�p��, �ڻ��Q�U�j�s�s�s�̱`�b
�F��X�S, �A���زӱ�, �G�M�F�价�B���G���@�y�s��, �p�G
�S��, �٬O����^������p�a....
LONG
    );
 set("exits",([ "northwest":__DIR__"ten2",
                "eastup":__DIR__"ten4",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

