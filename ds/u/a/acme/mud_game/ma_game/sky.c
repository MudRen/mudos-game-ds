#include <ansi.h>
#include <room.h>
//#define START_ROOM "/open/dragon_wine/inn_hall.c"       //At ��
#define START_ROOM "/open/world1/tmr/area/hotel.c"      //Ds ��

inherit ROOM;

int do_giveup();
void heart_beat();

void create()
{
        set("short", "�L�ɪ����");
        set("long", @LONG
�|�P�c�P�I�I�A�@��L�ڡA�}�U�@���ŵ�A�@�L���P�A�e
���@�D�y�P���L�A�즲�۪��������ڡA�ꬰ�a���W�S����������
�I�I��M�A�i�H���(giveup)�b��A�]�i�H�ش�(survey)���y
���Z���C
LONG
        );
        set("no_fight",1);
        set("no_recall",1);
        set_heart_beat(1);
        setup();
}
void init()
{
        add_action("do_giveup","giveup");
        add_action("do_survey","survey");
}

int do_giveup()
{
        message_vision(HIW"$N���F�X�y�u�}�F��}�F��v�H�Y���U�Y���I\n"NOR,this_player());
        this_player()->delete_temp("fly_speed");
        this_player()->delete_temp("fly_long");
        this_player()->delete_temp("fly_time");
        this_player()->move(START_ROOM);
        message_vision(HIW"$N�q�ѤW���F�U�ӡI�I\n"NOR,this_player());
        return 1;
}
int do_survey()
{
        if( this_player()->query_temp("fly_long") )
        {
                if( this_player()->query_temp("fly_long") > 0 )
                write("�A�񲴱�h�A�ش�����y�٦�"+chinese_number(this_player()->query_temp("fly_long"))+"�������Z���C\n");
                else write("�A�񲴱�h�A�ش�����y�٦�����@�������Z���C\n");
        }
        else return notify_fail("�A�èS���b�b��I\n");
        return 1;
}
void heart_beat()
{
        float j;
        int i;
        object *ppl;
        ppl=all_inventory(this_object());
        i=sizeof(ppl);
        while( i-- )
        {
                if( !ppl[i]->query_temp("fly_speed") )
                        continue;

                if( ppl[i]->query_temp("netdead") )
                {
                        message_vision(HIW"$N���F�X�y�u�}�F��}�F��v�H�Y���U�Y���I\n"NOR,ppl[i]);
                        ppl[i]->delete_temp("fly_speed");
                        ppl[i]->delete_temp("fly_long");
                        ppl[i]->delete_temp("fly_time");
                        ppl[i]->move(START_ROOM);
                        message_vision(HIW"$N�q�ѤW���F�U�ӡI�I\n"NOR,ppl[i]);
                }

                if( !ppl[i]->query_temp("fly_time") )
                {
                        j=100*ppl[i]->query_temp("fly_long")/ppl[i]->query_temp("fly_speed");
                        ppl[i]->add_temp("fly_time",j/(float)100.00);

                }

                if( ppl[i]->query_temp("fly_long") <= 0 )
                {
                        ppl[i]->delete_temp("fly_speed");
                        ppl[i]->delete_temp("fly_long");
                        ppl[i]->move(__DIR__"moon");
                }

                ppl[i]->add_temp("fly_long", -ppl[i]->query_temp("fly_speed"));
        }
}
