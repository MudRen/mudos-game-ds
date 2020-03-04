#include <ansi.h>
#include <room.h>
//#define START_ROOM "/open/dragon_wine/inn_hall.c"     //At ��
#define START_ROOM "/open/world1/tmr/area/hotel.c"        //Ds ��

inherit F_SAVE;
inherit ROOM;
mapping game_record;
mapping game_no;

int do_del(string arg);
int do_leave();
int do_list();
int do_sign();
float sort_list(string ob1, string ob2);

void create()
{
        seteuid(getuid()); 
        set("short", "��c[��y]");
        set("long", @LONG
�@��L�ڪ���y�A�|�g�|�|�}�}���A�Q����D�A����Ǩӡu�ء�
�ء�v���n�A���ӬO�d��b��۾�a�A���S�ǨӰ}�}�u�N�N��v�n
�A�]�\�O�ɨߦb�o�ġA���e�@���¦�j�ۡA�W�Y��۳\�h�K�K�³ª�
�r�C��M�A�]�i�H���}(leave)�o�̡C
LONG
        );
//        set("detail", ([      // At ��
        set("item_desc", ([     // Ds ��
                "�¦�j��" : "�A�i�H�b�W����U(sign)�ۤw�������A�]�i�H�[�ݬ���(list)�C\n",
        ]));
        set("no_fight",1);
        set("no_recall",1);
        setup();
        if( !restore() )
        {
                game_record=([]);
                game_no=([]);
                this_object()->save();
        }
}

void init()
{
        add_action("do_list","list");
        add_action("do_sign","sign");
        add_action("do_leave","leave");
        add_action("do_del","del");
}

int do_del(string arg)
{
        if( wiz_level(getuid(this_player())) < wiz_level("(arch)") )
                return 0;
        if( !arg ) return notify_fail("�A�Q�R���֪��O���H\n");

        if( undefinedp(game_record[arg]) && arg!="-a" )
                return notify_fail("�o�ӤH�èS���b������@�I\n");

        if( arg=="-a")
                write("�A�T�w�n�R���������b������ܡH(y/n)");
        else write("�A�T�w�n�R��["+arg+"]���b������ܡH(y/n)");
        
        input_to("check_del", arg);

        return 1;
}

private void check_del(string check,string arg)
{
        if( check != "y" && check !="Y" )
        {
                write("�����R���I\n");
                return;
        }
        if( arg== "-a" )
        {
                write("�A�N�������b������R���F�I\n");
                game_record=([]);
                game_no=([]);
        }
        else
        {
                write("�A�N["+arg+"]���b������R���F�I\n");
                map_delete(game_record,arg);
                map_delete(game_no,arg);
        }
        this_object()->save();
        return;
}

int do_leave()
{
        message_vision(HIW"$N���F�@�y�u�}�F�㯫�P�������٬O�^�h��Z�ҫU�l�a��v�H�Y���U�Y���I\n"NOR,this_player());
        this_player()->delete_temp("fly_speed");
        this_player()->delete_temp("fly_long");
        this_player()->delete_temp("fly_time");
        this_player()->move(START_ROOM);
        message_vision(HIW"$N�q�ѤW���F�U�ӡI�I\n"NOR,this_player());
        return 1;
}

int do_list()
{
        float *speed,swap;
        int i,j,x;
        string *ppl,msg,user;
        if( !mapp(game_record) ) return notify_fail("�ثe�٨S����������I\n");
        ppl=keys(game_record);
        speed=values(game_record);

        i=sizeof(speed);

        for(j=i-1;j>0;j--)
        {
                for(x=1;x<=j;x++)
                {
                        if( speed[x-1] < speed[x] )
                        {
                                swap=speed[x-1];
                                speed[x-1]=speed[x];
                                speed[x]=swap;
                                user=ppl[x-1];
                                ppl[x-1]=ppl[x];
                                ppl[x]=user;
                        }
                }
        }
        i=sizeof(ppl);
        j=1;
        msg ="\t\t\t  ������b�묡�ʡ�\n";
        msg+="======================================================================\n";
        while( i-- )
        {
                if( i<sizeof(ppl)-1 )
                        if( game_record[ppl[i]] != game_record[ppl[i+1]] )
                                j++;

                  if( j <= 3 ) {
                          msg+=HIC;
                  } else if( j <= 10 ) {
                          msg+=HIY;
                  } else msg+=YEL;


                  if( ppl[i]==getuid(this_player()) ) msg+= HIW;

                msg+=sprintf("��%3d�W ---- %13s �@��%10.3f��",
                        j,ppl[i],game_record[ppl[i]]);

                if(i==0) {
                        msg+= HIC"  (save eq�@��)\n"NOR;


                } else {
                        switch( j )
                        {
                                  case 1: msg+= HIC"  (�ۭqsave eq�@��)\n"NOR; break;
                                   case 2..3: msg+= HIC"  (save eq�@��)\n"NOR; break;
                                  case 4..10: msg+= HIB"  (doll�@��)\n"NOR; break;
                                  default: msg+=CYN"  (�ѥ[��)\n"NOR; break;

                        }
                }
        

                msg+=NOR;
        }       
        msg+="======================================================================\n";
//          msg+="���G���ʵ�����A�e���W�̽Ь� �y�v(Acme) ������~�K\n";
//          msg+="    �䥦����߮Z�n�ѥ[���a..:D~\n";

        this_player()->start_more(msg);
        return 1;
}

int do_sign()
{
        string id;
        object me=this_player();
        id=getuid(me);
        if( !mapp(game_record) ) game_record=([]);
        if( !me->query_temp("fly_time") )
                return notify_fail("�A�èS���b��t�סI\n");
        if( !undefinedp(game_record[id]) )
        {
                write("�A���¬�����["+game_record[id]+"]��A�o�����t�׬�["+me->query_temp("fly_time")+"]�A�T�w�n��s�����ܡH(y/n)");
                input_to("check_sign");
                return 1;
        }
        write("�A�b�¦�j�ۤW��U�F�ۤw���j�W�M�b��t�סI\n");
        game_record[id]=me->query_temp("fly_time");
        me->delete_temp("fly_time");
        this_object()->save();
        return 1;
}

private void check_sign(string check)
{
        object me=this_player();
        if( check!="y" && check!="Y" )
        {
                write("������s�����C\n");
                return;
        }
        game_record[getuid(me)]=me->query_temp("fly_time");
        me->delete_temp("fly_time");
        write("�A�b�¦�j�ۤW��U�F�ۤw���j�W�M�b��t�סI\n");
        this_object()->save();
}
string query_save_file() { return DATA_DIR + "game/ma_game"; }

