inherit NPC;
void create()
{
        set_name("�����N",({ "watermoon","�����N" }));

 set("long", @LONG

    �b�p���������Hı�o���G�z���T���A���o����o�䷡���i�������A�A
�M�Ө���R�������o�y�S�X��w�������A�ϩ��S������Ʊ���v�T�o���M
�w�C�b�o�����W���H�Pı���X����s�T����^�A�o�`�O�N�Ҧ��d�˪��Ʊ�
�����b�ۤv���ߪ��`�B�A���o�]�]����R�Q�o�]�L�k���J�o�����ߦӲ`�`
���۳d�ۡC

LONG
        );
        set("gender", "�k��" );
        set("level", 80);
        set("age",16);
        set_temp("class_wind/power",300);

map_skill("sword","star-sword");
set("chat_chance", 8);
set("chat_chance_combat", 8);
set("chat_msg",({
  (: command("say �b�A���n���}�ڤ��e�A�ڷ|�@���R�ۧA���C") :),
(:command("sigh") :),
  (: command("say ����A�`�O���۫H�ڪ��u�ߩO......") :),
(:command("stare") :),

}));
set("chat_msg_combat", ({
  (: command("say �K, �Q��ڤ��W�x�A�A�٦��O.....") :),
  (: command("exert fogseven shadow") :),
  (: command("exert moon_force recover") :),
  (: command("exert star-sword penuma-sword") :),
  (: command("exert moon_force long-arc") :),
  (: command("exert star-sword tian") :),
  (: command("exert star-sword nine") :),
}));
      set_skill("unarmed",100);
        set_skill("sword",100);
        set_skill("force",100);
        set_skill("fogseven",100);
        set_skill("moon_force",100);
         set_skill("sorgi_sword",100);
        set_skill("star-sword",100);

        setup();
}

