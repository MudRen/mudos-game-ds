#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "����", ({ "tao chung","tao","chung"}));
set("long",
"�o�O�@�Ӥw�g�h�����򪺦���ǤH, �ڻ��L�����쳺�M�O��\n"
"�@�Ӥp�c! �p���L�]�h����ѱ������h�ӨӹL�L�L�~�L�{��\n"
"�s��ͬ��C\n",
);

        set("level",22);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 56);
        set("evil",-20);
        set_skill("unarmed",70);  
        set_skill("parry",50); 
        set_skill("dodge",40);       
   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("sell_list",([   
           __DIR__"item/bag"    : 25, //��ܨC�R�@�ӳU�l�|��15�I�ɵ��I��
           __DIR__"item/dump"   : 10, //���D���S��z�ѧ_�h���i�]��0 (�L���q����)
           __DIR__"item/pill1"  :30,  
      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       
"�������G�֦b�s�椤....!\n",
(:command("smile"):),
}) );

set("inquiry/name", @LONG
   �ڥs��������.. 
LONG );

      setup();
      add_money("dollar", 400);       
      carry_object(__DIR__"obj/pill1");
      carry_object(__DIR__"eq/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
