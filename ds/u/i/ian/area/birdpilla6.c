#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s�}��"NOR);

 set("long",@LONG
�A�^�^�������Ө��ਤ�B, ���T���q�ߩ��w�I�@�n, �u���@��������
�۴Y, �W��������W�J��F�\�h�����������B�J, �ݮݦp��, ��W�B�J��
����ϩ��n����W���X�@��, �۴Y��W�a�۪o�O, �O������n�\���w, ��
���N�M�M���۴Y���㪺����, �A�i�H�����������ݨ�۴Y�����Y, �O�@��
�۪�...   
LONG
    );
 set("exits",([ "south":__DIR__"birdpilla5",
                "east":__DIR__"birdpilla7",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

