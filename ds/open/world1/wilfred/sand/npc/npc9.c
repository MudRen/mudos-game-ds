inherit NPC;

void create()
{
  set_name("��", ({"bear"}) );
  set("long",@LONG
�Q�����j�����A�g�`�X�S�b�s�ϰ줧���A�ӥB�D�`������ʡC
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",4);
  set("level",24);
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  carry_object(__DIR__"eq/eq7")->wear();
}
