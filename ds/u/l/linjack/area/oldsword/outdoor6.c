#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪����W");
 set("long",@LONG
�A�{�b���B���۪����W, �s�U���R���i�H�M�����ݨ�,
�o�Ӧa��O���۪����谼, �a��s�L, �C�s���誺�˪L�i
�H�Ѧ��B�ʵ�. �A���A�谼�|���@�Ӥp����i�H�q������
�U�誺�p��.
LONG
    );
 set("exits",([ "westdown":__DIR__"outdoor7",
                "down":__DIR__"outdoor3",
                "east":__DIR__"outdoor4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}