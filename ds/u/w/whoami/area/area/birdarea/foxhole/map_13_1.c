inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "southwest" : __DIR__"map_14_0", 
        "southeast" : __DIR__"map_14_2",
        "northwest" : __DIR__"map_12_0",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

