#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ūȩ�");
 set("long",@LONG
�o���ȩЪſ�����, �u���@��²�檺�\���M�]��, �p�G�A
�����󪺸�, �o���٬O�i�H�ΤH��. �ӥB�S�O�w�R��. 
LONG
    );
 set("exits",(["south":__DIR__"inroom30",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
