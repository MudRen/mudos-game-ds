#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��-�G�h"NOR);
 set("long",@LONG 
�o�̬O�j�}���ĤG�h�A�u�S�Q��A�o�Ӷ·t���j�}�A���M��
�����h�A�ӥB�o�̦��G�󮣩ƤF�C����ǨӰ}�}�����~���G�s�n
�A���G�O���~�b���ۦ۴ݪ��n���C
LONG
    );

       set("exits",([        
       "north":__DIR__"s2", 
//       "up":__DIR__"f12",  �H�Kmob�]�W�h
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

