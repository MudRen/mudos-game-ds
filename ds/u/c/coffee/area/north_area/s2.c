#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��-�G�h"NOR);
 set("long",@LONG 
�A���ۨ��ۡA��M�A�Aı�o�a�W�H�H���B�n�n���A���G�|�W
���U�h�C��ӡA�o�a�W���@�j�����d�ڡA�Ϧ����A���_���ӧ�
��K�F�C
LONG
    );

       set("exits",([        
       "north":__DIR__"s5", 
       "south":__DIR__"s1",
       "west":__DIR__"s3",
       "east":__DIR__"s4",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

