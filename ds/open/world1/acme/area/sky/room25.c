// Room25.c

inherit ROOM;

void create()
{
        set("short","�Ѧa�|�|ĳ��");
        set("long", @LONG
�o�̬O�����A���O�Ѧa�|���ѭ̷|ĳ���a�A�ؤU�\�]����²��C
���B�]���G�i�O�A�q�`���|���U�j�p�ưȤ]�b�����i�A�H�������p��
���ΡC���_�i�H��F���������A���n�i�H��F�Ѧa�|�j���C

LONG
        );
        set("exits", ([
                "north": __DIR__"room15",
                 "west": __DIR__"room50",
                "south": __DIR__"room35",
                 "east": __DIR__"room60",
        ]));
        set("objects", ([
                __DIR__"item/axe1" : 1,
        ]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
        call_other( "/obj/board/sky_room25_b", "???" );
}

