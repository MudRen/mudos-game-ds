#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�d�b�p��");
 set("long",@LONG
���e�N�O�Q�U�j�s���������p -- �d�b�p�F, ���M�٥��n
���p, ���Ѧ��B�V�n�軷��, �@���d�骺���s�b���e�X�{, �Q
�����N�O�j�W���������s��, �o�̩��F�O�@���p��, ���_�h�q
���Q�U�j�s�`�B.
LONG
    );
 set("exits",([ "southdown":__DIR__"ten1",
                "northup":__DIR__"ten7",
                "southeast":__DIR__"ten3",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

