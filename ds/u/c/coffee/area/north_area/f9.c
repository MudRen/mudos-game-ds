#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��"NOR);
 set("long",@LONG 
�b�o�̡A���~���q�s�n�ǹM�|�P�A�A�Pı�n���w�g�Q���~�]
��_�ӤF�C�|�P���M�·t�A���n�����ƹ���⪺�����o�b�c����
�������ۧA�A���A���T�}�l��򪺡C
LONG
    );

       set("exits",([        
       "north":__DIR__"f8",
       "northeast":__DIR__"f14", 
       "northwest":__DIR__"f13",
       "southeast":__DIR__"f11",
       "southwest":__DIR__"f10",           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}
