#include <ansi.h>
inherit NPC;
void create()
{
       set_name("��^",({"pan-en","pan","en"}));
       set("long",
           "    �A�ݨ�@�쨭����G���~�l�A�ӲӪ��ܦt�U�O�@���L���������A�n�����h�F\n"
           "�Ҧ����Ʊ�A���O�L�����l�o�S�n���u�@�ۤ���F��@�ˡA��ݤ��i�ʷn�C�L��\n"
           "�W�y�W�G���F�˲��A���ӥi���ٺ�M�q���y�{�b�ܪ��L�L���Ǥ�������C���L�L\n"
           "�n���S�ݨ�A�@�ˡA�ʤ]���ʪ���ۧA���᪺����C\n"
        );
       set("nickname",HIB"�P�e�}��"NOR);
       set("gender","�k��");
       set("age", 37);
       set("level", 37);
      set("adv_class",2);    
      set("class1","�K�P��"); 
     set("class2","�_��");
      create_family( MAG "�K�P��" NOR ,21,"�Z�Ǳ��Y");

   set("guild_skills",([  
             "dagger":({130,2,100}),   
             "unarmed":({190,2,70}),
             "parry":({150,2,90}),  
        ]) );

   set("guild_gifts",({-2,-2,7,17}));

        set("chat_chance",3);
        set("chat_msg",({
                                   (:command, "close door"
:)}));

       set("attitude", "peaceful");
       set("talk_reply","�^�h�C"); 

        setup();
        add_money("coin", 100);
        carry_object( __DIR__"eq/sky-walk_b")->wear();
        carry_object(  __DIR__"wp/stonedragon_d")->wield();
        carry_object( __DIR__"eq/stars_c")->wear();           
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}