#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�x�|"NOR);
 set("long",@LONG
�o�̬O�����a���e���x�|�A�̭��ص۳\�h��A�ݨӧ���
���Z���w�������C�q�o�̥i�H�ݨ�������b�θ̳ܵۯ��A��
�O�o�S�A�Į��ۡE�E�E

LONG
    );

       set("exits",([
       "north":__DIR__"town24", 
       "west":__DIR__"town20", 
       "east":__DIR__"town22",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

