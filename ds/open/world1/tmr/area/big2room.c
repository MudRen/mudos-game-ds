// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "�P��");
        set("long", "�@�Ӭ۷������b���P�ǡA����ն��B�@�I�]�夣�X��i����^�C\n");
        set("exits", ([
            "west" : __DIR__"inn_2f",
            "east" : __DIR__"big2room2", 
         ]));
        set("objects", ([
            "/obj/big2.c" : 1, 
            __DIR__"atm.c" : 1,   

      ]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

