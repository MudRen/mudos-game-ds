#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�A�u�۪d�g������F��, ��L�����b�����, ����
���@�ǩ_�Ǫ����, �b�A���F�観�ۤ@�ӥ��j�L�񪺥�
�����M�@�ǤH, �o�������F�䩵���U�h.
LONG
    );
 
 set("exits",(["west":__DIR__"village1",
               "east":__DIR__"village3",
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
