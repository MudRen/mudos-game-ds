inherit NPC;

void create()
{
  set_name("�º�", ({"black bear","bear"}) );
  set("long",@LONG
�b�`�s�~��w�[�����A���Ķ¦�A�����Q�����j�A�ݨӫܥͮ�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",100);
  set("level",30);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
}

void init()
{
        ::init();

if(userp(this_player() ) && this_object()->visible(this_player()))
        {
   message_vision("$N��q�@�n�A�}�l����$n�I�I\n",this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
}


