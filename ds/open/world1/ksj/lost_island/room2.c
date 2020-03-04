#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��  "HIG"�~��"NOR);
        set("long", @LONG
�o�̬O�@��L�ڪ��j���A�����ν����C�A����A�٦��\�h����
�W�����Ӫ��A���W���R�ۤC�m�����M�_�������ΡA�����i�H�ݨ�
�øV���~�b��줤�b�]�V���A�񲴱�h���L�H�ϡA�k�M�O�ʪ����@�~
�緽�A�n���O�@���~�k�������C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room3",
  "north" : __DIR__"room6",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("item_desc", ([
        "����" : "�����ƤV���@�������A�~�k����ơC\n",
        ]));

        setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me=this_player();        
        if(arg!="����") 
                return notify_fail("�A�Q�n��(jump)�L����H");
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�L�k�M�����I���ʧ@�C\n");
        if(me->query_skill("dodge",2) <60)
                return notify_fail("�A�L�k�w���a���L�h�C\n" );
        if(!me->move(__DIR__"room1") )
                return notify_fail("�A�L�k���L�ʤf�C\n");
  tell_room(me,HIW"$N����@�D�ӤW�A�������򩥾��A�X���ɤO�ᨭ�v�����b�������t�@��C\n"NOR,me);

        return 1;
}
