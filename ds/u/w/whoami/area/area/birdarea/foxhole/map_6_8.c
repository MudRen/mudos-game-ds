inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "northeast" : __DIR__"map_5_9",
        "south" : __DIR__"map_7_8",
        "west" : __DIR__"map_6_7",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

