// Npc: /u/s/suez/npc/3.c

inherit NPC;

void create()
{
 set_name("���i", ({"bi co bonze","bonze"}) );
	set("long", "�L�O�ⶳ�x�̭t�d�֮�P��󪺹��H�C\n");
	set("race", "�H��");
	set("age", 25);
	set("level", 12);
   set("chat_chance",9);
   set("chat_msg",({(:command, "sweat":),
                    (:command, "smile":),
                    (:command, "say �U���Ҧ���,�ɵM�C�j��....":),
                    (:command, "say �o�Ǫ��ݨӱo�h���I���F...":),
}));
     set("chat_chance_combat",17);
     set("chat_msg_combat", ({
      (:command("fear"+this_player()->query("id")):),
     "���i�`�Ȫ����D:�u�o��I�D�O�A�����p���F........�v\n"
     }) );



	setup();

          carry_object(__DIR__"wp/shovel.c")->wield();
}
