#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"����"NOR);
 set("long",@LONG
�Ө�o�̡A�A�o�{�o������G�O��v�ϡA���䳣�O�@�ǥ���
�A���O�ܩ��㪺�i�H�ݨ�e�����@���Q�����ª��ЫΡA��������
�򨺶��Τl�|�S�O���¡E�E�E�E�E

LONG
    );

       set("exits",([
       "east":__DIR__"town35",
       "west":__DIR__"town33",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

