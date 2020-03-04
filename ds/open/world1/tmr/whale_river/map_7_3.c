// File: /d/whale_river/map_7_3.c
// Updated by tmr (Tue Feb 26 04:50:11 2002)

#include <ansi.h>
inherit ROOM;

void create()
{
          set("short", "�e��");
          set("long", @LONG
�A���b�e����A�������h�O�@�������Ū��j��A���s�n�R���թ�
�A���s���ण�ɱ�X�����A�n�O���W���ڳ���A�ˤ]�Q�b�o��ɨ�
����(fishing) �����R�Cť���񪺳��Ȼ��ӡA���G�o���a��O���
�̱`�X�S���a��C
LONG
          );
        set("map_long", 1);
        set("exits", ([ /* 1 element(s) */
                "east" : __DIR__"map_7_4",
        ]));
        set("objects",([
                __DIR__"npc/fisher":2,
        __DIR__"npc/obj/rod":1,
        ]));

        set("outdoors", "forest");

        setup();
}

void init()
{
        add_action("do_fishing","fishing");
}

int do_fishing(string arg)
{
        object me,rob;
        string type;
        
        me=this_player();
        rob = present("_OBJECT_ROD_", me);      // �P�_���W�O�_����
        if( me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S���ų����C\n");
        if( !rob )  return  notify_fail("�A�èS������A�����p�󳨳��C\n");
        if( !(type = rob->query("equipped")) )
                                return notify_fail("�A�����⳨�񮳦b��̡A�~�೨���C\n");
        if( me->query_temp("whale_river/is_fishing") )
                                return notify_fail("�A�w�g�b�����F�C\n");
        if( me->query_stat("gin") < 10)
                                return notify_fail("�A���믫���p���n�A�L�k�M�߳����C\n");
        me->set_temp("whale_river/is_fishing",1);
        switch(random(3))
        {
        case 0:
                message_vision("$N�ΤO�⳨�u�Ϩ�򤤥��A�@���ѧ��b����A�}�l���۳��W�_...\n",me);
                break;
        case 1:
                message_vision("$N�H��q�a�W��F�X���L�C������A�@�ϳ��u��򤤥h�A�}�l���_����...\n",me);
                break;
        default:
                message_vision("$N�⳨�u�z�F�z�A�j�W�F�X���C�Y�h�A�H�Y�ϤF�X�h�A�}�l���_����...\n",me);
                break;
        }
        // �i�J���� function
        call_out("fishing_2",3+random(3),me);
        return 1;
}

void fishing_2(object me)
{
        object fish;
        /* ���⤣�s�b or �D�������A */
        if(!me || !me->query_temp("whale_river/is_fishing") 
           || environment(me)!= this_object()       )

        {
                me->delete_temp("whale_river/is_fishing");
                return;
        }
        /* ���⦣�L�� or ����԰��� */
        if(me->is_busy() || me->is_fighting() )
        {
                message_vision("$N�����ۤ��o�}��A�u�n��󳨳����ʧ@�F�C\n",me);
                me->delete_temp("whale_river/is_fishing");
                return;
        }
        switch(me->query_temp("whale_river/is_fishing") )
        {
        case 1:         /*      ������        */
                switch(random(3) )
                {
                case 0:
                        message_vision("$N�r�ۤ@�ӡu���I�Y�v�A��ӬO�������쥴�ߺΤF....\n",me);
                        break;
                case 1:
                        message_vision("$N���_���ӰʤF�X�U��}�A�S���b����A�}�l���_����....\n",me);
                        break;
                default:
                        message_vision("$N�o�X�@�}���q���s�A�ݨӬO�����W�_���ۤ��@�ФF....\n",me);
                        break;
                }
                me->add_temp("whale_river/is_fishing",1);
                call_out("fishing_2",3+random(3),me);
                break;
        case 2: // ���� or Not ?
                if(random(100) > 70) {
                        switch(random(3))
                        {
                        case 0:
                                message_vision("$N�@���W������A�~�o�{����w�g�Q�Y�����F...\n",me);
                                break;
                        case 1:
                                message_vision("$N���^�F���u�A���G�@�������S������...\n",me);
                                break;
                        default:
                                message_vision("$N��榣�������^���u�A���G����@�}�ä�A�k��h�F...\n",me);
                                break;
                        }
                
                } else 
                {
                          if( random(100)>10 ) 
                        {
                                message_vision("$N�⤤�����u�@��A��ӬO����W���F�I�I\n",me);
                                fish=new(__DIR__"fishs/fish");
                                message_vision("$N�n��H�v�C�C�ۦ��^���u�A�᳨̫�W�@��$n�F...\n",me,fish);
                                if(!fish->move(me))
                                     fish->move(environment(me));
                        } else  {
                        /* ������  */
                                 // �w�g����ǤF�A�N���ΦA�X�{�F�C
                                if( objectp(fish=present("_NPC_ID_HELATIESI_") ) )
                                        message_vision("$N���^�F���u�A���G�@�������S������...\n",me);
                                else {
                                        fish=new(__DIR__"npc/helatiesi.c");
                                        fish->move(environment(me));
                                        message_vision(HIM "���M�򭱿E�_�@�}�j�P���i���A�@�����j���ͪ����W�F����I�I\n" NOR,me);
                                }
                        }

                }
                me->delete_temp("whale_river/is_fishing");
        break;  
        }
}

int valid_leave(object ob)
{
        /*      �������}�A�M�������O��  */
        ob->delete_temp("whale_river/is_fishing");
    return 1;
}

