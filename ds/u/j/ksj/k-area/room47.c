inherit ROOM;

void create()
{
        set("short", "�H�ۤl��");
        set("long", @LONG
����o�̵o�{���n���Y�p�F�A��ӬO��Ǫ���������F�@�Ǹ����A����
    ���_�@����g�A�W���������y������C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room46",
  //"southeast" : __DIR__"room47",
  //"north" : __DIR__"room34",
  "east" : __DIR__"room48",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

