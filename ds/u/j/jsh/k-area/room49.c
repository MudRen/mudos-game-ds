inherit ROOM;

void create()
{
        set("short", "�H�ۤl��");
        set("long", @LONG
�o�q�������ǬO�L�����g�C�A�g�C�W���@�ǧ|�}�A�i�঳����ʪ��~��a�A
    �����W�����ۤg�C�W�u�U�Ӫ��H�g���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room48",
  "south" : __DIR__"room50",
  //"north" : __DIR__"room34",
  //"west" : __DIR__"room47",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

