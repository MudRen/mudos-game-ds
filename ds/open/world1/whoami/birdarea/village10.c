#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�n����"NOR);
 set("long",@LONG
�A����F�n���󪺧���, �w�g����b���e���F, �b�A���F��
�N�O�y�����̦n��´���̪��a, �A�i�H�h���ݬ�, �o�����q�_��
����o.
LONG
    );
 
 set("exits",(["east":__DIR__"village11",
               "north":__DIR__"village7",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

