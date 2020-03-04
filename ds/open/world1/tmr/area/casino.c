#include <ansi.h>

inherit ROOM;

string *gamble_msg = ({
  HIC+"���a��T����l�˦b�j�ظ�....\n"+NOR,
  HIC+"���a���_�F�j�ث�t���n�ʰ_�ӤF....\n"+NOR,
  HIC+"���a�j�۵�, �����}�l�F, �֤U�`��I�I\n"+NOR,
  HIC+"���a�j�۵�, �U�n����, �U�n����I�I\n"+NOR,  
  ""
});

string *bet_item = ({
});

string *dict = ({
        "�~�w�w�w��", 
        "�x      �x",
        "�x��    �x",
        "�x  ��  �x",
        "�x    ���x",
        "�x��  ���x",
        "���w�w�w��",
        "�x  "+HIR+"��"+NOR+"  �x",
});

string drawdict(int x,int y,int z);
int run_gamble(int stage);
int pay_gamble();

void create()
{
        set("short", "�Q��EĹ��{");
        set("long", @LONG
�o�O�@���D�`�ټM����{�A�Τ��\�]�F�E�i���A�ҳ򺡤F�H�A���a
�������q�A�B�u�|������u�}�F�X���p����A�Ů���o�Q���{�e�C�譱��
�W�K�F�i�ȱi�A�W�Y���G�g�ۤ@�ǳW�w�M��k�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "north" : __DIR__"wynd2",
          "south": __DIR__"mjroom",
        ]));
        set("item_desc",([
        "�ȱi" : @LONG
  �i�Q��EĹ��{�j

�U�`�G
	bet <���X||same> <�ƶq>
�d�ݡGcheck

����{�C�����Y�T�ɻ�l�A�i���N�U�`

	���㢵�����Ӹ��X(�߲v: �@�ߤ@)�C
	same �\�l(�߲v: �@�ߤT�Q)�C
LONG
        ]) );

	set("objects",([
		__DIR__"npc/ringman": 2,
	]) );

        set("no_clean_up", 0);
	set("no_fight",0);
        set("light",1);
        setup();
}

void setup()
{
        ::setup();
        call_out("run_gamble",15,0);
        return;
}

void init()
{
	  add_action("do_bet","bet");
	  add_action("do_check","check");
}

int run_gamble(int stage)
{
	if( stage < sizeof(gamble_msg) )
        {
	        tell_room(this_object(),gamble_msg[stage]);
	        stage += 1;

	        if(query("count") < 4 ) add("count",1); 
		else set("count",0);

	        call_out( "run_gamble",15,stage);
	}
	if( stage == sizeof(gamble_msg)-1) 
		call_out("pay_gamble",5);
        return 1;
}

int pay_gamble()
{
        object *inv;
         int i,x,y,z, money,flag;

        inv = all_inventory(this_object());

                       x = random(6)+1;
    		y = random(6)+1;
	       	z = random(6)+1;
			if ((x==y) && (y==z) && (z==x))
			{
        		x = random(6)+1;
        		y = random(6)+1;
	        	z = random(6)+1;
	        	if ((x==y) && (y==z) && (z==x))
				{
        			x = random(6)+1;
        			y = random(6)+1;
	        		z = random(6)+1;
				}
			}
	
        drawdict(x,y,z);
        tell_room(this_object(),"���a�ܹD�G�y�}�I�I "+x+"�B"+y+"�B"+z+"�I�I�z\n");
        tell_room(this_object(),drawdict(x,y,z));
        if(x==y && y==z) tell_room(this_object(),"���a���D�G�y��..�~�M�O�\\�l�I�I�ӺD�ҳ渹�߲v�[��...�z\n");
        flag = 0;

	for(i=0; i<sizeof(inv); i++) 
	{
            if( !inv[i]->query_temp("gamblebet") || 
	  (inv[i]->query_temp("gamblebet/1") + inv[i]->query_temp("gamblebet/2") +
               inv[i]->query_temp("gamblebet/3") + inv[i]->query_temp("gamblebet/4") +
               inv[i]->query_temp("gamblebet/5") + inv[i]->query_temp("gamblebet/6") +
               inv[i]->query_temp("gamblebet/7")
	    < 1 )  )  continue;
        money = 0;

	if(inv[i]->query_temp("gamblebet/"+x) > 0)
                money += inv[i]->query_temp("gamblebet/"+x)*2;
        if(inv[i]->query_temp("gamblebet/"+y) > 0)
                money += inv[i]->query_temp("gamblebet/"+y)*2;
        if(inv[i]->query_temp("gamblebet/"+z) > 0)
                money += inv[i]->query_temp("gamblebet/"+z)*2;        
        if( x == y && x == z )
        {
        	money *= 2;
        	if(inv[i]->query_temp("gamblebet/7") > 0)
        		money += inv[i]->query_temp("gamblebet/7")*30;
        }


        if( money > 0 ) 
	{
        flag = 1;

        if( x != y || x != z || y != z )
	{
	        if( inv[i]->query_temp("gamblebet/"+x) > 0 )
		        tell_room(this_object(),  "���a���D�G"+HIY "�u"+inv[i]->query("name")+"�㤤�F "+x+" ���I�v\n"+NOR);
	        if( inv[i]->query_temp("gamblebet/"+y) > 0 )
		        tell_room(this_object(),  "���a���D�G"+HIY "�u"+inv[i]->query("name")+"�㤤�F "+y+" ���I�v\n"+NOR);
	        if( inv[i]->query_temp("gamblebet/"+z) > 0 )
			tell_room(this_object(),  "���a���D�G"+HIY "�u" +inv[i]->query("name")+"�㤤�F "+z+" ���I�v\n"+NOR);
        } 
	else
	{
            if(inv[i]->query_temp("gamblebet/7"))
              tell_room(this_object(),
		 "���a�y��G�񪺻��D�G"HIW+"�u"+inv[i]->query("name")+"���F�T�P ["+x+"]�I�I�v\n"+NOR);
	}

         message_vision("$N����Ĺ�F"+money+"�T�j���I�I\n", inv[i] );
          inv[i]->add("bank/past", money);
	}
	 else
	{	
		 tell_object(inv[i],"�A�����b�t�F�C\n");
	         //�令BET�ɥI��    inv[i]->receive_money(-total);
	}
        inv[i]->delete_temp("gamblebet");
        inv[i]->delete_temp("gamblebet_count");
	}

        if( !flag )
		tell_room(this_object(),"���a�j�ۤ@�n�G�u�q���I�I�v�A���ⶡ�D�`�����C\n" );
	
        call_out("run_gamble",5,0);
}

int do_bet(string str)
{

        int number, amount, i,count;
          string *terms;
          object me;
        mapping bets;
        
        me = this_player();
        if( query("count") != 3) return notify_fail("�����٨S�}�l�C\n");
        if( !str ) return notify_fail("�Ϊk bet <���X|same> <�ƶq>\n");
        if( sscanf(str, "same %d ", amount)==1 )
        {
                number = 7;
        }
        else if( !str || sscanf(str, "%d %d", number, amount)==2)
        {
                if( !number || number > 6 || number < 1)
                        return notify_fail("�@�ɻ�l�����o�˪��I�ơH\n");
        } else return notify_fail("�Ϊk bet <���X|same> <�ƶq>\n");

         if( amount > 1000000)
                return notify_fail("����{�������o�ؤj��`�C\n");
        if( amount < 0 ) 
                return notify_fail("���r�r....�Ȩ⨺���t���X�C\n");
         if( amount > me->query("bank/past") ) 
                return notify_fail("�A�Ȧ檺�s�ڤ����C\n");

        bets = me->query_temp("gamblebet");
        count= me->query_temp("gamblebet_count"); //luky �����.. (������������P�@�ӴN�����bug.
        if (count>2)  return notify_fail("�A�@�������̦h�u�����T���C\n");
        if( me->query_temp("gamblebet") )
        {
                bets = me->query_temp("gamblebet");
                terms = keys(bets);
        }
        else
        {
                 for( i=0; i<sizeof(bet_item)+1; i++) 
                        me->set_temp("gamblebet/"+i, 0);
        }
      if(number!=7) 
        message_vision("$N�o���b"+number+"���U�`�F"+amount+"�T�j���C\n", me);
      else 
        message_vision("$N�o���b[�\\�l]�U�`�F"+amount+"�T�j���C\n", me);

        // �����λȦ榩��
        me->add("bank/past",-amount);
        me->add_temp("gamblebet_count",1);//luky
        me->add_temp("gamblebet/"+number,amount );
        return 1;
}


int do_check()
{
	object me;

	me=this_player();

	if( me->query_temp("gamblebet") )
	{
	tell_object(me,HIY "�A�ثe�U�`�����άO�G\n" NOR );
	
	if( me->query_temp("gamblebet/1") )
		tell_object(me,HIY "�i���j���G "+me->query_temp("gamblebet/1")+"�T�j��\n"NOR );
	if( me->query_temp("gamblebet/2") )
		tell_object(me,HIY "�i���j���G "+me->query_temp("gamblebet/2")+"�T�j��\n"NOR );
	if( me->query_temp("gamblebet/3") )
		tell_object(me,HIY "�i���j���G "+me->query_temp("gamblebet/3")+"�T�j��\n"NOR );
	if( me->query_temp("gamblebet/4") )
		tell_object(me,HIY "�i���j���G "+me->query_temp("gamblebet/4")+"�T�j��\n"NOR );
	if( me->query_temp("gamblebet/5") )
		tell_object(me,HIY "�i���j���G "+me->query_temp("gamblebet/5")+"�T�j��\n"NOR );
	if( me->query_temp("gamblebet/6") )
		tell_object(me,HIY "�i���j���G "+me->query_temp("gamblebet/6")+"�T�j��\n"NOR );
	if( me->query_temp("gamblebet/7") )
		tell_object(me,HIY "�i�\\�l�j�G "+me->query_temp("gamblebet/7")+"�T�j��\n"NOR );
	}
	else
		return notify_fail("�A�ثe�èS������U�`�C\n");
	return 1;	
}               

string paint1(int x)
{
   switch(x) {
                case 1 : return dict[1];
                case 2 : return dict[2];
                case 3 : return dict[4];
                case 4 : return dict[5];
                case 5 : return dict[5];
                case 6 : return dict[5];
                default : return dict[1];
        }               
}

string paint2(int x)
{
        switch(x) {
                case 1 : return dict[7];
                case 2 : return dict[1];
                case 3 : return dict[3];
                case 4 : return dict[1];
                case 5 : return dict[3];
                case 6 : return dict[5];
                default : return dict[1];
        }               
}
string paint3(int x)
{
        switch(x) {
                case 1 : return dict[1];
                case 2 : return dict[4];
                case 3 : return dict[2];
                case 4 : return dict[5];
                case 5 : return dict[5];
                case 6 : return dict[5];
                default : return dict[1];
        }               
}

string drawdict(int x,int y,int z)
{
        string dicts;
        
        dicts = "\n";
        dicts += "      "+dict[0]+"      "+dict[0]+"      "+dict[0]+"\n";
        dicts += "      "+paint1(x)+"      "+paint1(y)+"      "+paint1(z)+"\n";
        dicts += "      "+paint2(x)+"      "+paint2(y)+"      "+paint2(z)+"\n";
        dicts += "      "+paint3(x)+"      "+paint3(y)+"      "+paint3(z)+"\n";
        dicts += "      "+dict[6]+"      "+dict[6]+"      "+dict[6]+"\n\n";
        return dicts;
}

