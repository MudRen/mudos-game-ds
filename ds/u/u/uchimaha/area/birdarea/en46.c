#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�A�Ө�F���ܿ@�K����L, �A�Pı��o������
��, �ϧAı�o�������ΪA, ť���o�̪��C��ܦh, �A�i
�H�b�o�̬ݨ�U�ص���.

LONG
    );
 
 set("exits",(["north":__DIR__"en72",
               "southwest":__DIR__"en47",
               "southeast":__DIR__"en41",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
