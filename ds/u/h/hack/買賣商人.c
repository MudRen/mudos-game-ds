// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�L����", ({ "boss lin","lin","boss"}));
        set("long", "�@�ӭD�D�����~�k�H�M�ǬN����ۧA���ۡC\n\n"
        	    +"  �ݦs�f�Х� <list> <list wp> <list eq>\n"
        	    +"  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n"
        	    +"  �n��F��� <sell ���~> <sell all> <sell �ƶq ���~>\n\n"
        );
        set("level",20);
        set("title","[1;32m�ӤH[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
       
        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",20);			//���c�� 20 (�������c, �t���})

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�n��.. �h���Ф@�ǪB�ͨӶR�F��a!!");
   set("storeroom","/u/l/luky/shop");	//�`�N. �n�إߤ@��room��F��(�Ѧ�/u/l/luky/shop.c)

  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�L���󯺯�����: �p�S��, �n���n�R�I�F���? �ڥi�H��A�K�y�@�I��..\n",
(:command("smile"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���L�ǧJ.. �Цh����!![m
LONG );

        setup();

      add_money("coin", 120);		//�a����
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_sell","sell");
}

int accept_object(object who, object ob) //�������~��
{
        int val;

        val = ob->value();
        if( !val ) //���O��
        {
		command("say "+who->name()+", �A�i�H��sell�浹��");       
                return notify_fail("�L���n�N���H�K���O�H���F��C\n");
        }
        else
        {
		command("say "+who->name()+", �L�\�����S, �A�i�H��list�ݬݧA�Q�R(buy)����..");       
                return notify_fail("�L���n�N���H�K���O�H�����C\n");
        }

}

/* /u/l/luky/shop.c ���e�p�U


inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","�L���󪺭ܮw");
set("long","\n");
set("light",1);
set("no_clean_up",1);
set("objects",([
 "/u/l/luky/npc/item/bag":1,
 "/u/l/luky/npc/eq/blackjacket":3,
 "/u/l/luky/npc/wp/kaisan_b":1,
 ]));
set("exits", ([	//�X�f�]��NPC��m,�i�H���]
"out":"/open/world2/anfernee/start/bug",
]));
setup();
}



*/