
// �����s�ĥ|�h_���K

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�o�̬O�@���p�p���۶��A��A�q�t�@��½��L�ӮɡA�N�Pı��o��
�����t��áA�o�̥|�P���O���Y�A�i���O�@�ӤH�u�Ұ����@�ӥ۶��A��
�䪺��W�٦���ۨǹϧΡA���䦳�@�ӬW�l�A�W���w��ۤ@�����Y�A��
������γB�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
]));
        set("item_desc", ([
//  "�ϧ�" : "�@�ǩ_�Ǫ��ϧΡA�ݰ_�ӹ��O�@�تZ�\\���ˤl�A�A�i�H���եh�ǾǬݡC\n",
  "���Y" : "�o�O�@���Ϊ��_�Ǫ����Y�A���L�N�_�ӫo�O�H���I�믫���Ī��Pı�A�A�|�Q�n������(get)�C\n",
]));
        set("world", "past");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_get", "get");
}

int do_push(string arg)
{
        object me = this_player();

        if( arg != "�۾�" && arg != "stone" )
                return 0;
        message_vision(HIW"$N�ϫl���ʥ۾��A�u���۾��Ƿ����@�_�A��ӤH��½�F�L�h�C\n"NOR,me);
        me->move(__DIR__"hole8.c");
        tell_room(environment(me), "�u���۾��@�}�̰ʡA"+me->name()+"��M�X�{�b�o�̡I\n", ({ me }));
        me->start_busy(1);
        return 1;
}

/*int do_try(string arg)
{
        object me = this_player();
        if( !me->query("study_redblade") )
                return notify_fail("�A�ӵ۾��W�����A�h���A���G�S���⮩�줰��F��C\n");
        if( !present("tai-gei graph", me) )
                return notify_fail("�A�S��ν���Ϫ�A�ݤ������W�����F��D�D\n");
        if( me->query_skill("redblade") )
                return notify_fail("�A�w�g�|�����M�k�F�I\n");
        message_vision("$N�ӵۥ۾��W���ʧ@�̼˹���Ī�����F�_�ӡD�D\n", me);
        me->add("study_redblade",1);
        if( me->query("study_redblade") > 50 )
        {
                me->set_skill("redblade",1);
                tell_object(me, HIY"�A�⮩�F�����M�k���M�N�F�I\n"NOR);
        }
        return 1;
}*/

void close_get();
int do_get(string arg)
{
        object me = this_player(),
                  d_stone = new(__DIR__"npc/obj/d_stone.c");
        if( arg != "stone" && arg != "���Y" )
                return 0;
        if( query_temp("use_get") )
                return 0;
        message_vision(HIG"$N�q�W�W���U�F�@�����Y�I\n"NOR, me);
        d_stone->move(me);
        set_temp("use_get", 1);
        me->set_temp("got_stone",1);
        close_get( );
        return 1;
}

void close_get()
{
        set("long",@LONG
�o�̬O�@���p�p���۶��A��A�q�t�@��½��L�ӮɡA�N�Pı��o��
�����t��áA�o�̥|�P���O���Y�A�i���O�@�ӤH�u�Ұ����@�ӥ۶��A��
�䪺��W�٦���ۨǹϧΡA���䦳�@�ӬW�l�A�W���S������p�F��A��
������γB�C
LONG
        );
        delete("item_desc/���Y");
          call_out("delay", 600 + (600) );
        set_temp("use_get", 1);

}

void delay( )
{
        set("long", @LONG
�o�̬O�@���p�p���۶��A��A�q�t�@��½��L�ӮɡA�N�Pı��o��
�����t��áA�o�̥|�P���O���Y�A�i���O�@�ӤH�u�Ұ����@�ӥ۶��A��
�䪺��W�٦���ۨǹϧΡA���䦳�@�ӬW�l�A�W���w��ۤ@�����Y�A��
������γB�C
LONG
        );
        set("item_desc/���Y" ,"�o�O�@���Ϊ��_�Ǫ����Y�A���L�N�_�ӫo�O�H���I�믫���Ī��Pı�A�A�|�Q�n������(get)�C\n");
        delete_temp("use_get");
}

