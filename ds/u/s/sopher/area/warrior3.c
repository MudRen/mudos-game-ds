#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"�W�s�x�βĤ@�����x�ȳB"NOR);
        set ("long", @LONG
�o�̬O�x�ȳB�A�諸�p�s�������A�����@�a�C�A���
�ɬO�Ѭ[�M���d�A�̭��]�˺��F���A�A���e�o��x�ȩx�A
�A���T�}�l�P���L�F....:P
LONG);  
        set("no_fight",1);
        set("no_spells",1);
        set("no_magic",1);
        set("exits", ([
        "east": __DIR__"warrior2",
        "north":__DIR__"lightning",
        "south":__DIR__"ice",
        "west": __DIR__"fire",
         ]) );
        set("objects", ([
        __DIR__"npc/guard3" : 1,
        __DIR__"npc/knight" :2,
        ]) );
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "sign": "
          ��:���s�M�Υ���
          �_:�p�s�M�Υ���
          �n:�B�s�M�Υ���
          ", ]) );
        setup();
        replace_program(ROOM);
}
