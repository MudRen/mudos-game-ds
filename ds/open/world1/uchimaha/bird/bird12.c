#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���Y��");

 set("long",@LONG
�o�O�@���Υ��Y���y����, ���M���O���Y����, ��
�O���_�ӫo�񥭦a�٭n��, �A���e��F��A���e�@�I�K
��F�ѱ��Ъ��j���F, ��ӭ�ť��b�m�\���n���O�q�o
�̶ǨӪ��C 

LONG
    );
 
 set("exits",(["east":__DIR__"bird13",
               "west":__DIR__"bird11",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
