inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG

LONG
);
        set("exits",([
        "southeast" : __DIR__"map_14_14", 
        "northeast" : __DIR__"map_12_14",
        "southwest" : __DIR__"map_14_12",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

