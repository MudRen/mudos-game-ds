#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��"NOR);
 set("long",@LONG 
�Ө�o�̡A�u���M�Q���·t�A���A���G�Pı��e���n�����@
�Ѩ���A�צ�A���h���A�p�G�n�g�L�o�̡A���G�n�M�L�@������
�I�_�h�u�n���^���F�C
LONG
    );

       set("exits",([        
       "north":__DIR__"s2", 
       "down":__DIR__"s1",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}
