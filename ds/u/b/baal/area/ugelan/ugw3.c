#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", RED"�վB��������u�ƶ��n��"NOR);
        set("long", @LONG
�A�Ө�F�@���j�q�E�A�o�̬O�վB�������u�ƶ������
�A��Q�i����h���׾Q��¶�۩ж��������@�i�j����b�o
�ж��̡A�����ɦ��G�٬O�Ū��A�����W���h��ê���ۤ@��
����ǡA�Ф��ߤ@���ө��Ӧ۶��W�@���I�U������C
LONG
        );
        set("exits", ([ 
                        "east": __DIR__"ugw2",
            ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        create_door("east","���","west",DOOR_CLOSED);

}

