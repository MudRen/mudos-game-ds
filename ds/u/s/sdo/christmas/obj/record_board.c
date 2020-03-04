/*2001�t�ϸ`����--�ﳷ�H�����ƬݪO                          */
/*���alickyuen@DS������`�S�O���ʡy�O���v�v�z���ƱƦ�]    */
/*                                                sdo@DS    */
#include <ansi2.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;
mapping game_gift;
int reset_record();
string do_list();

int measure(object me);
int receive_gift(object me);

void create()
{
        set_name(HIW"�ﳷ�H���ʱƦW��"NOR,({"record board","board"}) );
        set("long","  ");
        set_weight(200000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
        if( !restore() ) 
        {
        	game_record=([]);
        	game_gift=([]);
        }
}
string query_save_file() 
{
        return DATA_DIR+"game/sdo_snowman";
}
void init()
{
        object me = this_player();

        if( !me ) return;
        if( !userp(me) ) return;
        
        add_action("do_look", "look");
}
int do_look(string arg)
{
        if ( arg == "board" )
        {
                return write(do_list());
        }
}
string do_list()
{
        float *score, swap;
        int i, j, x;
        string *ppl, msg, user;

	if( !restore() )  game_record=([]);
        if( !game_record ) return "�ثe�٨S����������I\n";
        if( !mapp(game_record) ) return "�ثe�٨S����������I\n";

        ppl=keys(game_record);
        score=values(game_record);

        i=sizeof(score);

        for(j=i-1;j>0;j--)
        {
                for(x=1;x<=j;x++)
                {
                        if( score[x-1] > score[x] )
                        {
                                swap=score[x-1];
                                score[x-1]=score[x];
                                score[x]=swap;
                                user=ppl[x-1];
                                ppl[x-1]=ppl[x];
                                ppl[x]=user;
                        }
                }
        }
        i=sizeof(ppl);
        j=0;
        msg= HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        msg += HIG"\t\t\t�ﳷ�H�j�ɰ���Ʀ�]\n";
        msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        while( i-- )
        {
                j++;

                if( ppl[i]==getuid(this_player()) ) msg+= HIC;
                        else msg += CYN;

                if( game_record[ppl[i]] > 0 ) {
                        msg+=sprintf("��%4s�W ---- %13s �ثe���� %3f ����",
                                chinese_number(j),ppl[i],game_record[ppl[i]]);

                        switch( j )
                        {
                                case 1: msg+= HIM""BLINK" (�W�Ťj���G�W�W�H�󡮦ۭq Save Eq �@��)\n"; break;
                                case 2..5: msg+= HIY" (�j���G�H�� Save Eq �@��)\n"; break;
                                default: msg+= HIR" (�ѥ[���G���BExp)\n"; break;
                                }
                }

                msg+=NOR;
        }       
        msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

        return msg;
}
int measure(object me)
{
	int roll1,roll2,comp1,comp2;
	float temp,high,temp1,temp2;
	string id;
	id=getuid(me);
	
	if( !restore() ) game_record=([]);
	
	if( !mapp(game_record) ) game_record=([]);
	
        temp=game_record[id];
        
        roll1=me->query_temp("sdogame/roll1");
	roll2=me->query_temp("sdogame/roll2");
	comp1=me->query_temp("sdogame/comp1");
	comp2=me->query_temp("sdogame/comp2");
		
	me->delete_temp("sdogame/roll1");
	me->delete_temp("sdogame/roll2");
	me->delete_temp("sdogame/comp1");
	me->delete_temp("sdogame/comp2");
	me->delete_temp("sdogame/build");
	
	temp1=sqrt(((roll1+1)/2))*2.5 - log(comp1+1);
	temp2=sqrt(((roll2+1)/2))*2.5 - log(comp2+1);
	high=(temp1+temp2)*2;
/*	
	if(high < 0)
	{
		high=0;
	}
*/	
	me->set_temp("sdogame/high",high);
	
	if (!me) return 0;
	tell_object(me,
	HIW"\n\n�@�Ӥu�@�H���L�n�L�����ۦ��Z�n�O���X�{�b�A����I\n"NOR
	HIW"�L�q���W���X�F�@���֤ءA�J�Ӫ��q�F�q�A�����H�A���G�y�o�ӳ��H�����׬O"+high+"�����I�z\n"
	HIW"��A���۴N�����F�I\n\n"NOR,high);

	if ( me->query_temp("sdogame/high") >= temp )
	{
        	game_record[id]=me->query_temp("sdogame/high");
        }
        this_object()->save();
	this_object()->create();
        return 1;
}
int reset_record()
{
        game_record=([]);
        this_object()->save();

        write("�n���w�g�M���I\n");

        return 1;
}
int receive_gift(object me)
{
	object gift;
	string id;
	id=getuid(me);
	
	if( !restore() ) 
	{
		game_gift=([]);
		game_record=([]);
	}
	if( !mapp(game_gift) ) 
	{
		game_gift=([]);
		game_record=([]);
	}
	
	if (!me) return 0;
	if (game_gift[id]==1) return notify_fail("�A�w�g��L§���F��I\n");
	
	me->add("exp",to_int(game_record[id]*50000));
        tell_object(me,"�A�o��"+to_int(game_record[id]*50000)+"�I�g��ȡI\n");
        
    	game_gift[id]=1;
        this_object()->save();
        this_object()->create();
        return 1;
}