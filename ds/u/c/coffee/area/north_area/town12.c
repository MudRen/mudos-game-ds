#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG
�o�̪�����O�����A���\�h�u�c���s���n�H�γټM�n�A���� 
�̦���ܦh�ӫ~�A�]���ĩСA�p�G�A���ݭn���ܡA�i�H�h�ݬݭ�
�I�o�̪��F�賣�ܫK�y���I�ӥk��O�@�f���A�i�H�h���̶����C

LONG
    );

       set("exits",([
       "north":__DIR__"town14",
       "south":__DIR__"town10",
       "east":__DIR__"town6",
       "west":__DIR__"town18",
           ]));

        set("objects", ([
           __DIR__"npc/villager" :2,
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

