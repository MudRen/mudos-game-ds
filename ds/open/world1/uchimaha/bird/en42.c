#include <room.h>
inherit ROOM;
void create()
{
 set("short","���O");
 set("long",@LONG
�A��L���O�Ө�o��, �o�������O��, ���A������
��, ���ɦ��ǰA�l�b�A����L��, ���A����ı�o������
��, �Q�����e��, �A�ݨ�F�������������@���p��.

LONG
    );
 
 set("exits",(["east":__DIR__"en43",
               "southwest":__DIR__"en41",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
