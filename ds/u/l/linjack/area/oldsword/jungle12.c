#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�A�Ө즹�B, �N�oı�Ʊ����I���j��F, �o��w�g�y�L���G
�F�@�I, ���O�A���e��|�B�����ǷL���~���s�n, �O�A�o�M����
�_�F�@���߷N.
LONG
    );
 set("exits",([ "northeast":__DIR__"jungle13",
                "southeast":__DIR__"jungle11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}