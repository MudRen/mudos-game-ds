#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "�B�F���F�j��");
        set("long",@LONG
�A���b�@���u�p����D�W�A��F�o�̦��G�N�O�������I�A�b�F�䦳
�\�h���ª��ЫΡA�ڻ��O�q�e�Y�Ӭ@�ϥ������^���Ҹ����a�A�]���ᬰ
�H�̴L�q�C
LONG
        );
        set("exits", ([
            "west" : __DIR__"beast1.c",
            "east" : __DIR__"beast3.c",
            "north" : "open/world1/ksj/thief/room1.c",
           ]));

        set("no_clean_up", 0);
        set("outdoors","land");
        set("objects",([
            __DIR__"npc/dove":4,
           ]) );
        create_door("north","�K��","south",DOOR_CLOSED);
        setup();
}
