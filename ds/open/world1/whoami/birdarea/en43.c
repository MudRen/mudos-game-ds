#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p��");
 set("long",@LONG
�A�Ө�F�@���p�p����, ���Ǧ��ǳ\���O, ���O�̤�
�ɶǥX�C�쪺��s�n, �y�ɥ|�P�u�ѤU�C�쪺��s�n, �O
�A�߸̤��, �o�����b�F�褣���B�N���G��F���Y.
LONG);
 
 set("exits",(["east":__DIR__"en44",
               "west":__DIR__"en42",
               ]));

 set("objects",([__DIR__"npc/frog" : 3+random(5),
               ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

