// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "�P��");
        set("long", "�@�Ӭ۷������b���P�ǡA����ն��B�@�I�]�夣�X��i����^�C\n");
        set("exits", ([
            "west" : __DIR__"big2room",
        ]));
        set("objects", ([
            "/obj/big2.c" : 1,
         ])); 
 set("item_desc", ([
 "��" : "����",
 ]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

