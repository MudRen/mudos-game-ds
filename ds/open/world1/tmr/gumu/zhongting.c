// Room: /d/gumu/zhongting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "���U");
        set("long", @LONG
�o�B�O�j�Ӭ��̤l�Ѩ��x�����B�A����j�ӶǤH�p�s�k�ί��J�j�L
���L���w�W�|����A�o���z�H�����Z�\�w���@���v�v�A��H�ڧӤ�����
�`����O�@�H�ɼ}���w�C�U���u�@�i����A���۴ȡC
    �U�W�観�@�����B(board).
LONG    );
        set("exits", ([
                "east"  : __DIR__"mudao06",
          "west"  : __DIR__"mudao05_e",
                "south" : __DIR__"mudao08",
                "north" : __DIR__"mudao17",
        ])); 
        set("item_desc", ([
                "board" :  HIR"
             ��������������������������������
             �����@                      ����
             ����    �������� �ѯ�a��   ����
             ����                        ����
             ��������������������������������\n"NOR
       "�A�@���Y�j�@�����B�A���Y���G�٦��ǪŶ��A�A����O�_�n��(jump)�W�h�C\n",
        ]));
        setup();

}

void init()
{ 
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if (arg!="board")
                return notify_fail("�n���������H\n");
        message_vision(HIY"$N����u���A���ũް_�ƤV�A�������b���B����C\n"NOR,me);
        me->move(__DIR__"bianhou"); 
        return 1; 
}

