#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�D");
 set("long",@LONG
�o��O�ӫ��ҰϪ��̥~��F, �g�L�F�o���s�D, �N�|����
���n��h���e���f, ť���n�䤣���B���@�Ӥj�Фl�������D��
�F��诫�t, �A�i�H�L�h�@���s��.
LONG
    );
 set("exits",([ "northeast":__DIR__"road2_1",
                "north":__DIR__"market2",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}