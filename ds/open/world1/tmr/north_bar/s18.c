#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�۬}��"NOR);
 set("long",@LONG 
�o�̦��G���@�����c�������b���A�A���A�Pı��Q�����ߡC
���ݵۥ~�����Ǫ��]�i�ӡA���A�i�h�]���O�C�쩳�ӫ���O�H
�n�X�h�N�n���a�A�ۤv�աI 
LONG
    );

       set("exits",([      
       "south":__DIR__"s7",             ]));
        set("objects", ([
           __DIR__"npc/soul" :1,
           ]));
 set("no_clean_up", 0);
 setup();
}

