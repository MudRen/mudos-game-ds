#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�e�|");

 set("long",@LONG
�A�Ө�ѱ��Ъ��e�|, �P�仡�O�e�|�ˤ��p���O��
���٤���A�X, �b�o�̪������~�ݨ����n�h�W�n�X��,
�ӥB�����]�ܦh�F, �L�̥���b�۱���, �A�ߤ��t�Q��
�����\�O�ѱ�, �G�M�O���������C
 
LONG
    );
 
 set("exits",(["east":__DIR__"bird15",
               "west":__DIR__"bird13",
               "north":__DIR__"bird22",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
