#include <room.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","���㪺�p��");
 set("long",@LONG
���F�@�}�l, �A�o�{�e���w�g������������j�L�ӤF,
���]�����ܼe, �Ӥ����ݱo�M�e���������F. �n�_���X
�Ϥ��U, �Aı�o�A�~�򨫤U�h�|����n.
LONG
    );
 set("exits",([ "northeast":__DIR__"path1",
                "southwest":__DIR__"road1",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}
