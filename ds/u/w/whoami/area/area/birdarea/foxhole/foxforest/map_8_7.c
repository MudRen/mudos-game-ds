inherit ROOM;
void create()
{
        set("short", "���� ");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "southwest" : __DIR__"map_9_6",
        "southeast" : __DIR__"map_9_8",
        ]));
        set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

