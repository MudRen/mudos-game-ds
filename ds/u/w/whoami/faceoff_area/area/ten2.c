#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����p");

 set("long",@LONG
�o�̴N�O�Q�U�j�s���������p -- �����p�F! ���ҥH�|�p��
�٩I�O�]���ʦ~�e�q�����Ѫ��j�L, �J�|�G���b�o, �A���T���o
��j�L�s��, �o�̩��F�O�@���p��, ����O�q���̰��p�_�ٮp, 
���_�h�q���Q�U�j�s�`�B.
LONG
    );
 set("exits",([ "south":__DIR__"ten1",
	        "north":__DIR__"ten20",
		"east":__DIR__"ten3",

        "westup":__DIR__"ten9",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
