#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", HIG"�g�A�˪L"NOR);
        set ("long", @LONG

                  ��    ��    ��    ��    ��    ��    ��
  �i�g�A�˪L�j    �� �� �� �� �� �� �� �� �� �� �� �� ��
                  �� �� �� �� �� �� �� �� �� �� �� �� ��
�A�Ө�@���p�p���K�ǡA�q�n���Ѧ��B�ǨӡA���V
�|�P��F��G�@�j����o�o���Ӫ��A²���N���m�����
�L�몺�֬��A�A�g�����l�۪�h��ɨ��j�۵M���ֽ�A
�A�e����M�X�{�F�@�ӤH�v....�O�@��....�k��???
LONG);   
        set("light",1);
        set("exits", ([
        "south": __DIR__"flower_room",
         ]) );
        set("objects", ([
        __DIR__"npc/sfuna" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}

