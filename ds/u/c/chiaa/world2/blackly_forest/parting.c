//u/c/chiaa/world2/blackly_forest/parting.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "�L�������p��");  
        set("long", @LONG
�u���p���󦹩��F�_�B�F�_�G��V,���F�G���Ӧ�,
�F�_��O���Ŧa!�ӪF�n��O���h�A��V�e�i,�����O�L��L������,
�ꤣ���n�����@�Ӥ�V�樫�~�n!!
LONG    
        );

        set("exits", ([ /* sizeof() == 3 */
          "northeast" : __DIR__"vacancy2",     //�L���Ŧa2
          "west"      : __DIR__"causeway1",    //�ۤl��1
          "southeast" : __DIR__"fen_road1",    //��h�p��1
     ]));
        setup();
replace_program(ROOM);
}
