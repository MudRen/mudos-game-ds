#include <ansi.h>
inherit NPC;
void create()
{
	set_name("���Ӥ�",({"mr.s yip","mr.s","yip"}) );
	set("long",@LONG
���Ӥӭ�ӬO�@�ӤQ���}�Ԫ��H�A���L�۱q�e�X�~�����͹L�@����
�N�ܪ��ܨH�q�C
LONG);
	set("age",41);
	set("title","���s���");
	set("level",12);
	set("race","human");
	set("gender","�k��");
	set("evil",-5);
	set("talk_reply","ť�����H�b����n�䪺��W�ݹL�@�����⪺�ǳ��C");
	set("chat_chance",8); 
        set("chat_msg",({
                (:command("sigh"):),
                (:command("sob"):),
        }) );
        set("inquiry", ([
        "�¼v" : "�ڰl���Ӷ¼v�l�줽�餧��N�S�ݨ�F�C\n",
        "����" : "�N�O���������..������n�B�C\n",
        "�����~" : "���O�ڥ��ͦb���B�Q�G�g�~������ɰe���ڪ��@�T�٫��C\n",
        ]));
	setup();
	carry_object(__DIR__"../eq/cloth_boots_5")->wear();
	carry_object(__DIR__"../eq/cloth_skirt_6")->wear();
	carry_object(__DIR__"../eq/cloth_robe_12")->wear();
	add_money("dollar",230);
}

void reset_quest()
{
	object ring,mob;
	if(mob=this_object()->query_temp("black_cat"))
	{
		message_vision("$N�@���ਭ��M�]�����F�C\n",mob);
		destruct(mob);
	}
	if(ring=this_object()->query("ring"))
	{
		message_vision("$N��M�����F�C\n",ring);
		ring->unequip();
		destruct(ring);
	}
	ring = new_ob(__DIR__"../eq/yip_wed_ring.c");
	mob = new_ob(__DIR__"../npc/beast_cat_4.c");
	ring->move(mob);
	mob->move("/open/world2/lichi_town_1/map_17_2");
	this_object()->set_temp("black_cat",mob);
	this_object()->set("ring",ring);
}

int talk_action(object me)
{
 object book,ring;
 if(!book=me->query_temp("notebook")) return 0;
 if(this_object()->query("have_ring"))
 {
 	command("say �٫��ש�S�^��ڪ�����F�C");
 	command("giggle");
 	return 1;
 }
 if(!book->query_step("LostRing") || random(2))
 {
  command("sob");
  command("say �ڤV�үd���ڪ������~�e�X�ѱߤW�Q�@�Ӷ¼v�������F�C");
  command("cry");
  book->add_quests_note("LostRing","���ӤӪ����ì����~�Q�@�Ӷ¼v�����F�C");
  if(ring=this_object()->query("ring"))
  {
  	if(!environment(ring)) reset_quest();
  } 
  else 
  {
  	reset_quest();
  }
  return 1;
 }
 return 0;
}

int accept_object(object who, object ob)
{
 int exp;
 object book;
 if(book=who->query_temp("notebook"))
 {
   if(this_object()->query("have_ring"))
   {
   	command("say �ڪ��_���٫��w�g���^�ӤF�C");
   	command("say ��L���F���ڦӨ����S�ΡC");
   	return notify_fail("\n");
   }
   if(ob->id("yip_wedding_ring"))
   {
   	if(!book->query_step("LostRing")) //�Ĥ@������
   	{
   		exp=7000+random(3000);
     		book->add_quests_note("LostRing","�N���^���٫����ٵ����ӤӡC[���ȧ���]");
     		who->add("exp",exp);
		who->add("popularity",1);
     		book->set_quests("LostRing",1);
     		set("chat_msg",({
                (:command("smile"):),
                (:command("ccc"):),
        	}) );
        	this_object()->set("have_ring",1);
    		call_out("delay_messages",1,who,exp,1);
    		return 1;
   	}
   	else
   	{
   		set("chat_msg",({
                (:command("smile"):),
                (:command("ccc"):),
        	}) );
        	this_object()->set("have_ring",1);
                who->add("exp",300);
   		call_out("delay_messages",1,who,300,0);
    		return 1;
   	}
   } else if(ob->id("ring"))
   {
   	message_vision("$N���F���ӤӤ@�u$n�C\n���ӤӮ��_$n�ݤF�@�U...\n",who,ob);
   	command("say �o�ä��O�ڪ��٫��C");
   	message_vision("���ӤӱN$n�ٵ�$N�C\n",who,ob);
   	return notify_fail("...\n");
   }
 }
 return notify_fail("\n");
}

void delay_messages(object ppl,int exp,int pub)
{
	object axe; 
	string str="";
	if(!ppl) return;
	if(this_object()->query("send_axe")) return;
	command("say �u�O�D�`���§A���ڧ�^�F�٫��C");
	command("wear ring");
	command("thank "+ppl->query("id"));
	str=sprintf("�A�o��F%d�I�g���",exp);
	if(pub) str+=sprintf("�A�n��]���ɤF�C\n");
	else {
		str+="�A�P500���S�ҡC\n";
		ppl->receive_money(500);
	}
	tell_object(ppl,str);
	if(axe = new_ob(__DIR__"../wp/stone_axe_18.c"))
	{
		command("say �o�O���үd�U���۩�A�p�G�z�����󪺸ܴN���h�a�C");
		axe->move(environment(this_object()));
		message_vision("$N�q�d�l�خ��X�@��$n�A�ñN$n��b�a�W�C\n",this_object(),axe);
		this_object()->set("send_axe",1);
	}
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("���a(%s)�F������[�򥢪��^��]..EXP: %d Pub: %d\n",ppl->name_id(1),exp,pub));
	return;
}

void reset()
{
	object ring;
	set("chat_msg",({
                (:command("sigh"):),
                (:command("sob"):),
        }) );
        this_object()->delete("have_ring");
        if(ring = present("yip_wedding_ring",this_object()) )
        {
        	ring->unequip();
        	destruct(ring);
        }
        this_object()->delete("ring");
        this_object()->delete("send_axe");
	reset_quest();
}

void die()
{
	object ring;
	if(ring=this_object()->query("ring"))
	{
		message_vision("$N��M�����F�C\n",ring);
		ring->unequip();
		destruct(ring);
	}
	::die();
}
