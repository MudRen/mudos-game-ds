#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("����", ({"god's board", "board"}));
        set("location","/open/world1/god_club/boardroom.c");
        set("board_id", "club_god_1");
        set("long", @long

�����̦��Ʊ��n�Ӷq�έn���G�@�ǨƱ��ɡA���|�K�󦹪O�W�C
���٪��ϥΤ�k�Ш� help board�C

long);
        set("master", ({ CLUB_D->query_club_leader("god") }));
        setup();
        set("capacity", 99);
}

