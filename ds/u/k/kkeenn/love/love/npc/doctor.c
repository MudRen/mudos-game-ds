inherit NPC;
#include <ansi.h>
inherit SELLMAN;
void create()
{
        set_name("�q�����",({ "si-ma doctor","doctor" }));
        set("long",
"    �o�O�c�H�����į�c�q���Ϫ��k��A�]���Y�ǭ�]���o�@�N�ӱ�����\n"
"�����c����ġI�A�i�H�V�o�߰ݩ|�L�s�f(list),�ʶR(buy)����v(heal)\n"
"[P.S ��v(heal + coin) �I�����ĶO�V�h, �ɪ��]�V�h^.^]\n"
        );
        set("age",15+random(10));
        set("no_fight",1);
     set("gender","�k��");
        set("nickname",HIC"�@�N�W��"NOR);
        set("chat_chance", 3);
        set("chat_msg", ({
  "�q����륿�b�M�I�d�l�����į�C\n",
}) );
        set("sell_list",([
"/open/world1/acme/area/npc/obj/god_pill" : 15,
"/open/world1/acme/area/npc/obj/head_pill" : 20,
"/open/world1/acme/area/npc/obj/hand_pill" : 20,
"/open/world1/acme/area/npc/obj/body_pill" : 20,
"/open/world1/acme/area/npc/obj/foot_pill" : 20,
"/open/world1/cominging/area/npc/obj/pdragon-herb.c": 12,
"/open/world1/cominging/area/npc/obj/big-pill.c": 15,
"/open/world1/cominging/area/npc/obj/tp_candy.c": 20,
"/open/world1/cominging/area/npc/obj/appill.c": 20,
]));
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_heal","heal");
}
int do_heal(string arg)
{
        int i;
        object me,ob,coin;
        me=this_player();
        ob=this_object();
        if(!arg ) 
                return notify_fail("�A�n���ۤv�X�h�����ĶO�O�H\n");
        if(sscanf(arg,"%d",i)!=1 ) 
                return notify_fail("�A�n���ۤv�X�h�����ĶO�O�H\n");
	if( ob->is_busy() ) 
		return notify_fail(ob->query("name")+"�����ۡA�S�Ųz�A�C\n"); // add busy settings by -alick
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S���ťI���ĶO�C\n");
        if(me->is_fighting() )
                return notify_fail("�A�����ۡA�S���ťI���ĶO�C\n");
       if(!objectp(coin=present("coin",me) ) )
            return notify_fail("�A���W�S�����C�C\n");
     if(i > coin->query_amount() )
         return notify_fail("�A���W���������C�C\n");
if(i < 100 ) return notify_fail("�A�����ĶO�����h�ڡC\n");
        message_vision("$N�I�F"+(string)(i)+"�����ĶO��$n\n",me,ob);
         command("smile");
         command("thank "+ me->query("id") );
         me->receive_money(-i);
        command("say �o��B�ͤⵧ�i�u����A���h�Q�ڨӬ��A�վi���ߡA����鰷�C");
 message_vision(HIW"\n$N�⤤�����@�{�A�E�E�K�Q�@�����w�ֳt����b$n���W�I�I\n"HIR"$n�u�z�v�a�@�n�R�F�X�f�¦�C\n\n"NOR ,ob,me);
   me->receive_heal("hp",i/2);
   me->receive_heal("mp",i/3);
   me->receive_heal("ap",i/3);
	ob->start_busy(2);
	me->start_busy(2);
        return 1;
}

