#include <room.h>
inherit ROOM;
void create()
{
 set("short","�w�q��");

 set("long",@LONG
�o�̬O�y��B���汵�f, �����������j�L�A���y, �ϧA��
�߱��Q���κZ, �b�A���F�B�_�M�n�谱���U���U�˪���, ����
�O�q�F��j���Ӫ�, ���ǫh�O�p�H���簲�p��E
LONG
    );
 
 set("exits",(["west":__DIR__"kus1",
               "north":__DIR__"kus3",
               "south":__DIR__"kus4",
               "east":__DIR__"kus5",
              ]));
 set("outdoors","land");
 setup();
}           

