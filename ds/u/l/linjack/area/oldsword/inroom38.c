#include <room.h>
inherit ROOM;
void create()
{
 set("short","�k�����O");
 set("long",@LONG
�o��N��������F�@�I, �Y�A�q�o�Ө��ש��s�q�ݥh, �A
�i�H�o�{�k�����W���G���@�ӫF�l. ���L�n���q�����ӫF�l,
�T��O�@�Ӥj���D..  
LONG
    );
 set("exits",(["west":__DIR__"inroom37",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
