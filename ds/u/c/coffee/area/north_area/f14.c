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
       "northeast":__DIR__"f19",
       "southwest":__DIR__"f9",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

