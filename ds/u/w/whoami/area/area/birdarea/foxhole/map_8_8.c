inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG

LONG
);
        set("exits",([
        "north" : __DIR__"map_7_8",
        "west" : __DIR__"map_8_7",
        "southeast" : __DIR__"map_9_9",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

