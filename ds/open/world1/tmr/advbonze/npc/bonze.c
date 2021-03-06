//凌雲寺 進階 Master -By Tmr 2002/1/24-

#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name("妙見金身",({"miao-jian bonze","bonze","miao-jian"}));
        set("gender", "男性");
        set("long",@LONG
妙見高僧為凌雲寺前任住持，畢生鑽研佛道，慧根深厚，中年時期因緣際會
習得佛門中第一絕技「如來九式」，自此佛、武二道互輔互長，修為幾以達
到「虹化」的境界。然而，你現在見到的是妙見修道成佛而留在人間的金身
，也是如來佛試驗的考驗官之一。
LONG
        );
        set("level",40);
        set("age",80);
        set("title","護法使者");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
		set_skill("jingang-finger",100);
        map_skill("unarmed","jingang-finger");
	    set("attitude", "aggressive");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
					(:do_heal:), 
					(:do_heal:), 
		}) );        

		setup();
		carry_object(__DIR__"eq/armor")->wear();
		carry_object(__DIR__"eq/cloth")->wear();
		carry_object(__DIR__"eq/helmet")->wear();
		carry_object(__DIR__"eq/boots")->wear();
		carry_object(__DIR__"eq/hands")->wear();
        set_living_name("buddha-war-jingang");
}

// 戰鬥中療傷
void do_heal()
{
	object me=this_object();
	if(me->query("hp") < me->query("max_hp")/2)
	{
		message_vision(HIG "$N使出金剛伏魔指中的「雨天曼陀羅華」，左手小指迅速點住了身上的各個止血的穴道。\n" NOR,me);
		me->heal("hp",100);
		me->add_busy(1);
	} else {
		if(me->is_busy() ) return;
		if(me->query_temp("do_attack") ) return;
		message_vision(HIR "$N手中結了個「怒意金剛」佛印，登時攻勢劇增！！\n" NOR,me);
		me->set_temp("do_attack",1);	// mark 避免多次攻擊
		me->add_temp("apply/damage",50);
		me->add_temp("apply/hit",300);
			me->attack();
			me->attack();
		me->add_temp("apply/hit",-300);
		me->add_temp("apply/damage",-50);
		me->set_temp("do_attack",0);
	}

}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

		if(random(100)<30)
		{
			damage/=2;
			message_vision(HIY "$N渾厚堅實的護體金身化解了大半傷害。\n" NOR,this_object());

		}

		if(objectp(who) )
			::receive_damage(type,damage,who);
		else
			::receive_damage(type,damage,who);
		return damage;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        ob->add("popularity",2);
        ::die();

        return;
}
