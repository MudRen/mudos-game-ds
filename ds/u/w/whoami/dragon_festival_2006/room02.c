
inherit ROOM;
#include <ansi.h>
void create()

{
        set("short", WHT"�Qù����"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    ���B�i�����}��ۨI���Qù���C�����R�R�a�y�g�@���o�񪺯�W�A
�����٦��X�Ӫ�������C�L�����A�ϩ��i�Hť�켫�n���d��G�u������
��A�˰y�p��A���H���i�A��h�L�W�C�v�@�Ǫ��W���F���m�E�q�n�̪�
�@������g���ܦb�A�����D�ʡC

LONG
        );
    set("exits",([
 "south" : __DIR__"room03",
 "enter" : __DIR__"room01",
]));
        set("objects", ([ 
  __DIR__"npc02" : 1,
]));
        set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}
