#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����|�Q�ŤK����", ({"bagiman","man1"}) );
        set("long", "�A�i�H���L�ݬ�....���Z�@����\n");
        set("title",HIW"�����˳�"NOR);
        set("race", "�H��");
        set("age", 50);
        set("level", 40);

        set("str",70);
        set("dex",40);
        set("con",64);
        set("int",25); 
        set("combat_exp",10000);
        set("chat_chance",20);
        set("chat_msg",({
         (:command("say �ڻ��O�޽c��...�A�{�b�b�Q����??"):),
         (:command("say ��...�u�L��..."):),
         (:command("exert bagi_fist"):),
         (:command("exert bagi_fist"):),
        }) );

      set_skill("unarmed",100);
      set_skill("combat",100);
      set_skill("bagi_fist",100);
      set_skill("horse-steps",100);
      set_skill("bagi_force",100);
      set_skill("force",100);
      set_skill("dodge",70);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
                (:command("exert bagi_force power_up"):),
         }) );

      setup();

      carry_object("/open/world1/eq/bc_cloak")->wear();
      carry_object("/open/world1/eq/bs_hands")->wear();
      carry_object("/open/world1/eq/bt_neck")->wear();
      carry_object("/open/world1/eq/gs_waist")->wear();
      carry_object("/open/world1/eq/mb_wing")->wear();
      carry_object("/open/world1/eq/mf_armor")->wear();
      carry_object("/open/world1/eq/sl_mask")->wear();
      carry_object("/open/world1/tmr/ghost-forest/npc/eq/randombite-finger")->wear();
      carry_object("/open/world1/tmr/ghost-forest/npc/eq/gold_helmet")->wear();
      carry_object("/open/world1/wilfred/sand/npc/eq/eq7")->wear();
      carry_object("/open/world1/wilfred/sand/npc/eq/eq9")->wear();
      carry_object("/open/world1/eq/water_boots")->wear();
      carry_object("/open/world1/eq/viper_cloth")->wear();
      carry_object("/open/world1/tmr/area/npc/wp/dab-aqua-claw2")->wield();


}
int talk_action()
{
command("know ");
command("emote �S�X�F�L�`�������C");
command("say �ѤѮ����A���ɯu���Q���F�C");
command("say �u���A�s�@�I�֧Q�]�S��...");
command("stare");
command("shrug");
command("sigh");
command("say �o�N�O�ڪ��J�R�a...");
return 1;
}

