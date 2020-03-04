// Room: /open/world1/tmr/goat_maze/stairway3.c

#include <ansi.h>
inherit ROOM;

void open_rain() {
        call_out("open_rain2", 60 + random(10) );
}

void open_rain2() {
        "/adm/daemons/event/pan_rain.c"->trigger_event();
}

void create()
{
        set("short", "�Ϩk���g�c - �a���s��");
        set("long", @LONG
�b����L���������Y��������A�A�Ө�F�a���s���C�o�O�@�y����
�Ϊ��j�s���A�j���i�H�P�ɮe�ǦʨӭӤH�A�b�s������������ߤ@�y��
�j���b�ϤH�۹��A�������~�A�N�A�]�S���䥦�_�Ǫ��F��A�A�]�䤣��
�O�_�٦��䥦�X�f�A�ݼˤl�n�^��a�W�A�ٱo�A���s�����Ʀʶ�������
�~��^�h�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"stairway3",
]));
        set("objects", ([
                __DIR__"npc/statue" : 1,
        ]) );
        set("current_light", 2);
        set("no_clean_up", 0);

        setup();
}



