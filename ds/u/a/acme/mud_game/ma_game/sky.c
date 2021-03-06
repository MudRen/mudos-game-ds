#include <ansi.h>
#include <room.h>
//#define START_ROOM "/open/dragon_wine/inn_hall.c"       //At 用
#define START_ROOM "/open/world1/tmr/area/hotel.c"      //Ds 用

inherit ROOM;

int do_giveup();
void heart_beat();

void create()
{
        set("short", "無盡的虛空");
        set("long", @LONG
四周繁星點點，一望無際，腳下一片空虛，毫無踏實感，前
眼一道流星劃過，拖曳著長長的尾巴，實為地面上沒有的美景啊
！！當然你可以放棄(giveup)奔月，也可以目測(survey)到月球
的距離。
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
        message_vision(HIW"$N說了幾句「罷了∼罷了∼」隨即往下墜落！\n"NOR,this_player());
        this_player()->delete_temp("fly_speed");
        this_player()->delete_temp("fly_long");
        this_player()->delete_temp("fly_time");
        this_player()->move(START_ROOM);
        message_vision(HIW"$N從天上掉了下來！！\n"NOR,this_player());
        return 1;
}
int do_survey()
{
        if( this_player()->query_temp("fly_long") )
        {
                if( this_player()->query_temp("fly_long") > 0 )
                write("你放眼望去，目測離月球還有"+chinese_number(this_player()->query_temp("fly_long"))+"公里的距離。\n");
                else write("你放眼望去，目測離月球還有不到一公里的距離。\n");
        }
        else return notify_fail("你並沒有在奔月！\n");
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
                        message_vision(HIW"$N說了幾句「罷了∼罷了∼」隨即往下墜落！\n"NOR,ppl[i]);
                        ppl[i]->delete_temp("fly_speed");
                        ppl[i]->delete_temp("fly_long");
                        ppl[i]->delete_temp("fly_time");
                        ppl[i]->move(START_ROOM);
                        message_vision(HIW"$N從天上掉了下來！！\n"NOR,ppl[i]);
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
