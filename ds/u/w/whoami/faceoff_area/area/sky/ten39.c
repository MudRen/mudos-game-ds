#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�����p-�s�y"NOR);
 set("long",@LONG
�o�̴N�O���ɫؿv�����e��F, �A�o�{�o�O�@�y�C�ۻs
�������q, �t�W�o�s�y�צ~�������H��, �ᦳ�P�H�X�@���P! 
�ӳo�ɯ��q�e�����W�g�ۡm ���c�ۦ��`�D �n, ����o�O��
��N��? �ӦV�U���U�h�ݨӤ]�S���h��, �Q���O�U�s�����|
�F....?!
LONG
    );
 set("exits",([  "enter":__DIR__"ten40",
                 "down":__DIR__"ten29",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

