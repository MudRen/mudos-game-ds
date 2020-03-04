// Room: /d/gumu/lingshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"�F��"NOR);
        set("long", @LONG
�u���Ū��m�m���@�y�j�U�W�}�C��ۤ���۴áC�����ӬݡA�����
�۴ôû\�w�K�K�\�ۡA��ӬO�j�Ӭ����v�L�­^�M�p�s�k�v�Ū��w����
�B�C�t�~�G�㪺�û\(coffin)�o�u���W�@�b�A�]�����䤤���L�r��C
LONG    );

        set("exits", ([ 
                "out" : __DIR__"shishi5",
        ]));
        
                set("item_desc", ([
                           "coffin" : "�p�����û\\�A�����G�i�H������(push)�C\n",
         ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_tui", "push");      
        add_action("do_tang","lie");
}

int do_tui(string arg)
{
        object me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if ( arg =="coffin")
        {
                        message_vision(YEL"$N�ϫl���}�F�û\\�A�۴ä��n���i�H���H(lie)�C\n"NOR,me);
                me->set_temp("marks/�۴�", 1);
                return 1;
        }
        return notify_fail("�A�n������H\n");
}

int do_tang(string arg)
{
        object me=this_player();       

        if (!me->query_temp("marks/�۴�")) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        
        if ( arg =="coffin")
        {
                me->delete_temp("marks/�۴�");
                me->move(__DIR__"shiguan");
                message_vision(HIY"$N���i�F�۴áA�ä��w�L�఼�l�a�C\n"NOR,me);
                return 1;
        }
        return notify_fail("�A�Q���b�����H\n");
}

