#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"��e���f"NOR);
        set ("long", @LONG
�o�̬O�ӤQ�r��e���f�A�����P�l�A�i��O����
(sign)�]�����w�C�_�䪺���y�Ӯc�V�ӶV��A�A����
�]�H�ۤ߱��_�񤣩w�C
LONG);  
        set("no_fight",1);
        set("no_spells",1);
        set("no_magic",1);
        set("exits", ([
        "south": __DIR__"dragon3",
        "north": __DIR__"dragon8",
        "west" : __DIR__"dragon9",
        "east" : __DIR__"dragon10",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "sign": "
                    �Ӯc
                     �x
                     �x
�W�s�Ĥ@�����w�X�X�X �� �X�X�X�X�X�W�s�ĤG����
                     �W
                     �W
                  �������j�D
          
        ", ]) );
        setup();
        replace_program(ROOM);
}
