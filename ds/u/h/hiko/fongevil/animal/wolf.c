inherit NPC;

void create()
{
  set_name("���T", ({"wolf"}) );
  set("long",@LONG
�Q���������T�ءA�|�D�ʧ����H���A�ʦn�W��A�դѷ|����X�~�V���C
LONG
);
  set("attitude", "aggressive");
  set("race", "beast");
  set("unit","��");
  set("age",5);
  set("level",22);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",100);
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

