#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG
�A�n���e���b�k���W���@�B�y�L�Y�X������, ��O�A�M�w
�A�{�b�Ө�F�_�A�L���`�B, �|�P�@�����t, �Ů𤤦��@�ѷ÷�
���Pı, �O�H�Q�������ΪA, �A��F��|�P, ���h��Ƥ��M, 
�A�����������ݨ�o�������F�_�詵���U�h�C
LONG
    );
 
 set("exits",(["west":__DIR__"en5",
               "south":__DIR__"en4",
               "northeast":__DIR__"en7",
     ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup(); 
 replace_program(ROOM);
}           

