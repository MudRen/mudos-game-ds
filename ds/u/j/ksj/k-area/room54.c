inherit ROOM;

void create()
{
        set("short", "�D��");
        set("long", @LONG 
�o���D���������Υ۪O�Q���A�i�H�e�Ǩ�x�����æ�A���W���ɦ��Ӹ붤���
    �滰���A�����٦��_�Ǫ��H�e���䤤�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"northeast" : __DIR__"room54",
  "east" : __DIR__"room55",
  //"north" : __DIR__"room34",
  "southwest" : __DIR__"room53",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

