inherit ROOM;

void create()
{
        set("short", "�T�s��x��B");
        set("long", @LONG
�o�̬O��²���f��p�b�סA�̭����\��ۦU�ض��ĥH���^
�a�����A���䯸�F�X����˪��x�H�A���b���ԭx�媺�s��C�Ů�
���H�H���į�����A���ǷP�줣�ΪA�C
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"camp004",
]));
        set("objects", ([
       __DIR__"mob/soldier_doctor" : 1,
                ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

