#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
���~���s�n�V�ӶV�j�F....�i�O�A�{�b�ٵL�k�ݨ����ǳ��~
�쩳�b����, �A�]�L�k����o�쩳�O���@�ت��r�~, �b�A�O�Ф�
���G�S��ť�L�o�س��~���s�n....����....!?
LONG
    );
 set("exits",([ "east":__DIR__"jungle14",
                "southwest":__DIR__"jungle12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}