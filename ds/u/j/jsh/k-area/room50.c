inherit ROOM;

void create()
{
        set("short", "�H�ۤl��");
        set("long", @LONG
�o�q���W���H�ۤl�ҳѵL�X�A�j�������Q�B���R�걼�F�A��Ӹ����ܦ����g
    �����A�X�ڤp��}���a���ۡC
LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"room51",
  "north" : __DIR__"room49",
  //"north" : __DIR__"room34",
  //"west" : __DIR__"room47",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

