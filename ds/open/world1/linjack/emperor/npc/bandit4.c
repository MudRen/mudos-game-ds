inherit NPC;
void create()
{
        set_name("�D�j�s",({ "fat bandit","bandit" }));
        set("long",
                "�o�å�ݰ_�Ӥ@�Ƥ��ڤڪ��ˤl, �@�ݴN���D���O�n�f,\n"
                "���L�L�{�b�����D�b�䤰��, ���G�L����A���s�b�C\n"
        );
        set("age",35+random(6));
	set("attitude", "peaceful");
        set("level",20+random(6));
	set("battlepoint",2);
        set("guild_gifts",({ 7,6,3,4 }));
	set("evil",5+random(6));
        set("chat_chance",5);
        set("chat_msg",({
  "�D�j�s���b�a�W��Ǥ���, ���L���򳣨S���C\n",
  "�D�j�s��: �x! �_��(key)��򤣨��F..?\n",
  "�D�j�s���b�|�B�i���, �����D�b�ݨǤ���C\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "�D�j�s��: �S�̭�! �W!\n",
  (: command("say �ǩR�� ~~~ ! \n") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/cutless")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        add_money("silver",4);
}

int talk_action(object me)     
{
  object room;
  int a;
  a = random(6) + 1;
  if( !this_object()->query("talked") && !find_object("/open/world1/linjack/emperor/npc/obj/greenkey") ) {
     room = load_object("/open/world1/linjack/emperor/forest"+a+".c");
     command("emote �n���L���A���s�b, �u���y: �����ڧ��_��(key)! ���@�w���b�K�L���Y�B�F..!");
room -> set("item_desc",(["�ݰ_�өǩǪ����":"�o��襤�����@���_��(key)!�֧⥦��(pick)�_�ӧa!
\n"]));
     room -> set("active_action",1);
     this_object()->set("talked",1);
     return 1;
  }
  else command("emote ���G�S�z�A..");
  return 0;
}

int accept_object(object me, object ob)
{
        object tob, herb,a;

        if( ob->query("id")!="grass green key" ) return 0;
        else {
                command("say ��..�_��! �x? �A�O��! �A�o�å�! �ݤM!"); 
                command("kill "+me->query("id"));
        }
        return 1;
}
