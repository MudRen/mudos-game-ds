#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�_����"NOR);
 set("long",@LONG
�o�̬O�s���_�誺��D, �u�󦳽�Ǥp�Y, ��~���u��, �p
�c�����H�H���ݵۧA, �n���Ʊ�A�R�ǥL�̪��F��, ���L�����n
�����I....
LONG
    );
 
 set("exits",(["north":__DIR__"village13",
               "south":__DIR__"village4",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

