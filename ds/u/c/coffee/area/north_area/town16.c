#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�Ѥl"NOR);
 set("long",@LONG
�Ө�o�̡A��Ǫ�������O�ѿj���զ��A�e���N�O�@�a����
���A�q�o�̴N�i�Hť��A�i���ݪ��n���A�ݨӸ̭����_�ò��_��
�Ӥ��֡C

LONG
    );

       set("exits",([
       "northwest":__DIR__"town17",
       "southeast":__DIR__"town14",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

