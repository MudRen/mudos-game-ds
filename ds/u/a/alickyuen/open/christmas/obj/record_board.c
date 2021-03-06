/*2001聖誕節活動--堆雪人之分數看板                          */
/*改自alickyuen@DS的中秋節特別活動『燈謎競逐』分數排行榜    */
/*                                                sdo@DS    */
#include <ansi2.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;
int reset_record();
string do_list();

int measure(object me);

void create()
{
        set_name(HIW"堆雪人活動排名版"NOR,({"record board","board"}) );
        set("long","  ");
        set_weight(200000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
        if( !restore() ) game_record=([]);
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
//                return write(do_list());
// 可以換行比較好看... by -Acme-
                return this_player()->start_more(do_list());
        }
}
string do_list()
{
        float *score, swap;
        int i, j, x;
        string *ppl, msg, user;

	if( !restore() ) game_record = ([]);
        if( !game_record ) return "目前還沒有任何紀錄！\n";
        if( !mapp(game_record) ) return "目前還沒有任何紀錄！\n";

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
        msg += HIG"\t\t\t堆雪人大賽高手排行榜\n";
        msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        while( i-- )
        {
                j++;

                if( ppl[i]==getuid(this_player()) ) msg+= HIC;
                        else msg += CYN;

                if( game_record[ppl[i]] > 0 ) {
                        msg+=sprintf("第%4s名 ---- %13s 目前高度 %3f 公分",
                                chinese_number(j),ppl[i],game_record[ppl[i]]);

                        switch( j )
                        {
                                case 1: msg+= HIM""BLINK" (超級大獎：上名人堂＆自訂 Save Eq 一件)\n"; break;
                                case 2..5: msg+= HIY" (大獎：隨機 Save Eq 一件)\n"; break;
                                default: msg+= HIR" (參加獎：錢、Exp)\n"; break;
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
	me->set_temp("sdogame/high",high);
	
	if (!me) return 0;
	tell_object(me,
	HIW"\n\n一個工作人員無聲無息拿著成績登記本出現在你身邊！\n"NOR
	HIW"他從身上拿出了一條皮尺，仔細的量了量你的雪人，說：『這個雪人的高度是"+high+"公分！』\n"
	HIW"後，接著就消失了！\n\n"NOR,high);

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

        write("積分已經清除！\n");

        return 1;
}
int do_cheat(string id)
{
game_record[id] = 0;
	this_object()->save();
	write("ok!\n");
	return 1;
}
