#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�m�Z��");

 set("long",@LONG
�A�Ө�ѱ��Ъ��m�Z��, �A�ݬݥ|�P, �o�{�o�̰�
�F�@�ǥۼΥH�~�O�L�L��, �A���L�h�ݤF�ݥۼ�, �o�{
��ӳo�̬O�M���m���F�l�K�B�Z���ۼ�, �A�V�F�V�ۼ�,
�쥻�o�̪��ۼεw�׳����@��, ���p�@�Ӥ��p�ߥi��|
��o�ۼε����_, �ҥH�m�_�ӥ[�����x���C
 
LONG
    );
 
 set("exits",(["south":__DIR__"bird14",
               "north":__DIR__"bird20",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
