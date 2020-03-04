#include <ansi.h>
#include <path.h>
inherit ITEM;
int do_move(int i);

void create()
{
        set_name("�¥@�ɹq��",({"old world dinkey","dinkey"}) );
        set("long",@long
�o�O�@�x�w���}�ª��p���q���A���¥@�ɴݯd�U�Ӫ������A���M�ĥ�
�ϯB��z�o�ʡA�s���¥@���q�ϩM�D�����¥@�ɦa�U�K���C���M�}�¡A��
���M�w���B�ֳt�A�]�O�q�u���O�o�_���B���u��C
long
);
        set_weight(999999);
        if(clonep() )
                set_default_object(__FILE__);
        else {
                set("no_sac",1);
                set("no_get",1);
                set("value",9999);
        }       
        setup();
        call_out("do_move",60,1);
}

int do_move(int i)
{
        object temproom;
        temproom=find_object(__DIR__"dinkey_temproom");
        if(!environment(this_object() )) return 1;

        if(i==1)
        {
	tell_room(environment(),"�͹͹͡I�I�q���ֳt�����_�����A�H�J�o�ʶ}�V�D���C\n" );
          this_object()->move("/u/s/superbug/train/3");
        tell_room(environment(),"�@�x�q���C�C�a���a�b��x��.....\n");
        temproom->do_move(1);
        call_out("do_move",60,2);
        }
        else    {
	tell_room(environment(),"�͹͹͡I�I�q���ֳt�����_�����A�H�J�o�ʶ}�V�D���C\n" );
        this_object()->move(FUTURE+"tmr/basic/train_station1");
        tell_room(environment(),"�@�x�q���C�C�a���a�b��x��.....\n");
        temproom->do_move(2);
        call_out("do_move",60,1);
        }
        return 1;
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="dinkey")
                return 0;
        if(!me->query_temp("dinkey_ticket"))
        {
                tell_object(me,"�A�èS���R�����A�L�k�i�h�q���C\n");
                return 1;
        }

        me->move(__DIR__"dinkey_temproom");
        message_vision("$N�q�q���}�Ҫ��������F�i�ӡC\n",me);
        me->delete_temp("dinkey_ticket");
        return 1;
}

