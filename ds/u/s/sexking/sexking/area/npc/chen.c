#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
set_name( "�p���`��", ({ "shu chen","shu","chen"}));
        set("long", @TEXT
�L�O�@��ݰ_�ӬܲM�بq�����~�H�A���O�@����H�C�ȡA�~���ɦb�@
���ԧФ��Q�Ĥ�G�Q�W���ⰽŧ�妨�F���ˡA�@�𤧤U�ƨg�������L
�̥������H�A���]���t�˹L������L�h�ӥ\�O�j�h�p���w�h������q
�Ƴc��C
TEXT    );
        set("level",50);
        set("title","�ӤH");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 43);
        set("str",70);                  
        set("dex",50);                
        set("con",90);                  
        set("int",90);               
        set("combat_exp",8000);         
        set("evil",-20);                 
        set_skill("blade",90);         
        set_skill("parry",90);          
        set_skill("dodge",70);  
        set_skill("perception",25);  
        set("sell_list",([
                __DIR__"obj/sous" : 9,
                __DIR__"obj/wine" : 10,
                __DIR__"obj/noodles" :15,
                __DIR__"obj/boil" :15,
        ]) );     
        set("attitude", "peaceful");  
        set("talk_reply","���N�h�R�Ǥ饻���F��^�h�~���a.....");
        set("storeroom",__DIR__"japen_shop"); 

  set("chat_chance", 3 ); 
  set("chat_msg", ({      
"�p���`���Ĥf��:�H�٬O�L�o���R�I�n.. ..\n",
(:command("smile"):),
(:command("tender"):),
}) );
set("inquiry/name", @LONG
   �ڥs���p���`��.. �Цh����!!
LONG );

        setup();

      
      carry_object(__DIR__"wp/japen_blade")->wield();
      }

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}

