#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�x�|"NOR);
 set("long",@LONG
�o�̬O�����a���e���x�|�A�̭��ص۳\�h��A�ݨӧ���
���Z���w�������C�e��n���٦����A���̭��o�n�����\�h��
��A�����̭�������F��C

LONG
    );

       set("exits",([
       "north":__DIR__"town25",        
       "south":__DIR__"town22",           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

