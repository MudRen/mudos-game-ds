
inherit ROOM;

void create()
{
 set("short","�s���p�|");
        set("long",@LONG
�����b�A�}�U�F�F���T�A�A�����b�@�����R�p���W�C
LONG
        );

         set("exits", ([
         "southdown": __DIR__"hotel_f",
         "northeast": __DIR__"path_2",
         ]));
        
        set("outdoors","land");
        
        setup();
        replace_program(ROOM);

 }