#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"�վB�����w����j��"NOR);
        set("long", @LONG
���q�������¶�o�y�ѯ����ݪ������A����p�F��Q��
�ءA�O�q�����s�ߤU�H�]�k���O�}�Ħ۫p�F�⤽�����B�h��
�U�����۩Ҭ䦨�A�����h�O�H�����s�ߪ���}�ĦӨӪ��d�S
�i������(Giant Stone of Kartermoop)�һs���A�ڻ����W
��s�]�k�v�̪��k�N���L�k������z�C
LONG
        );
        set("exits", ([ 
            "east": __DIR__"wgate2",
            ]));
        set("light",1);
                        set("objects", ([
  __DIR__"npc/gguard" : 8,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

