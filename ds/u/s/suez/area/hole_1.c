#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short","�}���p��");
        set("long",@LONG
�@�����t���o�O�M�@�i�}�ª����A�n�����O�����ӱ���A���y�W�A
�����q����]�i�Ӫ��B��b�a�𪺮Ѭ[�W�O�O���s�A��T�i�p����ê��\
�ۡA���۳o�̪��\�]�ݤU�h�A���M�o�{�A���}�U�����@�Ӥj�۪��T���W��
��Ӥj�K���R�R�{ģ�ۨ����������A�n���D���۪��U�������ΦM���A��M
�@�}�H���j�J�A���A���T�򰩮��M�C
LONG
        );

         set("exits", ([
  "south": __DIR__"hole_out",
  "down":__DIR__"hole_2",
]));

        set("objects",([
          __DIR__"npc/pan-en" : 1,
]));
        set("light", 1);
        setup();
          create_door("down","�۪�","up",DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        object obj = this_object(), pan = present("pan-en", this_object());
        if( !objectp(pan) || !pan->visible(me) )
        {
                me->delete_temp("pan-en");
                return ::valid_leave(me, dir);
        }
        if( (dir=="down") && obj->query_temp("pan-en") > 0 && pan )
        {
                write("��^�j��@�i�A�צ�A���h���C\n");
                return 1;
        }
        else if( (dir=="down") && objectp(pan) )
        {
                message_vision("$N���R�ͦ��T�a�A���i�L�X�A�֧����h�I\n", pan);
                call_out("kill_1", 7, me, this_object(), pan);
                me->set_temp("pan-en", 1);
        }
        else if( (dir=="down") && !objectp(pan) )
        {
                return ::valid_leave(me, dir);
        }
        else return ::valid_leave(me, dir);
}

void kill_1(object me, object obj, object pan)
{
        if( !me )return;
        if( !objectp(environment(me)) ) return;
        if( environment(me)!=obj ) return;
        else
        {
                message_vision("$N���R�٤��t���I���Ǧb�U�⤤�L�b�I\n", pan);
                call_out("kill_2", 7 , me, obj, pan);
        }
        return;
}

void kill_2(object me, object obj, object pan)
{
        if( !me ) return;
        if( !objectp(environment(me)) ) return;
        if( environment(me)!=obj ) return;
        else
        {
                message_vision("$N���R�A�Tĵ�i�٤����h�I�O�ݻ���Y�_�I\n", pan);
                call_out("kill_3", 7 , me, obj, pan);
        }
        return;
}

void kill_3(object me, object obj, object pan)
{
        if( !me )return;
        if( !objectp(environment(me)) ) return;
        if( environment(me)!=obj ) return;
        if( environment(me)==obj )
        {
                message_vision("$N���R�d�s���h�Iĵ�i��ť�I���������ϡI\n", pan);
                pan->kill_ob(me);
                return;
        }
//      this_object()->delete_temp("pan-en");
}
