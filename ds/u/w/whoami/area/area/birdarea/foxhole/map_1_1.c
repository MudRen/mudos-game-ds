inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "northwest" : __DIR__"map_0_0", 
        "southwest" : __DIR__"map_2_0",
        "northeast" : __DIR__"map_0_2",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

