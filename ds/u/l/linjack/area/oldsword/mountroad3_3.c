#include <room.h>
inherit ROOM;
void create()
{
 set("short","��L�����p�D");
 set("long",@LONG
�o�䦳�@�����㪺�p�D�����ާA�W�s, �A�i�H�������q��
���ݨ�s���|�U�k���M���ؿv��. ���_������~��, �άO���F
���s�U�h.
LONG
    );
 set("exits",([ "eastdown":__DIR__"mountroad3_4",
                "north":__DIR__"mountroad3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}