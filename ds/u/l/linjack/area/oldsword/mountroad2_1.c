#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���W");
 set("long",@LONG
�o���s���]�O�i�H�q��V���󪺤@���s��, �o�䪺�s����
�ܿ������, �A�@���p�ߴN�|�g�F���F. ���F�䨫�O���V����
���s����, �����䨫�i�H�q�C�s���谼�U�s.
LONG
    );
 set("exits",([ "west":__DIR__"mountroad2_2",
                "east":__DIR__"mountroad3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}