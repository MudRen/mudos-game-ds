#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�A����o���, ���G��o�������, ���O����_�詵���L�h��,
���n���i�H�^���O�L�����e���f. �A���M�i�H����������ť��@��
�����~�ȼS���n, �ӥB���G����M���F.
LONG
    );
 set("exits",([ "northwest":__DIR__"jungle12",
                "south":__DIR__"jungle4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}