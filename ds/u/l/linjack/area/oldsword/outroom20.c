#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o�@����W�ٺ⺡�j��, �A���_���h�N��s���}�U�F,
�A�i�H�ݨ���񦳨Ǥp�ʪ��X�S. �A�q�o�̬ݤs��, ���G
�������i�H�ݨ�s���W���g�@�Ǥj�r.
LONG
    );
 set("exits",([ "southup":__DIR__"inroom19",
                "north":__DIR__"outroom21",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
