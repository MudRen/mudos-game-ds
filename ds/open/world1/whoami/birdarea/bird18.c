#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"���Y");

 set("long",@LONG
�o�O�@�����t�����Y, �������t�ˤ��p�������Ǹ޲�, �A��
�F�ݥ|�P, �A�o�{�o�̪��H�ܳ��w���Y, �����ѱ����O�Υ��Y��
��, �s����a�O�]�O���Y����, ���F�q������, ����h�O�j��C
LONG
    );
 
 set("exits",(["east":__DIR__"bird19",
               "west":__DIR__"bird15",
    ]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           

