#include <room.h>
inherit ROOM;
void create()
{
 set("short","���ȥ𮧫�");
 set("long",@LONG
�o��O���@�릿��H�h�Ө�V����ɱ�������, ��W
��������, �A�i�H�ۤv����, �̭�������������͹�, �A
�i�H�M�L��ť�@�ǨƱ�. ���䦳��T��𮧪��ȤH.
LONG
    );
 set("exits",([ "west":__DIR__"outroom1",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}