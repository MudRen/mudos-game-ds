#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"���E"NOR);
 set("long",@LONG
�o�̬O���̰ߤ@���@�a�ĩ��A�A�̥i�N�i�H����@�@���į�
�j�ҴN���b�e���i�į��A�ݭn������Ī��ܥi�H�ۤv���I
���O�j�Ҭݰ_�Ӧn�����дo...

LONG
    );

       set("exits",([
       "east":__DIR__"town18",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
 set("light", 1);
}     


