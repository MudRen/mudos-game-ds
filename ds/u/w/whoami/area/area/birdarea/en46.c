#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG 
�A�Ө�F���ܿ@�K����L, �A�Pı��o�����ܭ�, �ϧA
ı�o�������ΪA, ť���o�̪��C��ܦh, �A�i�H�b�o�̬ݨ�U��
����.
LONG
    );
 
 set("exits",(["north":__DIR__"en72",
               "southwest":__DIR__"en47",
               "southeast":__DIR__"en41",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        


