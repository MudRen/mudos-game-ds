// caochang.c ���
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�o�@�ګ��ħJ�H�j���w�g�ߺD�F�w�~�ͬ��A��O���F�Ӥj����C�K�L
�⻷�B�ι઺����ΤU�Ӱ�b�o�̡A�H�Ƭ�V�u�`�b�ͪ����ơC�o�̰ﺡ
�F�@���b�O�j�p�����M�F��(gancao)�A�ݰ_�Ӥ��U�d��C
LONG);
        set("exits", ([
//            "northdown" : __DIR__"pmchang",
//            "westdown" : __DIR__"shuijing",            
            "southeast" : __DIR__"pmchang",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1
        ]));
        set("item_desc", ([
                "gancao" : 
            "�o�O��n�b����z�����A�a�W�ٹs�s�����a��F�n�h�w�g�ηF������C�A�i�H���U�����̧�F��令��C\n",
        ])); 
        set("outdoors", "land");
        setup();
        replace_program(ROOM);

}
