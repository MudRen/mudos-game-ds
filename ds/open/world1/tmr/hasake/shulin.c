// shulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short",HIY"�s��"NOR);
       set("long", @LONG
��M�����A��_��X�{�F�@���s���A�s�W���a���A�b�������M�ݨ�A
�u�p����@�~�P�s�@��C�j����W�C���_��A�X�ӨF�C�N�o���s���B��F�A
�]�����B�����椣���C
LONG);
        set("exits", ([
                "west" : __DIR__"gebi2",
                "south" : __DIR__"gebi1",
                "east" : __DIR__"gebi4",
                "northwest" : __DIR__"shulin1",
        ]));
        set("outdoors", "land");
        setup();
       replace_program(ROOM);
}